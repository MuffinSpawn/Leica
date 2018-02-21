# -*- coding: utf-8 -*-
"""
Created on Thu Feb  1 16:05:49 2018

@author: peter
"""
import logging
import socket
import time
import unittest

from CESAPI.connection import Connection
from CESAPI.packet import *
from CESAPI.test import LTSimulator

logging.basicConfig(level=logging.INFO)
logger = logging.getLogger(__name__)
logger.setLevel(logging.INFO)

# Base class for most of the other test cases. Used to setup and teardown
# the LTSimulator instance that the test cases use.
class ConnectionTestCase(unittest.TestCase):
    def __init(self):
        self.sim = None

    def setUp(self):
        self.sim = LTSimulator()
        self.sim.start()

    def tearDown(self):
        self.sim.stop()
        self.sim.join()

# Check that Connection gracefully fails if it cannot connect to the laser tracker.
class MissingLaserTrackerConnectionTestCase(unittest.TestCase):
    def runTest(self):
        success = False
        connection = Connection()
        try:
            stream = connection.connect(host='localhost')
        except ConnectionRefusedError:
            success = True
        except socket.timeout:
            success = True
        except Exception as e:
            logger.info('Received an unexpected exception: {}'.format(e))
        finally:
            if connection != None:
                connection.disconnect()
        self.assertTrue(success)

# Basic connect/disconnect test.
class LaserTrackerConnectionTestCase(ConnectionTestCase):
    def runTest(self):
        success = False
        connection = Connection()
        try:
            connection.connect(host='localhost')
    
            success = True
        except Exception as e:
            logger.info(e)
        finally:
            if connection != None:
                connection.disconnect()
        self.assertTrue(success)

# Destructor connection cleanup.
class DestructorCleanupTestCase(ConnectionTestCase):
    def runTest(self):
        connection = Connection()
        try:
            stream = connection.connect(host='localhost')
            del connection
    
            self.assertFalse(stream.is_alive())
        except Exception as e:
            logger.info(e)

# Send an InitializeCT packet and verify that an InitializeRT packet was returned.
class InitializeTestCase(ConnectionTestCase):
    def runTest(self):
        success = False
        connection = Connection()
        try:
            stream = connection.connect(host='localhost')
            
            init = InitializeCT()
            stream.write(init)
            
            time.sleep(1)
            
            initrt = stream.read()
        except Exception as e:
            logger.info(e)
        finally:
            if connection != None:
                connection.disconnect()

        self.assertFalse(initrt == None)
        self.assertEqual(ES_C_Initialize, initrt.packetInfo.command)

# Send several InitializeCT and GetSystemStatusCT packets and verify that
# appropriate return type packets were received.
class DelayedMultipleReadTestCase(ConnectionTestCase):
    def runTest(self):
        success = False
        connection = Connection()
        try:
            stream = connection.connect(host='localhost')
            
            init = InitializeCT()
            status = GetSystemStatusCT()
            for index in range(3):
                stream.write(init)
                stream.write(status)
            
            time.sleep(2)

            initrts = []
            statusrts = []
            for index in range(3):
                initrts += [stream.read()]
                statusrts += [stream.read()]
        except Exception as e:
            logger.info(e)
        finally:
            if connection != None:
                connection.disconnect()

        for index in range(3):
            self.assertFalse(initrts[index] == None)
            self.assertEqual(ES_C_Initialize, initrts[index].packetInfo.command)
            self.assertFalse(statusrts[index] == None)
            self.assertEqual(ES_C_GetSystemStatus, statusrts[index].packetInfo.command)

# Alternate reads and writes to make sure the packet buffer works
class AlternatingReadWriteTestCase(ConnectionTestCase):
    def runTest(self):
        success = False
        connection = Connection()
        try:
            stream = connection.connect(host='localhost')
            
            init = InitializeCT()
            initrts = []
            for index in range(5):
                stream.write(init)
                time.sleep(1)
                initrts += [stream.read()]
        except Exception as e:
            logger.info(e)
        finally:
            if connection != None:
                connection.disconnect()

        for index in range(5):
            self.assertFalse(initrts[index] == None)
            self.assertEqual(ES_C_Initialize, initrts[index].packetInfo.command)

# Test the packet ring buffer functionality when packet overflow occurs.
class BufferWrapAroundTestCase(ConnectionTestCase):
    def runTest(self):
        success = False
        connection = Connection()
        PACKET_BUFFER_SIZE = 3
        try:
            stream = connection.connect(host='localhost')
            stream.PACKET_BUFFER_SIZE = PACKET_BUFFER_SIZE
            
            init = InitializeCT()
            for index in range(PACKET_BUFFER_SIZE):
                stream.write(init)
            status = GetSystemStatusCT()
            stream.write(status)
            
            time.sleep(1)

            rtpackets = []
            for index in range(PACKET_BUFFER_SIZE):
                rtpackets += [stream.read()]
        except Exception as e:
            logger.info(e)
        finally:
            if connection != None:
                connection.disconnect()

        for index in range(PACKET_BUFFER_SIZE-1):
            logger.debug('Inspecting packet #{}'.format(index))
            self.assertFalse(rtpackets[index] == None)
            self.assertEqual(ES_C_Initialize, rtpackets[index].packetInfo.command)
        logger.debug('Inspecting packet #{}'.format(PACKET_BUFFER_SIZE-1))
        self.assertFalse(rtpackets[PACKET_BUFFER_SIZE-1] == None)
        self.assertEqual(ES_C_GetSystemStatus, rtpackets[PACKET_BUFFER_SIZE-1].packetInfo.command)

# Test the packet buffer's unreadCount after emptying.
class EmptyBufferSizeTestCase(ConnectionTestCase):
    def runTest(self):
        connection = Connection()
        try:
            stream = connection.connect(host='localhost')
            self.assertEqual(0, stream.unreadCount())

            stream.write(InitializeCT())
            time.sleep(1)
            self.assertEqual(1, stream.unreadCount())

            stream.read()
            self.assertEqual(0, stream.unreadCount())
            success = True
        except Exception as e:
            logger.info(e)
        finally:
            if connection != None:
                connection.disconnect()
        self.assertTrue(success)

if __name__ == '__main__':
    unittest.main()
