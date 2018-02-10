#!/bin/bash

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
python ${SCRIPT_DIR}/pygen-packet.py ${SCRIPT_DIR}/../Include/ES_C_API_Def_clean.h > ${SCRIPT_DIR}/../CESAPI/packet.py
