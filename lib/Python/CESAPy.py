import socket
import threading

# import CESAPI

'''
ES_API enum ES_DataType
{
    ES_DT_Command = 0,
    ES_DT_Error = 1,
    ES_DT_SingleMeasResult = 2,
    ES_DT_NivelResult = 6,
    ES_DT_ReflectorPosResult = 7,
    ES_DT_SystemStatusChange = 8,
    ES_DT_SingleMeasResult2 = 9,
};
'''

class PacketHeaderT(object):
	def __init__(self, packet_header):
		self.lPacketSize = packet_header[0]
		self.type = packet_header[1]

class ReturnDataT(object):
	def __init__(self, packet_header, body_data):
		self.packetHeader = PacketHeaderT(packet_header)
		body = struct.Struct('I').unpack(body_data)
		self.status = body[1]

class BasicCommandRT(object):
	def __init__(self, packet_header, body_data):
		self.packetHeader = PacketHeaderT(packet_header)
		body = struct.Struct('I I').unpack(body_data)
		self.command = body[0]
		self.status = body[1]

struct NivelResultT
{
    struct ReturnDataT  packetInfo;
    enum ES_NivelStatus nivelStatus;
    double              dXTilt;
    double              dYTilt;
    double              dNivelTemperature;
};

class NivelResultT(object):
	def __init__(self, packet_header, body_data):
		self.packetHeader = PacketHeaderT(packet_header)
		body = struct.Struct('I I').unpack(body_data)
		self.command = body[0]
		self.status = body[1]




class LTPacketFactory(object):
	def __init__(self):
		self.PACKET_HEADER_SIZE = 12
		self.RETURN_DATA_SIZE = 16
		self.RETURN_DATA_BODY_SIZE = self.RETURN_DATA_SIZE-self.PACKET_HEADER_SIZE
		self.BASIC_COMMAND_SIZE = 20
		self.BASIC_COMMAND_BODY_SIZE = self.BASIC_COMMAND_SIZE-self.PACKET_HEADER_SIZE

	def packet(self, packet_header, body_data):
		packet_type = packet_header[1]
		if packet_header.type == ES_DT_Command:
			packet_info = BasicCommandRT(packet_header, body_data[:self.BASIC_COMMAND_BODY_SIZE])
		elif packet_header.type == ES_DT_Error:
			packet_info = ReturnDataT(packet_header, body_data[:self.RETURN_DATA_BODY_SIZE])
		elif packet_header.type == ES_DT_SingleMeasResult:
			packet_info = ReturnDataT(packet_header, body_data)[:self.RETURN_DATA_BODY_SIZE]
		elif packet_header.type == ES_DT_NivelResult:
			packet_info = ReturnDataT(packet_header, body_data[:self.RETURN_DATA_BODY_SIZE])
		elif packet_header.type == ES_DT_ReflectorPosResult:
			packet_info = ReturnDataT(packet_header, body_data[:self.RETURN_DATA_BODY_SIZE])
		elif packet_header.type == ES_DT_SystemStatusChange:
			packet_info = ReturnDataT(packet_header, body_data[:self.RETURN_DATA_BODY_SIZE])
		elif packet_header.type == ES_DT_SingleMeasResult2:
			packet_info = ReturnDataT(packet_header, body_data[:self.RETURN_DATA_BODY_SIZE])
		else:
			packet = PacketHeaderT(packet_header)
		return packet

class LTPacketStream(Thread):
	def __init__(self, sock):
		self.__sock = sock
		self.__running = False
		self.PACKET_HEADER_SIZE = 12  # lPacketSize, type
		self.PACKET_BUFFER_SIZE = 1000
		self.__packet_buffer = []

	def start(self):
		self.__running = True

	def run(self):
		packet_factory = CESAPI.LTPacketFactory()

		while __running:
			header_data = __sock.recv(self.PACKET_HEADER_SIZE)
			packet_header = struct.Struct('L I').unpack(header_data)
			packet_size = packet_header[0]

			body_data = __sock.recv(packet_size-self.PACKET_HEADER_SIZE)
			packet = packet_factory.packet(packet_header, body_data)


class LTConnection(object):
	def __init__(self):
		self.__sock = None
		self.__stream = None

	def connect(self, host, port):
		if __sock != None:
			raise Exception("Repeat connection. Only one connection to the laser tracker is allowed at one time.")

		# Create a TCP/IP socket
		self.__sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

		# Connect the socket to the port where the server is listening
		self.__sock.connect((host, port))

		self.__stream = LTPacketStream(__sock)
		self.__stream
		return __stream

	def disconnect(self):
		self.__sock.close()
		self.__sock = None