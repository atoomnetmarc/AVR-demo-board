set HEXFILE=at90s1200.hex
set PROGRAMMER=arduino
set COMPORT=COM2

REM chip erase
avrdude -u -c %PROGRAMMER% -p 1200 -P %COMPORT% -b 19200 -e

REM program flash
avrdude -u -c %PROGRAMMER% -p 1200 -P %COMPORT% -b 19200 -D -U flash:w:"%HEXFILE%":i
