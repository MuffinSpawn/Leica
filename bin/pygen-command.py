# coding: utf-8

import importlib
import os
import sys
sys.path.append(os.getcwd())
from CESAPI.packet import *


def get_command_names():
    module = importlib.import_module('CESAPI.packet')
    command_packet_names = filter(lambda x: 'CT' == x[-2:] and not 'Basic' in x, dir(module))
    command_names = map(lambda x: x[:-2], command_packet_names)
    return command_names

def get_command_attributes(name):
    module = importlib.import_module('CESAPI.packet')
    packet = getattr(module, name + 'CT')()
    public_attrs = filter(lambda x: not '__' in x and not 'pack' in x, dir(packet))
    return public_attrs

def main():
    print('''
import time
from CESAPI.packet import *
class CommandSync(object):
  def __init__(self, connection):
    self.__connection = connection
    print()
  def execute(self, packet):
    stream = self.__connection._LTConnection__stream
    stream.write(packet)
    print()
    in_packet = None
    return_packet = None
    done = False
    while (not done):
      unread_count = stream.unreadCount()
      if unread_count > 0:
        in_packet = stream.read()
        packet_type = packetType(in_packet)
        if packetType(in_packet) == ES_DT_Command and \\
           in_packet.packetInfo.command == packet.packetInfo.command:
          return_packet = in_packet
          if in_packet.packetInfo.command != ES_C_StartMeasurement and \\
             in_packet.packetInfo.command != ES_C_StartNivelMeasurement:
            done = True
        elif packetType(in_packet) == ES_DT_Error:
          raise Exception("Command {} failed with status {}".format(in_packet.command, in_packet.status))
        elif packet_type == ES_DT_SingleMeasResult or packet_type == ES_DT_SingleMeasResult2:
          return_packet = in_packet
          done = True
        elif packet_type == ES_DT_NivelResult:
          self.nivel_measurement = in_packet
          done = True
        elif packet_type == ES_DT_ReflectorPosResult:
          pass
        elif packet_type == ES_DT_SystemStatusChange:
          if packet.packetInfo.command == ES_C_SetCoordinateSystemType and \\
             in_packet.systemStatusChange == ES_SSC_CoordinateSystemTypeChanged:
            done = True
        else:
          time.sleep(0.2)
    return return_packet

    ''')
    for name in get_command_names():
        if name == 'StopMeasurement':
            continue
        attributes = list(get_command_attributes(name))
        if len(attributes) > 0:
            arguments = ', '.join(get_command_attributes(name))
            print('  def {}(self, {}):'.format(name, arguments))
        else:
            print('  def {}(self):'.format(name))
        print('    packet = {}'.format(name+'CT()'))
        for attribute in attributes:
            print('    packet.{0} = {0}'.format(attribute))
        print('    return self.execute(packet)')
        print()

if __name__ == '__main__':
    main()
