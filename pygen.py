# -*- coding: utf-8 -*-
"""
Created on Wed Jan 31 10:55:49 2018

@author: peter
"""
import sys
import pycparser
import pycparser.c_generator
from pycparser.c_ast import *
def main(argv):
    if len(argv) < 2:
        print("Error: C source code filename required as the argument 1")
        return
    filename = argv[1]
    ast = pycparser.parse_file(filename, use_cpp=False)

    # type_size_lookup = {}
    print('import struct')
    print()

    for (index, child) in enumerate(ast.children()):
        node_type = child[1].type
        # print(node_type)
        #node_name= child[1].type.name
        #print('{0} {1}'.format(node_type, node_name))
        if type(node_type) == Enum:
            print('# enum {1} (parse index: {0}):'.format(index, node_type.name))
            for member in node_type.values.enumerators:
                member_name = member.name
                # print('  {} = ??'.format(member_name))
                member_value = int(member.value.value)
                print('{} = {}'.format(member_name, member_value))
            print()
        elif type(node_type) == Struct:
            type_sizes = []
            member_inits = []
            member_assigns = []
            assign_index = 0
            type_formats = []
            new_subformat = True
            type_format_index = 0

            for (index, (member_id, member)) in enumerate(node_type.children()):
                member_name = member.name
                # print('  {} = ??'.format(enum_member_name))
                member_type = member.type
                if type(member_type) == TypeDecl:
                    if type(member_type.type) == IdentifierType:
                        member_type_name = member_type.type.names[0]
                        if new_subformat:
                            type_sizes += [int(0)]
                            type_formats += ["('"]
                            new_subformat = False
                            member_assigns += ['    packet_elements = struct.Struct(self.__formats[{0}]).unpack(packet[:self._size[{0}]])'.format(type_format_index)]
                            assign_index = 0
                            type_format_index += 1
                        if member_type_name == 'int':
                            type_sizes[-1] += 4
                            member_inits += ['    self.{} = {}(0)'.format(member_name, member_type_name)]
                            type_formats[-1] += "i "
                        elif member_type_name == 'long':
                            type_sizes[-1] += 8
                            member_inits += ['    self.{} = {}(0)'.format(member_name, 'int')]
                            type_formats[-1] += "L "
                        elif member_type_name == 'double':
                            type_sizes[-1] += 8
                            member_inits += ['    self.{} = {}(0)'.format(member_name, 'float')]
                            type_formats[-1] += "d "
                        member_assigns += ['    self.{} = packet_elements[{}]'.format(member_name, assign_index)]
                        assign_index += 1
                    elif type(member_type.type) == Enum:
                        if new_subformat:
                            type_sizes += [int(0)]
                            type_formats += ["('"]
                            new_subformat = False
                            member_assigns += ['    packet_elements = struct.Struct(self.__formats[{0}]).unpack(packet[:self._size[{0}]])'.format(type_format_index)]
                            assign_index = 0
                            type_format_index += 1
                        type_sizes[-1] += 4
                        member_inits += ['    self.{} = int(0)  # {}'.format(member_name, member_type.type.name)]
                        member_assigns += ['    self.{} = packet_elements[{}]'.format(member_name, assign_index)]
                        assign_index += 1
                        type_formats[-1] += "I "
                    elif type(member_type.type) == Struct:
                        # type_sizes[-1] += type_size_lookup[member_type.type.name]
                        if not new_subformat:
                            type_formats[-1] += "')"
                            new_subformat = True
                        member_inits += ['    self.{} = {}()'.format(member_name, member_type.type.name)]
                        member_assigns += ['    packet = self.{}.pack()'.format(member_name)]
                    else:
                        print('    # Skipped {} {} {}'.format(type(member_type.type), member_type.type.name, member_name))
                elif type(member_type) == ArrayDecl:
                    array_dim = int(member_type.dim.value)
                    if new_subformat:
                        type_sizes += [int(0)]
                        type_formats += ["('"]
                        new_subformat = False
                        member_assigns += ['    packet_elements = struct.Struct(self.__formats[{0}]).unpack(packet[:self._size[{0}]])'.format(type_format_index)]
                        assign_index = 0
                        type_format_index += 1
                    member_inits += ['    self.{} = str()  # {} bytes max'.format(member_name, array_dim)]
                    type_formats[-1] += "{}s ".format(array_dim)
                    member_assigns += ['    self.{} = packet_elements[{}]'.format(member_name, assign_index)]
                    assign_index += 1
            # type_size_lookup[node_type.name] = type_size
            if not new_subformat:
                type_formats[-1] += "')"

            print('class {}(object):  # parse index: {}:'.format(node_type.name, index))
            print('  def __init__(self):')
            for member_init in member_inits:
                print(member_init)
            print('    self.__sizes = [{}]'.format(','.join(map(str, type_sizes))))
            print('    self.__formats = [{}]'.format(','.join(type_formats)))
            print()
            print('  def unpack(self, packet):')
            for member_assign in member_assigns:
                print(member_assign)
            if len(type_sizes) > 0:
                print('    return packet[self.__sizes[{}]:]'.format(type_sizes[-1]))
            else:
                print('    return packet')
            print()
        else:
            print('# Skipped object {}'.format(type(node_type)))


'''
class PacketHeaderT(object):  # parse index: 37:
  def __init__(self):
    self.lPacketSize = int(0)
    self.type = 0  # ES_DataType
    self.__sizes = 12
    self.__formats = [('L I ')]

  def unpack(self, packet):
    packet_elements = struct.Struct(self.__formats[0]).unpack(packet[:self._size])
    self.lPacketSize = packet_elements[0]
    self.type = packet_elements[1]
    return data[self._size:]

  def pack(self):
    packet_elements = (self.lPacketSize, self.type)
    return struct.Struct(self.__formats[0]).pack(packet_elements)

class ReturnDataT(object):  # parse index: 38:
  def __init__(self):
    self.packetHeader = PacketHeaderT()
    self.status = 0  # ES_ResultStatus
    self.__sizes = 16
    self.__formats = self.packetHeader + ('I ')

  def unpack(self, packet):
    packet = self.packetHeader.unpack(packet)
    packet_elements = struct.Struct(self.__formats[0]).unpack(packet[:self._size])
    self.status = packet_elements[0]
    return data[self._size:]

  def pack(self):
    packet_elements = self.packetHeader.pack()
    return packet_elements + struct.Struct(self.__formats[0]).pack(packet_elements)
'''

if __name__ == "__main__":
    main(sys.argv)