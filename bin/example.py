# -*- coding: utf-8 -*-
"""
Created on Thu Feb  1 16:05:49 2018

@author: peter
"""
import logging
import time

from CESAPI.connection import *
from CESAPI.packet import *
from CESAPI.test import *

logging.basicConfig(level=logging.INFO)
logger = logging.getLogger(__name__)

def packetType(packet):
    attributes = dir(packet)
    if 'packetHeader' in attributes:
        return packet.packetHeader.type
    elif 'packetInfo' in attributes:
        return packetType(packet.packetInfo)
    else:
        return type(packet)

def main():
    connection = LTConnection()
    try:
        stream = connection.connect()
        
        init = InitializeCT()
        stream.write(init)
        
        in_packet = None
        while (packetType(in_packet) != ES_DT_Command and packetType(in_packet) != ES_DT_Error):
            unread_count = stream.unreadCount()
            logger.debug('Unread packet count: {}'.format(unread_count))
            if unread_count > 0:
                in_packet = stream.read()
                if in_packet == None:
                    logger.debug('No packet read.')
                else:
                    logger.info('Recieved type {} packet.'.format(packetType(in_packet)))
                    logger.debug(in_packet.pack())
            time.sleep(1)
        if packetType(in_packet) == ES_DT_Command and in_packet.packetInfo.command == ES_C_Initialize:
            logger.info('Received initialize acknowledgement.')
        elif packetType(in_packet) == ES_DT_Error:
            logger.info('Received error for command {} with status {}.'.format(in_packet.command, in_packet.status))
    #except Exception as e:
    #    logger.error(str(e))
    finally:
        if connection != None:
            connection.disconnect()


if __name__ == '__main__':
    main()