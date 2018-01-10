import socket
import sys

import CESAPI

SIZE_PACKET_HEADER = 8   # PacketHeaderT
SIZE_BASIC_COMMAND = 16  # BasicCommandRT
enc = CESAPI.Encoder()
dec = CESAPI.Decoder()

# Create a TCP/IP socket
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Connect the socket to the port where the server is listening
server_address = ('192.168.0.1', 700)
print('connecting to {}'.format(server_address))
sock.connect(server_address)

try:
    
    # Send data
    enc.Initialize()
    outPacket = enc.getPacket()
    print('sending "{}"'.format(outPacket))
    sock.sendall(outPacket)

    while True:
        # Look for the response
        amount_received = 0
        amount_expected = SIZE_PACKET_HEADER
        inPacket = b''
        while amount_received < amount_expected:
            data = sock.recv(amount_expected-amount_received)
            amount_received += len(data)
            # print('received "{}"'.format(data))
            inPacket = b''.join((inPacket, data))
        amount_expected = dec.getSize(inPacket)
        print("Packet Size: {}".format(amount_expected))
        while amount_received < amount_expected:
            data = sock.recv(amount_expected-amount_received)
            amount_received += len(data)
            # print('received "{}"'.format(data))
            inPacket = b''.join((inPacket, data))
        message = dec.decode(inPacket)

        messageType = message.getType()
        print('Message Type: {}'.format(messageType))
        messageTypeName = 'Unknown'
        if messageType == CESAPI.ES_DT_Command:
            messageTypeName = 'ES_DT_Command'
            commandType = message.getCommand().command
            print("Command Type: {}".format(commandType))
            if commandType == CESAPI.ES_C_Initialize:
                command = message.getInitialize()
                print("Init Status: {}".format(command.packetInfo.status))
                break
            else:
                print("Status: {}".format(message.getCommand().status))
        elif messageType == CESAPI.ES_DT_Error:
            messageTypeName = 'ES_DT_Error'
        elif messageType == CESAPI.ES_DT_SingleMeasResult:
            messageTypeName = 'ES_DT_SingleMeasResult'
        elif messageType == CESAPI.ES_DT_NivelResult:
            messageTypeName = 'ES_DT_NivelResult'
        elif messageType == CESAPI.ES_DT_ReflectorPosResult:
            messageTypeName = 'ES_DT_ReflectorPosResult'
            pos = message.getReflectorPosition()
            print("Reflector Position: ({},{},{})".format(pos.dVal1, pos.dVal2, pos.dVal3))
        elif messageType == CESAPI.ES_DT_SystemStatusChange:
            messageTypeName = 'ES_DT_SystemStatusChange'
        elif messageType == CESAPI.ES_DT_SingleMeasResult2:
            messageTypeName = 'ES_DT_SingleMeasResult2'
        else:
            messageTypeName = 'Unknown'
        print('Message Type Name: {}'.format(messageTypeName))

finally:
    print('closing socket')
    sock.close()