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
    print('import time')
    print('from CESAPI.packet import *')
    print('class CommandSync(object):')
    print('  def __init__(self, connection):')
    print('    self.__connection = connection')
    print()
    print('  def execute(self, packet):')
    print('    stream = self.__connection._LTConnection__stream')
    print('    stream.write(packet)')
    print()
    print('    in_packet = None')
    print('    done = False')
    print('    while (not done):')
    print('      unread_count = stream.unreadCount()')
    print('      if unread_count > 0:')
    print('        in_packet = stream.read()')
    print('        if packetType(in_packet) == ES_DT_Command and \\')
    print('           in_packet.packetInfo.command == packet.packetInfo.command:')
    print('          done = True')
    print('        elif packetType(in_packet) == ES_DT_Error:')
    print("          raise Exception('Command {} failed with status {}'.format(in_packet.command, in_packet.status))")
    print('      time.sleep(0.2)')
    print('    return in_packet')
    print()
    for name in get_command_names():
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
