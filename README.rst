Leica AT4xx laser tracker control modules
=========================================

This project provides pure python code for interacting with Leica AT4xx
laser trackers. The ``CESAPI.packet`` module was created by parsing the enums and
structures in C files provided by the official CESAPI Leica EmScon SDK.

The ``CESAPI.connection`` module provides infrastructure for connecting to,
sending packets to, and reading packets from the laser tracker. A synchronous
interaction class is provided in the ``CESAPI.command`` module that can
simplify simple laser tracker interactions.

Example code is provided in the ``bin`` directory.