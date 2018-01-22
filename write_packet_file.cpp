#include <fstream>
#include <iostream>
#include <netinet/in.h>

#include "ES_C_API_Def.h"

int main(const int argc, char const * const * const argv) {
	BasicCommandRT foo;
	foo.packetHeader.lPacketSize = sizeof(foo);
	foo.packetHeader.type = ES_DT_Command;
	foo.command = ES_C_Initialize;
	foo.status = ES_RS_Unknown;

	std::ofstream fout;
	fout.open("packet.bin", std::ios::binary | std::ios::out);

	std::cout << "Writing " << foo.packetHeader.lPacketSize << " bytes to packet.bin..." << std::endl;
	// fout.write(reinterpret_cast<char *>(&foo), foo.packetHeader.lPacketSize);
	fout.write(reinterpret_cast<char *>(&htonl(foo.packetHeader.lPacketSize)), 8)
	fout.write(reinterpret_cast<char *>(&htons(foo.packetHeader.type)), 4)
	fout.write(reinterpret_cast<char *>(&htons(foo.command)), 4)
	fout.write(reinterpret_cast<char *>(&htons(foo.status)), 4)

	fout.close();
}