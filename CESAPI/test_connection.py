# -*- coding: utf-8 -*-
"""
Created on Thu Feb  1 16:05:49 2018

@author: peter
"""
import unittest

from CESAPI.connection import *
from CESAPI.packet import *
from CESAPI.test import *

class ConnectionTestCase(unittest.TestCase):
    def __init(self):
        self.sim = None

    def setUp(self):
        self.sim = LTSimulator()
        self.sim.start()

    def tearDown(self):
        self.sim.stop()
        self.sim.join()

class MissingLaserTrackerConnectionTestCase(unittest.TestCase):
    def runTest(self):
        success = False
        connection = LTConnection()
        try:
            stream = connection.connect()
        except ConnectionRefusedError:
            success = True
        finally:
            if connection != None:
                connection.disconnect()
        self.assertTrue(success)

class LaserTrackerConnectionTestCase(ConnectionTestCase):
    def runTest(self):
        success = False
        connection = LTConnection()
        try:
            connection.connect()
    
            success = True
        except exception:
            pass
        finally:
            if connection != None:
                connection.disconnect()
        self.assertTrue(success)

if __name__ == '__main__':
    unittest.main()