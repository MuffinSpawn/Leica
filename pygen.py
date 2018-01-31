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

    type_sizes = {}

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
            print('class {}(object):  # parse index: {}:'.format(node_type.name, index))
            print('  def __init__(self):')

            type_size = int(0)

            for (member_id, member) in node_type.children():
                member_name = member.name
                # print('  {} = ??'.format(enum_member_name))
                member_type = member.type
                if type(member_type) == TypeDecl:
                    if type(member_type.type) == IdentifierType:
                        member_type_name = member_type.type.names[0]
                        if member_type_name == 'int':
                            type_size += 4
                            print('    self.{} = {}(0)'.format(member_name, member_type_name))
                        elif member_type_name == 'long':
                            type_size += 8
                            print('    self.{} = {}(0)'.format(member_name, 'int'))
                        elif member_type_name == 'double':
                            type_size += 8
                            print('    self.{} = {}(0)'.format(member_name, 'float'))
                    elif type(member_type.type) == Enum:
                        type_size += 4
                        print('    self.{} = int(0)  # {}'.format(member_name, member_type.type.name))
                    elif type(member_type.type) == Struct:
                        type_size += type_sizes[member_type.type.name]
                        print('    self.{} = {}()'.format(member_name, member_type.type.name))
                    else:
                        print('    # Skipped {} {} {}'.format(type(member_type.type), member_type.type.name, member_name))
                elif type(member_type) == ArrayDecl:
                    array_dim = int(member_type.dim.value)
                    print('    self.{} = str()  # {} bytes max'.format(member_name, array_dim))
            print()
            type_sizes[node_type.name] = type_size
        else:
            print('# Skipped object {}'.format(type(node_type)))

if __name__ == "__main__":
    main(sys.argv)