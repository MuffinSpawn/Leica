#define WIN32_LEAN_AND_MEAN

#include "CESAPI.hpp"

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>

#include <chrono>
#include <cstring>
#include <exception>
#include <string>
#include <thread>

// Need to link with Ws2_32.lib, Mswsock.lib, and Advapi32.lib
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

#define DEFAULT_ADDRESS "192.168.0.1"
#define DEFAULT_PORT 700


Message::Message(void const * const packet) {
    PacketHeaderT const * const header = reinterpret_cast<PacketHeaderT const * const>(packet);
    packet_ = new char[header.lPacketSize];
    std::memcpy(packet_, packet, header.lPacketSize);
}

Message::~Message() {
    delete[] packet_;
}

template<typename T>
T Message::packet() {
    T test;
    char const * type_name = typeid(test).name();
    if (std::strcmp(type_name, "PacketHeaderT") != 0 &&
        std::strcmp(type_name, "ReturnDataT") != 0 &&
        std::strcmp(type_name, "BasicCommandRT") != 0 &&
        std::strcmp(type_name, "NivelResultT") != 0 &&
        std::strcmp(type_name, "ReflectorPosResultT") != 0 &&
        std::strcmp(type_name, "SingleMeasResultT") != 0 &&
        std::strcmp(type_name, "SingleMeasResult2T") != 0 &&
        std::strcmp(type_name, "SystemStatusChangeT") != 0 &&
        std::strcmp(type_name, "ErrorResponseT") != 0 &&
        std::strcmp(type_name, "InitializeRT") != 0 &&
        std::strcmp(type_name, "ActivateCameraViewRT") != 0 &&
        std::strcmp(type_name, "ParkRT") != 0 &&
        std::strcmp(type_name, "GoBirdBathRT") != 0 &&
        std::strcmp(type_name, "GoBirdBath2RT") != 0 &&
        std::strcmp(type_name, "ChangeFaceRT") != 0 &&
        std::strcmp(type_name, "StartNivelMeasurementRT") != 0 &&
        std::strcmp(type_name, "StartMeasurementRT") != 0 &&
        std::strcmp(type_name, "StopMeasurementRT") != 0 &&
        std::strcmp(type_name, "ExitApplicationRT") != 0 &&
        std::strcmp(type_name, "GoLastMeasuredPointRT") != 0 &&
        std::strcmp(type_name, "FindReflectorRT") != 0 &&
        std::strcmp(type_name, "SetCoordinateSystemTypeRT") != 0 &&
        std::strcmp(type_name, "GetCoordinateSystemTypeRT") != 0 &&
        std::strcmp(type_name, "SetMeasurementModeRT") != 0 &&
        std::strcmp(type_name, "GetMeasurementModeRT") != 0 &&
        std::strcmp(type_name, "SetSearchParamsRT") != 0 &&
        std::strcmp(type_name, "GetSearchParamsRT") != 0 &&
        std::strcmp(type_name, "SetStationaryModeParamsRT") != 0 &&
        std::strcmp(type_name, "GetStationaryModeParamsRT") != 0 &&
        std::strcmp(type_name, "SetSystemSettingsRT") != 0 &&
        std::strcmp(type_name, "GetSystemSettingsRT") != 0 &&
        std::strcmp(type_name, "SetUnitsRT") != 0 &&
        std::strcmp(type_name, "GetUnitsRT") != 0 &&
        std::strcmp(type_name, "GetSystemStatusRT") != 0 &&
        std::strcmp(type_name, "GetMeasurementStatusInfoRT") != 0 &&
        std::strcmp(type_name, "GetTrackerStatusRT") != 0 &&
        std::strcmp(type_name, "SetReflectorRT") != 0 &&
        std::strcmp(type_name, "GetReflectorsRT") != 0 &&
        std::strcmp(type_name, "GetReflectorRT") != 0 &&
        std::strcmp(type_name, "SetEnvironmentParamsRT") != 0 &&
        std::strcmp(type_name, "GetEnvironmentParamsRT") != 0 &&
        std::strcmp(type_name, "SetRefractionParamsRT") != 0 &&
        std::strcmp(type_name, "GetRefractionParamsRT") != 0 &&
        std::strcmp(type_name, "SetStationOrientationParamsRT") != 0 &&
        std::strcmp(type_name, "GetStationOrientationParamsRT") != 0 &&
        std::strcmp(type_name, "SetTransformationParamsRT") != 0 &&
        std::strcmp(type_name, "GetTransformationParamsRT") != 0 &&
        std::strcmp(type_name, "GoPositionRT") != 0 &&
        std::strcmp(type_name, "GetDirectionRT") != 0 &&
        std::strcmp(type_name, "GoPositionHVDRT") != 0 &&
        std::strcmp(type_name, "PointLaserRT") != 0 &&
        std::strcmp(type_name, "PositionRelativeHVRT") != 0 &&
        std::strcmp(type_name, "PointLaserHVDRT") != 0 &&
        std::strcmp(type_name, "MoveHVRT") != 0 &&
        std::strcmp(type_name, "GoNivelPositionRT") != 0 &&
        std::strcmp(type_name, "CallOrientToGravityRT") != 0 &&
        std::strcmp(type_name, "SetCompensationRT") != 0 &&
        std::strcmp(type_name, "GetCompensationRT") != 0 &&
        std::strcmp(type_name, "GetCompensationsRT") != 0 &&
        std::strcmp(type_name, "GetCompensations2RT") != 0 &&
        std::strcmp(type_name, "SetStatisticModeRT") != 0 &&
        std::strcmp(type_name, "GetStatisticModeRT") != 0 &&
        std::strcmp(type_name, "SetCameraParamsRT") != 0 &&
        std::strcmp(type_name, "GetCameraParamsRT") != 0 &&
        std::strcmp(type_name, "GetADMInfo2RT") != 0 &&
        std::strcmp(type_name, "GetNivelInfoRT") != 0 &&
        std::strcmp(type_name, "GetNivelInfo2RT") != 0 &&
        std::strcmp(type_name, "GetTPInfoRT") != 0 &&
        std::strcmp(type_name, "GetTrackerInfoRT") != 0 &&
        std::strcmp(type_name, "GetATRInfoRT") != 0 &&
        std::strcmp(type_name, "SetLaserOnTimerRT") != 0 &&
        std::strcmp(type_name, "GetLaserOnTimerRT") != 0 &&
        std::strcmp(type_name, "GetFaceRT") != 0 &&
        std::strcmp(type_name, "SetLongSystemParamRT") != 0 &&
        std::strcmp(type_name, "GetLongSystemParamRT") != 0 &&
        std::strcmp(type_name, "GetObjectTemperatureRT") != 0 &&
        std::strcmp(type_name, "ClearCommandQueueRT") != 0 &&
        std::strcmp(type_name, "GetOverviewCameraInfoRT") != 0 &&
        std::strcmp(type_name, "GetDoubleSystemParamRT") != 0 &&
        std::strcmp(type_name, "SetDoubleSystemParamRT") != 0 &&
        std::strcmp(type_name, "RestoreStartupConditionsRT") != 0 &&
        std::strcmp(type_name, "GoAndMeasureRT") != 0 &&
        std::strcmp(type_name, "GetMeteoStationInfoRT") != 0 &&
        std::strcmp(type_name, "GetAT4xxInfoRT") != 0 &&
        std::strcmp(type_name, "GetSystemSoftwareVersionRT") != 0)
    {
        throw LTException("Invalid laser tracker packet type \"" + type_name + "\".");
    }
    return reinterpret_cast<T const *>(packet_); 
}

