import socket
import threading

import CESAPI

class LTPacketFactory(object):
	def packet(self, packet_header, body_data):
		packet_type = packet_header[1]
		if packet_type


class LTPacketStream(Thread):
	def __init__(self, sock):
		self.__sock = sock
		self.__running = False
		self.PACKET_HEADER_SIZE = 8
		self.PACKET_BUFFER_SIZE = 1000
		self.__packet_buffer = []

	def start(self):
		self.__running = True

	def run(self):
		packet_factory = CESAPI.LTPacketFactory()

		while __running:
			header_data = __sock.recv(self.PACKET_HEADER_SIZE)
			packet_header = struct.Struct('L I')
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