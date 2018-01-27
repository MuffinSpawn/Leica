import binascii
import struct

'''
struct PacketHeaderT
{
    long             lPacketSize;
    enum ES_DataType type;
};

struct BasicCommandRT
{
    struct PacketHeaderT packetHeader;
    enum ES_Command      command;
    enum ES_ResultStatus status;
};
'''


def main():
    fh = open('packet.bin', 'rb')
    try:
        packet = fh.read(20)
    finally:
        fh.close
    fh.close()
    print('{} Packet Hex Digits: {}'.format(len(packet), binascii.hexlify(packet)))

    # BasicCommandRT = struct.Struct('!Q I I I')
    BasicCommandRT = struct.Struct('L I I I')
    command = BasicCommandRT.unpack(packet)
    print('Packet Values: {}'.format(command))


if __name__ == "__main__":
        main()