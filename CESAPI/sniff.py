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
import time
from CESAPI.packet import *
from CESAPI.connection import *

logging.basicConfig(level=logging.DEBUG)
logger = logging.getLogger(__name__)
logger.setLevel(logging.DEBUG)

class ClientRelay(threading.Thread):
    def __init__(self, packet_sniffer):
        super().__init__()
        self.__running = True
        self.packet_sniffer = packet_sniffer

    def stop(self):
        self.__running = False

    def run(self):
        logger.debug('Client Relay is running...')
        PACKET_HEADER_SIZE = 8  # lPacketSize, type

        try:
            while self.__running:
                # Relay client -> LT packets
                try:
                    logger.debug('Attempting to receive a client packet...')
                    header_data = self.packet_sniffer.client_connection.recv(PACKET_HEADER_SIZE)
                    if len(header_data) == 0:
                        logger.debug('Laser Tracker Packet Sniffer is waiting to receive client data...')
                        time.sleep(0.2)
                        continue
                    logger.debug('header data: {}'.format(header_data))
                    packet_header = PacketHeaderT()
                    packet_header.unpack(header_data)
                    logger.debug('packet size: {}'.format(packet_header.lPacketSize))
        
                    data = header_data + self.packet_sniffer.client_connection.recv(packet_header.lPacketSize-PACKET_HEADER_SIZE)
                    logger.info('Received {} byte packet from the CLIENT:\n{}'.format(len(data), data))
                    
                    self.packet_sniffer.lt_stream._PacketStream__sock.sendall(data)
                    logger.debug('sent {} byte packet to the laser tracker.'.format(len(data)))
                except socket.timeout:
                    logger.debug('Socket timed out waiting for client packets.')

        except ConnectionResetError:
            logger.debug('Client inbound_inbound_connection was reset.')
        except ConnectionAbortedError as cae:
            logger.debug('Client inbound connection was aborted.')
        except socket.timeout as ste:
            pass
        finally:
            self.__running = False

        logger.debug('Client Relay has stopped.')

class LaserTrackerRelay(threading.Thread):
    def __init__(self, packet_sniffer):
        super().__init__()
        self.__running = True
        self.packet_sniffer = packet_sniffer

    def stop(self):
        self.__running = False

    def run(self):
        logger.debug('Laser Tracker Relay is running...')
        try:
            while self.__running:
                # Relay client -> LT packets
                unread_count = self.packet_sniffer.lt_stream.unreadCount()
                logger.debug('Unread packet count: {}'.format(unread_count))
                while self.__running and unread_count > 0:
                    packet = self.packet_sniffer.lt_stream.read()
                    data = packet.pack()
                    logger.info('Received {} byte packet from the LASER TRACKER:\n{}'.format(len(data), data))

                    self.packet_sniffer.client_connection.sendall(data)
                    logger.debug('sent {} byte packet to the client'.format(len(data)))

                    unread_count = self.packet_sniffer.lt_stream.unreadCount()
                time.sleep(0.5)

        except ConnectionResetError:
            logger.debug('Laser Tracker connection was reset.')
        except ConnectionAbortedError as cae:
            logger.debug('Laser Tracker connection  was aborted.')
        finally:
            self.__running = False

        logger.debug('Laser Tracker Relay has stopped.')

class LTPacketSniffer(threading.Thread):
    def __init__(self):
        super().__init__()
        self.__running = True
        self.host = 'localhost'
        self.lt_host = '192.168.0.1'
        self.port = 700
        self.initialized = False
        self.client_connection = None
        self.lt_stream = None
        self.client_relay = None
        self.lt_relay = None

    def stop(self):
        self.__running = False
        if self.client_relay != None:
            self.client_relay.stop()
        if self.lt_relay != None:
            self.lt_relay.stop()

    def run(self):
        sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        sock.bind((self.host, self.port))
        sock.listen(1)
        sock.settimeout(1)
        logger.info('Laser Tracker Packet Sniffer was started on port {}.'.format(self.port))
        
        lt_connection = None

        try:
            while self.__running:
                while self.__running and self.client_connection == None:
                    try:
                        logger.debug('Waiting for client to connect...')
                        self.client_connection, client_address = sock.accept()
                    except socket.timeout as ste:
                        logger.debug('Client connection timed out.')
                        pass
                self.client_connection.settimeout(1)
                logger.debug('Laser Tracker Packet Sniffer accepted a client connection from {}.'.format(client_address))
        
                lt_connection = Connection()
                stream = None
                try:
                    logger.debug('Connecting to the laser tracker on host {} and port {}...'.format(self.lt_host, self.port))
                    self.lt_stream = lt_connection.connect(host=self.lt_host, port=self.port)
                except Exception as e:
                    logger.error('Unable to connect to the laser tracker: {}'.format(e))
                    if lt_connection != None:
                        lt_connection.disconnect()
                    return
                logger.info('Laser Tracker Packet Sniffer connected to the laser tracker on host {} and port {}.'.format(self.lt_host, self.port))
        
                self.client_relay = ClientRelay(self)
                self.client_relay.start()
        
                self.lt_relay = LaserTrackerRelay(self)
                self.lt_relay.start()
        
                self.client_relay.join()
                self.lt_relay.join()

        finally:
            if self.client_connection != None:
                self.client_connection.close()
            if lt_connection != None:
                lt_connection.disconnect()
            sock.close()

        logger.debug('Laser Tracker Packet Sniffer has stopped.')

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
    