/*** Connection Class Member Definitions ***/
void Connection::SendPacket(void const * const packet) const {
  PacketHeaderT const * const header = reinterpret_cast<PacketHeaderT const * const>(_receive_buffer);
  const long packetSize = header->lPacketSize;

  const char * packet_ptr = static_cast<char const *>(packet);
  int iResult = send(_socket, packet_ptr, packetSize, 0);
  if (iResult == SOCKET_ERROR) {
    throw LTException(std::string("send failed with error: ") + std::to_string(WSAGetLastError()));
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
      throw LTException(std::string("Socket was closed."));
    } else if (iResult < 0) {
      throw LTException(std::string("Socket error: ") + std::to_string(iResult));
    }
    bytesReceived += iResult;
  }

  PacketHeaderT const * const header = reinterpret_cast<PacketHeaderT const * const>(_receive_buffer);
  bytesRequested = header->lPacketSize;

  while (iResult > 0 && bytesReceived < bytesRequested) {
    iResult = recv(_socket, (_receive_buffer + bytesReceived), (bytesRequested - bytesReceived), 0);
    if (iResult == 0) {
      Disconnect();
      throw LTException(std::string("Socket was closed."));
    }
    else if (iResult < 0) {
      throw LTException(std::string("Socket error: ") + std::to_string(iResult));
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
    WSADATA wsaData;
    _socket = INVALID_SOCKET;
    struct addrinfo *result = NULL,
                    *ptr = NULL,
                    hints;
    int iResult;

    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
    if (iResult != 0) {
        throw LTException(std::string("WSAStartup failed with error: ") + std::to_string(iResult));
    }

    ZeroMemory( &hints, sizeof(hints) );
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    // Resolve the server address and port
    iResult = getaddrinfo(address.c_str(), std::to_string(port).c_str(), &hints, &result);
    if ( iResult != 0 ) {
        WSACleanup();
        throw LTException(std::string("getaddrinfo failed with error: ") + std::to_string(iResult));
    }

    // Attempt to connect to an address until one succeeds
    for(ptr=result; ptr != NULL ;ptr=ptr->ai_next) {

        // Create a SOCKET for connecting to server
        _socket = socket(ptr->ai_family, ptr->ai_socktype, 
            ptr->ai_protocol);
        if (_socket == INVALID_SOCKET) {
            WSACleanup();
            throw LTException(std::string("socket failed with error: ") + std::to_string(WSAGetLastError()));
        }

        // Connect to server.
        iResult = connect( _socket, ptr->ai_addr, (int)ptr->ai_addrlen);
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
        throw LTException(std::string("getaddrinfo failed with error: ") + std::to_string(iResult));
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
    for (receiver=_receivers.begin(); receiver!=_receivers.end(); ++receiver) {
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

/*
bool CommandSync::ProcessData(void *pDataArrived, long lBytes) {
    _packet = pDataArrived;
}
*/

void CommandSync::StopMonitoringIfTarget(const ES_DataType targetType) {
    if (_targetType == targetType) {
        _monitoring = false;
    }
}

void CommandSync::StopMonitoringIfTargetCommand(const ES_DataType targetType, const ES_Command targetCommand) {
    if (_targetType == targetType && _targetCommand == targetCommand) {
        _monitoring = false;
    }
}

void CommandSync::OnInitializeAnswer() {
    StopMonitoringIfTargetCommand(ES_DT_Command, ES_C_Initialize);
}

void CommandSync::StartMonitoring(const ES_DataType targetType, const ES_Command targetCommand) {
    _targetType = targetType;
    _targetCommand = targetCommand;
    _monitoring = true;
}

void CommandSync::WaitWhileMonitoring() {
    while (_monitoring) {
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
}

InitializeRT const * CommandSync::Initialize() {
    StartMonitoring(ES_DT_Command, ES_C_Initialize);
    _commandAsync->Initialize();
    WaitWhileMonitoring();
    return reinterpret_cast<InitializeRT const *>(_packet);
}


/*
int __cdecl main(int argc, char **argv) 
{
    WSADATA wsaData;
    SOCKET _socket = INVALID_SOCKET;
    struct addrinfo *result = NULL,
                    *ptr = NULL,
                    hints;
    char *sendbuf = "this is a test";
    char recvbuf[DEFAULT_BUFLEN];
    int iResult;
    int recvbuflen = DEFAULT_BUFLEN;
    
    // Validate the parameters
    if (argc != 2) {
        printf("usage: %s server-name\n", argv[0]);
        return 1;
    }

    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
    if (iResult != 0) {
        printf("WSAStartup failed with error: %d\n", iResult);
        return 1;
    }

    ZeroMemory( &hints, sizeof(hints) );
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    // Resolve the server address and port
    iResult = getaddrinfo(argv[1], DEFAULT_PORT, &hints, &result);
    if ( iResult != 0 ) {
        printf("getaddrinfo failed with error: %d\n", iResult);
        WSACleanup();
        return 1;
    }

    // Attempt to connect to an address until one succeeds
    for(ptr=result; ptr != NULL ;ptr=ptr->ai_next) {

        // Create a SOCKET for connecting to server
        _socket = socket(ptr->ai_family, ptr->ai_socktype, 
            ptr->ai_protocol);
        if (_socket == INVALID_SOCKET) {
            printf("socket failed with error: %ld\n", WSAGetLastError());
            WSACleanup();
            return 1;
        }

        // Connect to server.
        iResult = connect( _socket, ptr->ai_addr, (int)ptr->ai_addrlen);
        if (iResult == SOCKET_ERROR) {
            closesocket(_socket);
            _socket = INVALID_SOCKET;
            continue;
        }
        break;
    }

    freeaddrinfo(result);

    if (_socket == INVALID_SOCKET) {
        printf("Unable to connect to server!\n");
        WSACleanup();
        return 1;
    }

    // Send an initial buffer
    iResult = send( _socket, sendbuf, (int)strlen(sendbuf), 0 );
    if (iResult == SOCKET_ERROR) {
        printf("send failed with error: %d\n", WSAGetLastError());
        closesocket(_socket);
        WSACleanup();
        return 1;
    }

    printf("Bytes Sent: %ld\n", iResult);

    // shutdown the connection since no more data will be sent
    iResult = shutdown(_socket, SD_SEND);
    if (iResult == SOCKET_ERROR) {
        printf("shutdown failed with error: %d\n", WSAGetLastError());
        closesocket(_socket);
        WSACleanup();
        return 1;
    }

    // Receive until the peer closes the connection
    do {

        iResult = recv(_socket, recvbuf, recvbuflen, 0);
        if ( iResult > 0 )
            printf("Bytes received: %d\n", iResult);
        else if ( iResult == 0 )
            printf("Connection closed\n");
        else
            printf("recv failed with error: %d\n", WSAGetLastError());

    } while( iResult > 0 );

    // cleanup
    closesocket(_socket);
    WSACleanup();

    return 0;
}
*/