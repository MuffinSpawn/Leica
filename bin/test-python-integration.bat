@echo off
SET SCRIPT_PATH=%~dp0
python -m unittest discover -v -s %SCRIPT_PATH%\..