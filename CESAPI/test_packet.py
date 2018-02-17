# -*- coding: utf-8 -*-
"""
Created on Thu Feb  1 16:05:49 2018

@author: peter
"""
import logging
import time
import unittest

from CESAPI.connection import Connection
from CESAPI.packet import *
from CESAPI.test import LTSimulator

logging.basicConfig(level=logging.INFO)
logger = logging.getLogger(__name__)

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
        except exception:
            pass
        finally:
            if connection != None:
                connection.disconnect()
        self.assertTrue(success)

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
        except exception:
            pass
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
            for index in range(10):
                stream.write(init)
                stream.write(status)
            
            time.sleep(1)

            initrts = []
            statusrts = []
            for index in range(10):
                initrts += [stream.read()]
                statusrts += [stream.read()]
        except exception:
            pass
        finally:
            if connection != None:
                connection.disconnect()

        for index in range(10):
            self.assertFalse(initrts[index] == None)
            self.assertEqual(ES_C_Initialize, initrts[index].packetInfo.command)
            self.assertFalse(statusrts[index] == None)
            self.assertEqual(ES_C_GetSystemStatus, statusrts[index].packetInfo.command)

# Test the packet ring buffer functionality when packet overflow occurs.
class BufferWrapAroundTestCase(ConnectionTestCase):
    def runTest(self):
        success = False
        connection = Connection()
        try:
            stream = connection.connect(host='localhost')
            stream.PACKET_BUFFER_SIZE = 10
            
            init = InitializeCT()
            for index in range(10):
                stream.write(init)
            status = GetSystemStatusCT()
            stream.write(status)
            
            time.sleep(1)

            rtpackets = []
            for index in range(10):
                rtpackets += [stream.read()]
        except exception:
            pass
        finally:
            if connection != None:
                connection.disconnect()

        for index in range(9):
            logger.debug('Inspecting packet #{}'.format(index))
            self.assertFalse(rtpackets[index] == None)
            self.assertEqual(ES_C_Initialize, rtpackets[index].packetInfo.command)
        logger.debug('Inspecting packet #{}'.format(9))
        self.assertFalse(rtpackets[9] == None)
        self.assertEqual(ES_C_GetSystemStatus, rtpackets[9].packetInfo.command)

if __name__ == '__main__':
    unittest.main()