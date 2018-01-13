#define WIN32_LEAN_AND_MEAN

#include "CESAPI.hpp"

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>

#include <chrono>
#include<exception>
#include <string>
#include <thread>

// Need to link with Ws2_32.lib, Mswsock.lib, and Advapi32.lib
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

#define DEFAULT_BUFLEN 512
#define DEFAULT_ADDRESS "192.168.0.1"
#define DEFAULT_PORT 700


/*** Connection Class Member Definitions ***/

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

void Connection::Connect() {
  Connect(DEFAULT_ADDRESS, DEFAULT_PORT);
}

void Connection::Connect(const std::string address, const uint16_t port) {
    WSADATA wsaData;
    _socket = INVALID_SOCKET;
    struct addrinfo *result = NULL,
                    *ptr = NULL,
                    hints;
    int iResult;

    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
    if (iResult != 0) {
        throw ConnectionException(std::string("WSAStartup failed with error: ") + std::to_string(iResult));
    }

    ZeroMemory( &hints, sizeof(hints) );
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    // Resolve the server address and port
    iResult = getaddrinfo(address.c_str(), std::to_string(port).c_str(), &hints, &result);
    if ( iResult != 0 ) {
        WSACleanup();
        throw ConnectionException(std::string("getaddrinfo failed with error: ") + std::to_string(iResult));
    }

    // Attempt to connect to an address until one succeeds
    for(ptr=result; ptr != NULL ;ptr=ptr->ai_next) {

        // Create a SOCKET for connecting to server
        _socket = socket(ptr->ai_family, ptr->ai_socktype, 
            ptr->ai_protocol);
        if (_socket == INVALID_SOCKET) {
            WSACleanup();
            throw ConnectionException(std::string("socket failed with error: ") + std::to_string(WSAGetLastError()));
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
        throw ConnectionException(std::string("getaddrinfo failed with error: ") + std::to_string(iResult));
    }

    _commandAsync->StartReceiving();
}


void Connection::Disconnect() {
    if (_socket != INVALID_SOCKET) {
        closesocket(_socket);
        WSACleanup();
    }
}


/*** CommandAsync Class Member Definitions ***/

bool CommandAsync::SendPacket(void const * const PacketStart, const long PacketSize) const {
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