import logging
import socket
import threading
from CESAPI.packet import *

class PacketStream(threading.Thread):
    def __init__(self, sock):
        logging.basicConfig()
        self.__logger = logging.getLogger(__name__)
        self.__logger.setLevel(logging.INFO)

        super().__init__()
        self.__sock = sock
        self.__running = True
        self.PACKET_BUFFER_SIZE = 1000
        self.__packet_buffer = []
        self.__head_index = 0
        self.__tail_index = 0
        self.__buffer_lock = threading.Lock()

    def stop(self):
        self.__running = False

    def run(self):
        PACKET_HEADER_SIZE = 12  # lPacketSize, type
        packet_factory = LTPacketFactory()

        while self.__running:
            try:
                data_list = []
                data_count = 0
                while data_count < PACKET_HEADER_SIZE:
                    read_data = self.__sock.recv(PACKET_HEADER_SIZE-data_count)
                    data_list += [read_data]
                    data_count += len(read_data)
                header_data = b''.join(data_list)
                self.__logger.debug('PacketStream received {} bytes from laser tracker.'.format(len(header_data)))
                packet_header = PacketHeaderT()
                packet_header.unpack(header_data)
    
                self.__logger.debug('PacketStream header data: {}'.format(header_data))
                self.__logger.debug('PacketStream lPacketSize: {}'.format(packet_header.lPacketSize))

                while data_count < packet_header.lPacketSize:
                    read_data = self.__sock.recv(packet_header.lPacketSize-PACKET_HEADER_SIZE)
                    data_list += [read_data]
                    data_count += len(read_data)
                data = b''.join(data_list)
                self.__logger.debug('PacketStream data: {}'.format(data))
                self.__logger.debug('PacketStream received a {} byte packet.'.format(len(data)))
                packet = packet_factory.packet(data)
    
                self.__buffer_lock.acquire()
                # append or overwrite an old packet with the new packet
                if len(self.__packet_buffer) < self.PACKET_BUFFER_SIZE:
                    self.__packet_buffer += [packet]
                    self.__logger.debug('PacketStream appended a {} byte packet to the input stream buffer.'.format(len(data)))
                else:
                    self.__packet_buffer[self.__tail_index] = packet
                    self.__logger.debug('PacketStream set a {} byte packet at index {} of the input stream buffer.'.format(len(data), self.__tail_index))
                    if self.__tail_index == self.__head_index:
                        # If the tail is right behind the head (full buffer),
                        # move up the head index (lose oldest packet).
                        self.__head_index += 1
                        self.__logger.debug('PacketStream incremented the input stream buffer head index to {}.'.format(self.__head_index))

                self.__tail_index += 1

                if self.__tail_index == self.PACKET_BUFFER_SIZE:
                    # If the tail is past the end of the buffer, loop it around to 0.
                    self.__tail_index = 0
                    self.__logger.debug('PacketStream set the input stream buffer tail index to {}.'.format(self.__tail_index))
                self.__buffer_lock.release()
            except socket.timeout as ste:
                self.__logger.debug('PacketStream timed out waiting for laser tracker packets.')
            self.__logger.debug('*** PacketStream buffer head index is {} and tail index is {}. ***'.format(self.__head_index, self.__tail_index))

    def unreadCount(self):
        count = 0
        self.__buffer_lock.acquire()
        if len(self.__packet_buffer) == 0:
            count = 0
        elif self.__tail_index == self.__head_index:
            count = 0
        elif self.__tail_index > self.__head_index:
            count = self.__tail_index - self.__head_index
        else:
            count = self.PACKET_BUFFER_SIZE-self.__head_index + self.__tail_index
        self.__buffer_lock.release()
        return count

    def read(self):
        self.__buffer_lock.acquire()
        self.__logger.debug('### PacketStream buffer size is {}. ###'.format(len(self.__packet_buffer)))
        self.__logger.debug('### PacketStream buffer head index is {} and tail index is {}. ###'.format(self.__head_index, self.__tail_index))
        if self.__head_index == len(self.__packet_buffer) or self.__packet_buffer[self.__head_index] == None:
            self.__logger.debug('PacketStream packet buffer is empty. Returning None.'.format(self.__tail_index))
            return None
        packet = self.__packet_buffer[self.__head_index]
        self.__packet_buffer[self.__head_index] = None
        self.__logger.debug('PacketStream popped the packet at input stream buffer head index {}.'.format(self.__head_index))
        self.__head_index += 1
        if self.__head_index == self.PACKET_BUFFER_SIZE:
            # If the head is past the end of the buffer, loop it around to 0
            self.__head_index = 0
            self.__logger.debug('PacketStream set the input stream buffer head index to {}.'.format(self.__head_index))
        self.__logger.debug('### PacketStream buffer head index is {} and tail index is {}. ###'.format(self.__head_index, self.__tail_index))
        self.__buffer_lock.release()
        return packet

    def write(self, packet):
        data = packet.pack()
        self.__sock.sendall(data)
        self.__logger.debug('PacketStream sent a {} byte packet.'.format(len(data)))

class Connection(object):
    def __init__(self):
        self.__sock = None
        self.__stream = None

    def connect(self, host='192.168.0.1', port=700):
        if self.__sock != None:
            raise Exception("Repeat connection. Only one connection to the laser tracker is allowed at one time.")

        try:
            # Create a TCP/IP socket
            self.__sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            self.__sock.settimeout(3)
    
            # Connect the socket to the port where the server is listening
            self.__sock.connect((host, port))

            self.__stream = PacketStream(self.__sock)
            self.__stream.start()
        except socket.timeout as ste:
            self.disconnect()
            self.__logger.debug('Client timed out waiting for a connection to the laser tracker.')
            raise ste
    
        return self.__stream

    def disconnect(self):
        if self.__stream != None:
            self.__stream.stop()
            self.__stream.join()
        if self.__sock != None:
            self.__sock.close()
            self.__sock = None