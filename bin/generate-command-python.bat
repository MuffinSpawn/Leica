rem @echo off
SET CURRENT_PATH=%cd%
SET SCRIPT_PATH=%~dp0
cd %SCRIPT_PATH%\..
python %SCRIPT_PATH%\pygen-command.py > %SCRIPT_PATH%\..\CESAPI\command.py
cd %CURRENT_PATH%
