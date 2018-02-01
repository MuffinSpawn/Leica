# Leica

Code for working with Leica laser trackers.

## Python Package

The CESAPI Python package modules are in the CESAPI directory. The code that
generates CESAPI/packet.py is the creatively-named pygen.py in the top-level
directory. The pygen.py script requires the pycparser module to run. It parses
the C header file (with all pre-processor directives and comments removed)
include/ES_C_API_Def_clean.h and produces variables from enums and classes
from structs.

The packet classes have two functions: pack and unpack. The pack function serializes the class member data into a byte string that can be translated by a C program into the struct it was constructed from. The unpack function takes a struct byte string and deserializes it into the member variables.

I have done a manual, rudimentary test on the packet code. If I were a good
little boy I would have written unit tests first, but when you only get
15 minutes here and there to work on a project, you tend to want to stick to
the fun stuff and the design evolves sporadically.

## Python Module Next Steps

* Finish the LTPacketFactory to generate all of the ES_DT_Command type packets
* Write a laser tracker simulator to test the socket code in CESAPI/connection.py
* Write proper unit and integration tests.
* Properly package the Python code.

## C++ Library

Things are a bit of a mess right now. I'm not sure what state the C++ code is
in as I stopped working on it in favor of furthering a set of pure Python
modules.

## LTControl.dll CLSIDs

LTConnect: E73780A3-025C-11D5-BBB7-00508B35B332
LTControlAsync: 58DB5620-0186-11D5-BBB6-00508B35B332
LTControlSync: 58DB561E-0186-11D5-BBB6-00508B35B332
