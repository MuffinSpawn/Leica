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

def main():
    connection = LTConnection()
    try:
        stream = connection.connect()
        
        logger.info('Initializing laser tracker...')
        init = InitializeCT()
        stream.write(init)
        
        in_packet = None
        done = False
        while (not done):
            unread_count = stream.unreadCount()
            logger.debug('Unread packet count: {}'.format(unread_count))
            if unread_count > 0:
                in_packet = stream.read()
                logger.debug('Recieved type {} packet'.format(packetType(in_packet)))
                if packetType(in_packet) == ES_DT_Command and in_packet.packetInfo.command == ES_C_Initialize:
                    logger.info('Done initializing laser tracker.')
                    done = True
                elif packetType(in_packet) == ES_DT_Error:
                    logger.info('Received error for command type {} with status code {}.'.format(in_packet.command, in_packet.status))
                    if in_packet.packetInfo.command == ES_C_Initialize:
                        done = True
            time.sleep(1)
    finally:
        if connection != None:
            connection.disconnect()


if __name__ == '__main__':
    main()