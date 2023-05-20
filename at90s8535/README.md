# MightyCore

You could use [MightyCore](https://github.com/MCUdude/MightyCore) to program a supported MCU (ATmega8535, ATmega16, ATmega32, ATmega164, ATmega324, ATmega644 and ATmega1284) using Arduino IDE or PlatformIO.

To be useful as an Arduino board, you must first burn a bootloader using the Arduino IDE. Use the instructions from the [MightyCore GitHub page](https://github.com/MCUdude/MightyCore) to burn the bootloader.

Verify the bootloader burn by compiling the blink sketch and uploading it to the board using the [USB UART PMOD](https://github.com/atoomnetmarc/PMOD-USB-UART) (or your own compatible serial cable). After uploading LED D8 should blink.

# AT90S4434 or AT90S8535

These old MCUs do not have bootloader capability and are not supported by [MightyCore](https://github.com/MCUdude/MightyCore). Program these with a AVR programmer connected to the ISP header.

# ATmega163 or ATmega323

The ATmega163 and ATmega323 are also not supported by [MightyCore](https://github.com/MCUdude/MightyCore). These MCUs do contain bootloader capability but are not supported by [Optiboot](https://github.com/Optiboot/optiboot).

At this moment (2023-05) you can program these just like the AT90S8535 using the ISP header.
