#!/bin/bash

CURRENT_DIR=$(pwd)
SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
cd $SCRIPT_DIR/..
python ${SCRIPT_DIR}/pygen-command.py > ${SCRIPT_DIR}/../CESAPI/command.py
cd $CURRENT_DIR
