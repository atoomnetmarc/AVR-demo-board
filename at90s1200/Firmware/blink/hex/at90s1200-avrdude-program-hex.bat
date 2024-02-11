set HEXFILE=at90s1200.hex
set PROGRAMMER=arduino
set COMPORT=COM2

REM chip erase
avrdude -c %PROGRAMMER% -P %COMPORT% -p 1200 -b 19200 -e

REM program flash
avrdude -c %PROGRAMMER% -P %COMPORT% -p 1200 -b 19200 -D -U flash:w:"%HEXFILE%":i
