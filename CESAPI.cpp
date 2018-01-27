#define WIN32_LEAN_AND_MEAN

#include "CESAPI.hpp"

#include <iostream>
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>

#include <chrono>
#include<exception>
#include <string>
#include <thread>

// Need to link with Ws2_32.lib, Mswsock.lib, and Advapi32.lib
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

#define DEFAULT_ADDRESS "192.168.0.1"
#define DEFAULT_PORT 700

namespace CESAPI {

  /*** Connection Class Member Definitions ***/
  void Connection::SendPacket(void const * const packet) const {
    PacketHeaderT const * const header = reinterpret_cast<PacketHeaderT const * const>(_receive_buffer);
    const long packetSize = header->lPacketSize;

    const char * packet_ptr = static_cast<char const *>(packet);
    int iResult = send(_socket, packet_ptr, packetSize, 0);
    if (iResult == SOCKET_ERROR) {
      throw ConnectionException(std::string("send failed with error: ") + std::to_string(WSAGetLastError()));
    }
  }

  void const * Connection::ReceivePacket() const {
    uint16_t bytesRequested = sizeof(PacketHeaderT);
    uint16_t bytesReceived = 0;

    int iResult = recv(_socket, _receive_buffer, bytesRequested, 0);
    while (iResult > 0 && bytesReceived < bytesRequested) {
      iResult = recv(_socket, (_receive_buffer + bytesReceived), (bytesRequested - bytesReceived), 0);
      if (iResult == 0) {
        Disconnect();
        throw ConnectionException(std::string("Socket was closed."));
      }
      else if (iResult < 0) {
        throw ConnectionException(std::string("Socket error: ") + std::to_string(iResult));
      }
      bytesReceived += iResult;
    }

    PacketHeaderT const * const header = reinterpret_cast<PacketHeaderT const * const>(_receive_buffer);
    bytesRequested = header->lPacketSize;

    while (iResult > 0 && bytesReceived < bytesRequested) {
      iResult = recv(_socket, (_receive_buffer + bytesReceived), (bytesRequested - bytesReceived), 0);
      if (iResult == 0) {
        Disconnect();
        throw ConnectionException(std::string("Socket was closed."));
      }
      else if (iResult < 0) {
        throw ConnectionException(std::string("Socket error: ") + std::to_string(iResult));
      }
      bytesReceived += iResult;
    }

    return _receive_buffer;
  }

  Connection::Connection() :_socket(INVALID_SOCKET), _commandAsync(NULL), _commandSync(NULL) {
    _commandAsync = new CommandAsync(this);
    _commandSync = new CommandSync(_commandAsync);
  }

  Connection::~Connection() {
    delete _commandSync;

    _commandAsync->StopReceiving();
    delete _commandAsync;

    Disconnect();
  }

  void Connection::Connect() const {
    Connect(DEFAULT_ADDRESS, DEFAULT_PORT);
  }

  void Connection::Connect(const std::string address, const uint16_t port) const {
    std::cout << "Connecting to host " << address << " at port " << port << "..." << std::endl;
    WSADATA wsaData;
    _socket = INVALID_SOCKET;
    struct addrinfo *result = NULL,
      *ptr = NULL,
      hints;
    int iResult;

    // Initialize Winsock
    std::cout << "Initialize Winsock" << std::endl;
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
      throw ConnectionException(std::string("WSAStartup failed with error: ") + std::to_string(iResult));
    }

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    // Resolve the server address and port
    std::cout << "Resolve the server address and port" << std::endl;
    iResult = getaddrinfo(address.c_str(), std::to_string(port).c_str(), &hints, &result);
    if (iResult != 0) {
      WSACleanup();
      throw ConnectionException(std::string("getaddrinfo failed with error: ") + std::to_string(iResult));
    }

    // Attempt to connect to an address until one succeeds
    std::cout << "Attempt to connect to an address until one succeeds" << std::endl;
    for (ptr = result; ptr != NULL; ptr = ptr->ai_next) {

      // Create a SOCKET for connecting to server
      std::cout << "Create a SOCKET for connecting to server" << std::endl;
      _socket = socket(ptr->ai_family, ptr->ai_socktype,
        ptr->ai_protocol);
      if (_socket == INVALID_SOCKET) {
        WSACleanup();
        throw ConnectionException(std::string("socket failed with error: ") + std::to_string(WSAGetLastError()));
      }

      // Connect to server.
      std::cout << "Connect to server" << std::endl;
      iResult = connect(_socket, ptr->ai_addr, (int)ptr->ai_addrlen);
      if (iResult == SOCKET_ERROR) {
        closesocket(_socket);
        _socket = INVALID_SOCKET;
        continue;
      }
      break;
    }

    freeaddrinfo(result);

    if (_socket == INVALID_SOCKET) {
      WSACleanup();
      throw ConnectionException(std::string("getaddrinfo failed with error: ") + std::to_string(iResult));
    }

    _commandAsync->StartReceiving();
  }


  void Connection::Disconnect() const {
    if (_socket != INVALID_SOCKET) {
      closesocket(_socket);
      WSACleanup();
      _socket = INVALID_SOCKET;
    }
  }


  /*** CommandAsync Class Member Definitions ***/

  bool CommandAsync::SendPacket(void const * const PacketStart, const long PacketSize) const {
    _connection->SendPacket(PacketStart);
    return true;
  }

  void CommandAsync::StartReceiving() const {}
  void CommandAsync::StopReceiving() const {}

  void CommandAsync::NotifyReceivers(void const * const packet, long packetSize) {
    std::list<CESAPIReceive *>::const_iterator receiver;
    for (receiver = _receivers.begin(); receiver != _receivers.end(); ++receiver) {
      (*receiver)->ReceiveData(packet, packetSize);
    }
  }

  void CommandAsync::RegisterReceiver(CESAPIReceive * receiver) {
    UnregisterReceiver(receiver);  // just in case
    _receivers.push_back(receiver);
  }

  void CommandAsync::UnregisterReceiver(CESAPIReceive * receiver) {
    _receivers.remove(receiver);
  }

  /*** CommandSync Class Member Definitions ***/

  bool CommandSync::SendPacket(void const * const PacketStart, const long PacketSize) const {
    _commandAsync->SendPacket(PacketStart, PacketSize);
    return true;
  }

  void CommandSync::StartMonitoringCommand(const ES_Command targetCommand) {
    while (!_monitoring.isEnabled()) {
      _monitoring.enable(targetCommand);
      std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
  }

  void CommandSync::WaitWhileMonitoring() {
    while (_monitoring) {
      std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
  }

  void CommandSync::StopMonitoringIfCommand(const ES_Command targetCommand) {
    while (_monitoring.isEnabled()) {
      _monitoring.disable();
      std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
  }

  void CommandSync::OnInitializeAnswer() {
    StopMonitoringIfTargetCommand(ES_DT_Command, ES_C_Initialize);
  }

  InitializeRT const * CommandSync::Initialize() {
    StartMonitoring(ES_DT_Command, ES_C_Initialize);
    _commandAsync->Initialize();
    WaitWhileMonitoring();
    return reinterpret_cast<InitializeRT const *>(_packet);
  }

}  // namespace CESAPI