@echo off
SET script_path=%~dp0
python %script_path%\pygen.py %script_path%\..\Include\ES_C_API_Def_clean.h > %script_path%\..\CESAPI\packet.py