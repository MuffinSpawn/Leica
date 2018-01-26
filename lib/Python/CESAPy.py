import socket
import threading

# import CESAPI

class PacketHeaderT(object):
	def __init__(self, packet_header):
		self.lPacketSize = packet_header[0]
		self.type = packet_header[1]

class ReturnDataT(object):
	def __init__(self, packet_header, body_data):
		self.packetHeader = packet_header
		body = struct.Struct('I').unpack(body_data)
		self.status = body[1]

class BasicCommandRT(object):
	def __init__(self, packet_header, body_data):
		self.packetHeader = packet_header
		body = struct.Struct('I I').unpack(body_data)
		self.command = body[0]
		self.status = body[1]

class ErrorResponseT(object):
	def __init__(self, packet_header, body_data):
		self.packetHeader = packet_header
		body = struct.Struct('I I').unpack(body_data)
		self.command = body[0]
		self.status = body[1]

class NivelResultT(object):
	def __init__(self, packet_info, body_data):
		self.packetInfo = packet_info
		body = struct.Struct('I d d d').unpack(body_data)
		self.nivelStatus = body[0]
		self.dXTilt = body[1]
		self.dYTilt = body[2]
		self.dNivelTemperature = body[3]

class SingleMeasResultT(object):
	def __init__(self, packet_info, body_data):
		self.packetInfo = packet_info
		body = struct.Struct('I I d d d d d d d d d d d d d d d d d').unpack(body_data)
		self.measMode = body[0]
		self.bIsTryMode = body[1]
		self.dVal1 = body[2]
		self.dVal2 = body[3]
		self.dVal3 = body[4]
		self.dStd1 = body[5]
		self.dStd2 = body[6]
		self.dStd3 = body[7]
		self.dStdTotal = body[8]
		self.dPointingError1 = body[9]
		self.dPointingError2 = body[10]
		self.dPointingError3 = body[11]
		self.dAprioriStd1 = body[12]
		self.dAprioriStd2 = body[13]
		self.dAprioriStd3 = body[14]
		self.dAprioriStdTotal = body[15]
		self.dVal2 = dTemperature[16]
		self.dVal2 = dPressure[17]
		self.dVal2 = dHumidity[18]

class ReflectorPosResultT(object):
	def __init__(self, packet_info, body_data):
		self.packetInfo = packet_info
		body = struct.Struct('d d d').unpack(body_data)
		self.dVal1 = body[0]
		self.dVal2 = body[1]
		self.dVal3 = body[2]

class ReflectorPosResultT(object):
	def __init__(self, packet_header, body_data):
		self.packetHeader = packet_header
		body = struct.Struct('I').unpack(body_data)
		self.systemStatusChange = body[0]

class SingleMeasResult2T(object):
	def __init__(self, packet_info, body_data):
		self.packetInfo = packet_info
		body = struct.Struct('I I d d d d d d d d d d d d d d d d d d d d d d d').unpack(body_data)
		self.measMode = body[0]
		self.bIsTryMode = body[1]
		self.dVal1 = body[2]
		self.dVal2 = body[3]
		self.dVal3 = body[4]
		self.dStd1 = body[5]
		self.dStd2 = body[6]
		self.dStd3 = body[7]
		self.dStdTotal = body[8]
		self.dCovar12 = body[9]
		self.dCovar13 = body[10]
		self.dCovar23 = body[11]
		self.dPointingErrorH = body[12]
		self.dPointingErrorV = body[13]
		self.dPointingErrorD = body[14]
		self.dAprioriStd1 = body[15]
		self.dAprioriStd2 = body[16]
		self.dAprioriStd3 = body[17]
		self.dAprioriStdTotal = body[18]
		self.dAprioriCovar12 = body[19]
		self.dAprioriCovar13 = body[20]
		self.dAprioriCovar23 = body[21]
		self.dVal2 = dTemperature[22]
		self.dVal2 = dPressure[23]
		self.dVal2 = dHumidity[24]

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
			# instantiate specific command type
		elif packet_header.type == ES_DT_Error:
			packet = ErrorResponseT(packet_header, body_data)
		elif packet_header.type == ES_DT_SingleMeasResult:
			packet_info = ReturnDataT(packet_header, body_data[:self.RETURN_DATA_BODY_SIZE])
			packet = SingleMeasResultT(packet_info, body_data[self.RETURN_DATA_BODY_SIZE:])
		elif packet_header.type == ES_DT_NivelResult:
			packet_info = ReturnDataT(packet_header, body_data[:self.RETURN_DATA_BODY_SIZE])
			packet = NivelResultT(packet_info, body_data[self.RETURN_DATA_BODY_SIZE:])
		elif packet_header.type == ES_DT_ReflectorPosResult:
			packet_info = ReturnDataT(packet_header, body_data[:self.RETURN_DATA_BODY_SIZE])
			packet = ReflectorPosResultT(packet_info, body_data[self.RETURN_DATA_BODY_SIZE:])
		elif packet_header.type == ES_DT_SystemStatusChange:
			packet = ReflectorPosResultT(packet)_header, body_data)
		elif packet_header.type == ES_DT_SingleMeasResult2:
			packet_info = ReturnDataT(packet_header, body_data[:self.RETURN_DATA_BODY_SIZE])
			packet = SingleMeasResult2T(packet_info, body_data[self.RETURN_DATA_BODY_SIZE:])
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
		self.__head_index = 0
		self.__tail_index = 0

	def start(self):
		self.__running = True

	def stop(self):
		self.__running = False

	def run(self):
		packet_factory = CESAPI.LTPacketFactory()

		while __running:
			header_data = __sock.recv(self.PACKET_HEADER_SIZE)
			packet_header = struct.Struct('L I').unpack(header_data)
			packet_size = packet_header[0]

			body_data = __sock.recv(packet_size-self.PACKET_HEADER_SIZE)
			packet = packet_factory.packet(packet_header, body_data)
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
		self.__stream.start()
		return __stream

	def disconnect(self):
		self.__stream.stop()
		self.__sock.close()
		self.__sock = None