@echo off
make clean
make sync
make all

@REM (
@REM     echo                     Building Process [SUCCESS]
@REM     echo                     ----------------------------
@REM ) > temp.txt

@REM msg * < temp.txt
@REM del temp.txt

pause
