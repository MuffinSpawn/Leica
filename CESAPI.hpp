
#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>

#include <string>


// Need to link with Ws2_32.lib, Mswsock.lib, and Advapi32.lib
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

#define DEFAULT_BUFLEN 512
#define DEFAULT_ADDRESS "192.168.0.1"
#define DEFAULT_PORT "700"

class
#ifdef _CPP_API_EXT_DLL
   AFX_EXT_CLASS
#endif
Connection
{
private:
   std::string _address;
   uint16_t _port;

public:
   Connection();
   Connection(const std::string address, const uint16_t port) : _address(address), _port(port);
};

