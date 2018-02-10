# -*- coding: utf-8 -*-
"""
Created on Thu Feb  1 16:05:49 2018

@author: peter
"""
import logging
import time

from CESAPI.connection import *
from CESAPI.command import *

logging.basicConfig(level=logging.INFO)
logger = logging.getLogger(__name__)

def main():
    connection = LTConnection()
    try:
        connection.connect()
        command = CommandSync(connection)
        
        logger.info('Initializing laser tracker...')
        command.Initialize()

        logger.info('Measuring reflector..')
        measurement = command.StartMeasurement()
if __name__ == '__main__':
    main()
