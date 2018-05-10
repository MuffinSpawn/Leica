# -*- coding: utf-8 -*-
"""
Created on Thu Feb  1 16:05:49 2018

@author: peter
"""
import logging
import time
import unittest

from CESAPI.packet import *

logging.basicConfig(level=logging.INFO)
logger = logging.getLogger(__name__)
logger.setLevel(logging.INFO)

# Character string fields expect byte array, not str.
class BadCharacterStringFieldTestCase(unittest.TestCase):
    def runTest(self):
        success = False
        try:
            packet = GetCompensations2RT()
            packet.cTrackerCompensationName = 'TestCompensationName'
            packet.pack()
        except Exception as e:
            if str(e) == "argument for 's' must be a bytes object":
                success = True
        self.assertTrue(success)


# Character string fields expect byte array, not str.
class GoodCharacterStringFieldTestCase(unittest.TestCase):
    def runTest(self):
        success = True
        try:
            packet = GetCompensations2RT()
            packet.cTrackerCompensationName = b'TestCompensationName'
            packet.pack()
        except Exception as e:
            logger.info(str(e))
            success = False
        self.assertTrue(success)
if __name__ == '__main__':
    unittest.main()
