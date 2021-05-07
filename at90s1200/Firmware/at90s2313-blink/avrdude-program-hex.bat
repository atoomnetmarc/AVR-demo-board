set HEXFILE=at90s2313-blink.hex
set PROGRAMMER=arduino
set COMPORT=COM2

REM program flash
avrdude -u -c %PROGRAMMER% -p 2313 -P %COMPORT% -b 19200 -U flash:w:"%HEXFILE%":i
