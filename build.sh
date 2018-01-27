#!/bin/bash

g++ -IInclude -o write-packet-file write_packet_file.cpp

swig -python -py3 -c++ CESAPI.i
g++ -fPIC -c CESAPI_wrap.cxx -IInclude -I/usr/include/python3.6 -I/usr/lib/python3.6/config
g++ -shared CESAPI_wrap.o -o _CESAPI.so
