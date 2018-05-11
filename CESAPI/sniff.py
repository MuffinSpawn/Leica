# -*- coding: utf-8 -*-
"""
Created on Thu Feb  1 12:41:29 2018

@author: Peter G. Lane (petergwinlane@gmail.com)
"""

import logging
import os
import platform
import signal
import socket
import sys
import threading
from CESAPI.packet import *
from CESAPI.connection import *

logging.basicConfig(level=logging.DEBUG)
logger = logging.getLogger(__name__)
logger.setLevel(logging.DEBUG)

class LTPacketSniffer(threading.Thread):
    def __init__(self):
        super().__init__()
        self.__running = True
        self.host = 'localhost'
        self.lt_host = '192.168.0.1'
        self.port = 700
        self.initialized = False

    def stop(self):
        self.__running = False

    def run(self):
        PACKET_HEADER_SIZE = 8  # lPacketSize, type
        packet_factory = PacketFactory()
        
        sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        sock.bind((self.host, self.port))
        sock.listen(1)
        sock.settimeout(1)
        inbound_connection = None
        logger.info('Laser Tracker Packet Sniffer was started on port {}.'.format(self.port))
        outbound_connection = Connection()
        stream = None
        try:
            stream = outbound_connection.connect(host=self.lt_host, port=self.port)
        except Exception as e:
            logger.error('Unable to connect to the laser tracer: {}'.format(e))
            if outbound_connection != None:
                outbound_connection.disconnect()
            return
        logger.info('Laser Tracker Packet Sniffer connected laser tracker on host {} and port {}.'.format(self.lt_host, self.port))

        while self.__running:
            try:
                logger.debug('Waiting for inbound_connection...')
                inbound_connection, client_address = sock.accept()
                inbound_connection.settimeout(1)
                logger.debug('Laser Tracker Packet Sniffer accepted a inbound_connection from {}.'.format(client_address))
                
                while self.__running:
                    try:
                        # Relay client -> LT packets
                        logger.debug('Attempting to receive a packet...')
                        header_data = inbound_connection.recv(PACKET_HEADER_SIZE)
                        if len(header_data) == 0:
                            logger.debug('Laser Tracker Packet Sniffer is waiting to receive data...')
                            time.sleep(0.2)
                            continue
                        logger.debug('header data: {}'.format(header_data))
                        packet_header = PacketHeaderT()
                        packet_header.unpack(header_data)
                        logger.debug('packet size: {}'.format(packet_header.lPacketSize))
            
                        data = header_data + inbound_connection.recv(packet_header.lPacketSize-PACKET_HEADER_SIZE)
                        logger.info('Received {} byte packet from the CLIENT:\n{}'.format(len(data), data))
                        
                        outbound_connection._Connection__sock.sendall(data)
                        logger.debug('sent {} byte packet to the laser tracker.'.format(len(data)))

                        # Relay client -> LT packets
                        unread_count = stream.unreadCount()
                        logger.debug('Unread packet count: {}'.format(unread_count))
                        while self.__running and unread_count > 0:
                            packet = stream.read()
                            data = packet.pack()
                            logger.info('Received {} byte packet from the LASER TRACKER:\n{}'.format(len(data), data))

                            inbound_connection.sendall(data)
                            logger.debug('sent {} byte packet to the client'.format(len(data)))
                    except socket.timeout:
                        logger.debug('Socket timed out waiting for client packets.')

            except ConnectionResetError:
                logger.debug('Client inbound_inbound_connection was reset.')
            except ConnectionAbortedError as cae:
                logger.debug('Client inbound connection was aborted.')
            except socket.timeout as ste:
                pass
            finally:
                if inbound_connection != None:
                    inbound_connection.close()

        sock.close()
        logger.debug('Laser tracker simulator has stopped.')

if __name__ == '__main__':
    sim = LTPacketSniffer()

    sim.start()
    print('<<< Server running. Press Ctrl+C stop... >>>')
    sys.stdout.flush()
    try:
        while True:
            time.sleep(0.2)
    except KeyboardInterrupt:
        sim.stop()
    sim.join()
    print('Laser Tracker Packet Sniffer has terminated.')
    
