@echo off
SET SCRIPT_PATH=%~dp0
python %SCRIPT_PATH%\pygen-packet.py %SCRIPT_PATH%\..\Include\ES_C_API_Def_clean.h > %SCRIPT_PATH%\..\CESAPI\packet.py
