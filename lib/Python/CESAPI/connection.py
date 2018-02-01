import socket
import threading
from CESAPI.packet import *

class LTPacketFactory(object):
    def packet(self, packet_type, data):
        if packet_type == ES_DT_Command:
            if command == ES_C_Initialize:
                packet = InitializeRT()
        elif packet_type == ES_DT_Error:
            packet = ErrorResponseT()
        elif packet_type == ES_DT_SingleMeasResult:
            packet_info = ReturnDataT()
            packet = SingleMeasResultT()
        elif packet_type == ES_DT_NivelResult:
            packet_info = ReturnDataT()
            packet = NivelResultT()
        elif packet_type == ES_DT_ReflectorPosResult:
            packet_info = ReturnDataT()
            packet = ReflectorPosResultT()
        elif packet_type == ES_DT_SystemStatusChange:
            packet = ReflectorPosResultT()
        elif packet_type == ES_DT_SingleMeasResult2:
            packet_info = ReturnDataT()
            packet = SingleMeasResult2T()
        else:
            packet = PacketHeaderT(packet_header)
        return packet.unpack(data)


class LTPacketStream(threading.Thread):
    def __init__(self, sock):
        self.__sock = sock
        self.__running = False
        self.PACKET_BUFFER_SIZE = 1000
        self.__packet_buffer = []
        self.__head_index = 0
        self.__tail_index = 0

    def start(self):
        self.__running = True

    def stop(self):
        self.__running = False

    def run(self):
        PACKET_HEADER_SIZE = 12  # lPacketSize, type
        packet_factory = LTPacketFactory()

        while self.__running:
            header_data = self.__sock.recv(PACKET_HEADER_SIZE)
            packet_header = PacketHeaderT(header_data)

            data = header_data + self.__sock.recv(packet_header.lPacketSize-PACKET_HEADER_SIZE)
            packet = packet_factory.packet(packet_header.type, data)

            self.__packet_buffer[self.__tail_index] = packet
            self.__tail_index += 1
            if self.__tail_index == self.PACKET_BUFFER_SIZE:
                self.__tail_index = 0
            if self.__tail_index == self.__head_index:
                self.__head_index += 1
            if self.__head_index == self.PACKET_BUFFER_SIZE:
                self.__head_index = 0

    def read(self):
        if self.__tail_index == self.__head_index:
            return None
        packet = self.__packet_buffer[self.__head_index]
        self.__head_index += 1
        if self.__head_index == self.PACKET_BUFFER_SIZE:
            self.__head_index = 0
        return packet

    def write(self, packet):
        self.__sock.sendall(packet.pack())

class LTConnection(object):
    def __init__(self):
        self.__sock = None
        self.__stream_in = None

    def connect(self, host, port):
        if self.__sock != None:
            raise Exception("Repeat connection. Only one connection to the laser tracker is allowed at one time.")

        # Create a TCP/IP socket
        self.__sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

        # Connect the socket to the port where the server is listening
        self.__sock.connect((host, port))

        self.__stream_in = LTPacketStream(self.__sock)
        self.__stream_in.start()
        return self.__stream_in

    def disconnect(self):
        self.__stream_in.stop()
        self.__sock.close()
        self.__sock = None