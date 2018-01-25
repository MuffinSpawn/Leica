import time

import CESAPI

def main():
    address = 'localhost'
    port = 700
    connection = CESAPI.LTConnnection()
    packet_stream = connection.connect(address, port)

    Initialize command;
    packet_stream.write(command)

    message = packet_stream.read()
    while (message.packetHeader.type != ES_DT_Command and message.command != ES_C_Initialize or message.command) or
          (message.packetHeader.type != ES_DT_Error and message.command != ES_C_Initialize or message.command):
        message = packet_stream.read()
    if message.packetHeader.type == ES_DT_Command:

    connection.disconnect()

if __name__ == '__main__':
    main()
