import logging
import socket
import time
import threading
from CESAPI.packet import *

logging.basicConfig()
logger = logging.getLogger(__name__)
logger.setLevel(logging.INFO)

class PacketStream(threading.Thread):
    def __init__(self, sock):
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
        packet_factory = PacketFactory()

        main_thread = threading.main_thread()
        while self.__running:
            try:
                data_list = []
                data_count = 0
                while self.__running and data_count < PACKET_HEADER_SIZE:
                    logger.debug('Waiting for all header bytes...')
                    read_data = self.__sock.recv(PACKET_HEADER_SIZE-data_count)
                    data_list += [read_data]
                    data_count += len(read_data)
                    time.sleep(0.2)
                if not self.__running:
                    continue
                header_data = b''.join(data_list)
                logger.debug('PacketStream received {} bytes from laser tracker.'.format(len(header_data)))
                packet_header = PacketHeaderT()
                packet_header.unpack(header_data)
    
                logger.debug('PacketStream header data: {}'.format(header_data))
                logger.debug('PacketStream lPacketSize: {}'.format(packet_header.lPacketSize))

                while self.__running and data_count < packet_header.lPacketSize:
                    read_data = self.__sock.recv(packet_header.lPacketSize-PACKET_HEADER_SIZE)
                    data_list += [read_data]
                    data_count += len(read_data)
                if not self.__running:
                    continue
                data = b''.join(data_list)
                logger.debug('PacketStream data: {}'.format(data))
                logger.debug('PacketStream received a {} byte packet.'.format(len(data)))
                packet = packet_factory.packet(data)
    
                logger.debug('Acquiring lock (run)')
                self.__buffer_lock.acquire()
                logger.debug('Acquired lock (run)')
                # append or overwrite an old packet with the new packet
                if len(self.__packet_buffer) < self.PACKET_BUFFER_SIZE:
                    self.__packet_buffer += [packet]
                    logger.debug('PacketStream appended a {} byte packet to the input stream buffer.'.format(len(data)))
                else:
                    self.__packet_buffer[self.__tail_index] = packet
                    logger.debug('PacketStream set a {} byte packet at index {} of the input stream buffer.'.format(len(data), self.__tail_index))
                    if self.__tail_index == self.__head_index:
                        # If the tail is right behind the head (full buffer),
                        # move up the head index (lose oldest packet).
                        self.__head_index += 1
                        logger.debug('PacketStream incremented the input stream buffer head index to {}.'.format(self.__head_index))

                self.__tail_index += 1

                if self.__tail_index == self.PACKET_BUFFER_SIZE:
                    # If the tail is past the end of the buffer, loop it around to 0.
                    self.__tail_index = 0
                    logger.debug('PacketStream set the input stream buffer tail index to {}.'.format(self.__tail_index))
                logger.debug('Releasing lock (run)')
                self.__buffer_lock.release()
                logger.debug('Released lock (run)')
            except socket.timeout as ste:
                logger.debug('PacketStream timed out waiting for laser tracker packets.')
            except ConnectionAbortedError as cae:
                logger.debug('PacketStream socket connection was aborted: {}'.format(cae))
                self.__running = False
            except ConnectionResetError as cre:
                logger.debug('PacketStream socket connection was reset: {}'.format(cre))
                self.__running = False
            logger.debug('*** PacketStream buffer head index is {} and tail index is {}. ***'.format(self.__head_index, self.__tail_index))
            if not main_thread.is_alive():
                logger.debug('Main thread is dead.')
                self.__running = False
        logger.debug('PacketStream is terminating...')

    def unreadCount(self):
        count = 0
        logger.debug('Acquiring lock (unreadCount)')
        self.__buffer_lock.acquire()
        logger.debug('Acquired lock (unreadCount)')
        if len(self.__packet_buffer) == 0:
            count = 0
        elif self.__tail_index == self.__head_index:
            count = 0
        elif self.__tail_index > self.__head_index:
            count = self.__tail_index - self.__head_index
        else:
            count = self.PACKET_BUFFER_SIZE-self.__head_index + self.__tail_index
        logger.debug('Releasing lock (unreadCount)')
        self.__buffer_lock.release()
        logger.debug('Released lock (unreadCount)')
        return count

    def read(self):
        logger.debug('Acquiring lock (read)')
        self.__buffer_lock.acquire()
        logger.debug('Acquired lock (read)')
        logger.debug('### PacketStream buffer size is {}. ###'.format(len(self.__packet_buffer)))
        logger.debug('### PacketStream buffer head index is {} and tail index is {}. ###'.format(self.__head_index, self.__tail_index))
        if self.__head_index == len(self.__packet_buffer) or self.__packet_buffer[self.__head_index] == None:
            logger.debug('PacketStream packet buffer is empty. Returning None.'.format(self.__tail_index))
            self.__buffer_lock.release()
            return None
        packet = self.__packet_buffer[self.__head_index]
        self.__packet_buffer[self.__head_index] = None
        logger.debug('PacketStream popped the packet at input stream buffer head index {}.'.format(self.__head_index))
        self.__head_index += 1
        if self.__head_index == self.PACKET_BUFFER_SIZE:
            # If the head is past the end of the buffer, loop it around to 0
            self.__head_index = 0
            logger.debug('PacketStream set the input stream buffer head index to {}.'.format(self.__head_index))
        logger.debug('### PacketStream buffer head index is {} and tail index is {}. ###'.format(self.__head_index, self.__tail_index))
        logger.debug('Releasing lock (read)')
        self.__buffer_lock.release()
        logger.debug('Released lock (read)')
        return packet

    def write(self, packet):
        data = packet.pack()
        self.__sock.sendall(data)
        logger.debug('PacketStream sent a {} byte packet.'.format(len(data)))

class Connection(object):
    def __init__(self):
        self.__sock = None
        self.__stream = None
    
    def __del__(self):
        logger.debug("Destructing!")
        self.disconnect()

    def connect(self, host='192.168.0.1', port=700):
        if self.__sock != None:
            raise Exception("Repeat connection. Only one connection to the laser tracker is allowed at one time.")

        try:
            # Create a TCP/IP socket
            self.__sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            self.__sock.settimeout(1)
    
            # Connect the socket to the port where the server is listening
            self.__sock.connect((host, port))

            self.__stream = PacketStream(self.__sock)
            self.__stream.start()
        except socket.timeout as ste:
            self.disconnect()
            logger.debug('Client timed out waiting for a connection to the laser tracker.')
            raise ste
    
        return self.__stream

    def disconnect(self):
        logger.debug("Disconnecting!")
        if self.__stream != None:
            self.__stream.stop()
            self.__stream.join()
        if self.__sock != None:
            self.__sock.close()
            self.__sock = None