# But why?

This document tries to group mostly similar AVR devices in tables. In this document each device table has some vintage AT90S* (DIP) part as the first ancestor and all the serial programmable known pin-compatible more recent parts.

**Bold** introduces new function, move or name change for a pin.

# 8-pin

| Model         | Flash | RAM   | EEPROM    | Fmax      | Instructions  | Available since   |
| --            | --:   | --:   | --:       | --:       | --:           | --                |
| AT90S2323     |    2K |  128B |      128B |     10MHz |           118 | 1999              |
| AT90S2343     |    2K |  128B |      128B |     10MHz |           118 | 1999              |
| ATtiny12      |    1K |     - |       64B |      8MHz |            90 | 1999              |
| ATtiny15L     |    1K |     - |       64B |    1.6MHz |            90 | 2000              |
| ATtiny22L     |    2K |  128B |      128B |      1MHz |           118 | 2000              |
| ATtiny13      |    1K |   64B |       64B |     20MHz |           120 | 2004              |
| ATtiny25      |    2K |  128B |      128B |     20MHz |           120 | 2006              |
| ATtiny45      |    4K |  256B |      256B |     20MHz |           120 | 2006              |
| ATtiny85      |    8K |  512B |      512B |     20MHz |           120 | 2006              |
| ATtiny13A     |    1K |   64B |       64B |     20MHz |           120 | 2008              |

| Pin   | Common            | AT90S2323 | ATtiny22L | AT90S2343         | ATtiny12          | ATtiny15L             | ATtiny13<br />ATtiny13A           | ATtiny25<br />ATtiny45<br />ATtiny85          |
| --:   | --                | --        | --        | --                | --                | --                    | --                                | --                                            |
| 1     | RESET             |           |           |                   | **PB5**           | PB5, **ADC0**         | PB5, **dW**, ADC0, **PCINT5**     | PB5, dW, ADC0, PCINT5                         |
| 2     | -                 | **XTAL1** | **PB3**   | PB3, **CLOCK**    | PB3, XTAL1        | **PB4**, **ADC3**     | PB3, ADC3, **CLKI**, **PCINT3**   | PB3, ADC3, **OC1B**, CLKI, XTAL1, PCINT3      |
| 3     | -                 | **XTAL2** | **PB4**   | PB4               | PB4, XTAL2        | **PB3**, **ADC2**     | PB4, ADC2, **PCINT4**             | PB4, ADC2, **OC1B**, XTAL2, PCINT4            |
| 4     | GND               |           |           |                   |                   |                       |                                   |                                               |
| 5     | PB0, MOSI         |           |           |                   | **AIN0**          | AIN0, **AREF**        | AIN0, **OC0A**, **PCINT0**        | **DI**, **SDA**, AIN0, OC0A, **AREF**, PCINT0 |
| 6     | PB1, MISO         | **INT0**  | INT0      | INT0              | **AIN1**, INT0    | AIN1, **OC1A**        | AIN1, **OC0B**, INT0, **PCINT1**  | **DO**, AIN1, OC0B, **OC1A**, PCINT1          |
| 7     | PB2, SCK, T0      |           |           |                   |                   | **ADC1**, **INT0**    | ADC1, **PCINT2**                  | **USCK**, **SCL**, ADC1, **INT0**, PCINT2     |
| 8     | VCC               |           |           |                   |                   |                       |                                   |                                               |

# 20-pin

| Model         | Flash | RAM   | EEPROM    | Fmax  | Instructions  | Available since   |
| --            | --:   | --:   | --:       | --:   | --:           | --                |
| AT90S1200     | 1K    | -     | 64B       | 12MHz | 89            | 1997              |
| AT90S1300     | 1K    | -     | 128B      | 24MHz | 83            | N/A               |
| AT90S2313     | 2K    | 128B  | 128B      | 10MHz | 118           | 1998              |
| ATtiny2313    | 2K    | 128B  | 128B      | 20MHz | 120           | 2003              |
| ATtiny2313A   | 2K    | 128B  | 128B      | 20MHz | 120           | 2011              |
| ATtiny4313    | 4K    | 256B  | 256B      | 20MHz | 120           | 2011              |

| Pin   | Common    | AT90S1200 | AT90S2313 | ATtiny2313                    | ATtiny2313A<br />ATtiny4313   |
| --:   | --        | --        | --        | --                            | --                            |
| 1     | RESET     |           |           | **PA2**, **dW**               | PA2, dW, **PCINT10**          |
| 2     | PD0       |           | **RXD**   | RXD                           | RXD, **PCINT11**              |
| 3     | PD1       |           | **TXD**   | TXD                           | TXD, **PCINT12**              |
| 4     | XTAL2     |           |           |                               | **PA1**, **PCINT9**           |
| 5     | XTAL1     |           |           |                               | **PA0**, **PCINT8**           |
| 6     | PD2, INT0 |           |           | **XCK**, **CKOUT**            | XCK, CKOUT, **PCINT13**       |
| 7     | PD3       |           | **INT1**  | INT1                          | INT1, **PCINT14**             |
| 8     | PD4, T0   |           |           |                               | **PCINT15**                   |
| 9     | PD5       |           | **T1**    | T1, **OC0B**                  | T1, OC0B, **PCINT16**         |
| 10    | GND       |           |           |                               |                               |
| 11    | PD6       |           | **ICP**   | ICP                           | **ICPI**, **PCINT17**         |
| 12    | PB0, AIN0 |           |           | **PCINT0**                    | PCINT0                        |
| 13    | PB1, AIN1 |           |           |  **PCINT1**                   | PCINT1                        |
| 14    | PB2       |           |           | **OC0A**, **PCINT2**          | OC0A, PCINT2                  |
| 15    | PB3       |           | OC1       | **OC1A**, **PCINT3**          | OC1A, PCINT3                  |
| 16    | PB4       |           |           | **OC1B**, **PCINT4**          | OC1B, PCINT4                  |
| 17    | PB5, MOSI |           |           | **DI**, **SDA**, **PCINT5**   | DI, SDA, PCINT5               |
| 18    | PB6, MISO |           |           | **DO**, **PCINT6**            | DO, PCINT6                    |
| 19    | PB7, SCK  |           |           | **USCK**, **PCINT7**          | USCK, **SCL**, PCINT7         |
| 20    | VCC       |           |           |                               |                               |

# 28-pin

| Model         | Flash | RAM       | EEPROM    | Fmax  | Instructions  | Available since   |
| --            | --:   | --:       | --:       | --:   | --:           | --                |
| AT90S2333     | 2K    | 128B      | 128B      | 8MHz  | 118           | 1999              |
| AT90S4433     | 4K    | 128B      | 256B      | 8MHz  | 118           | 1999              |
| ATmega8       | 8K    | 1024B     | 512B      | 16MHz | 130           | 2002              |
| ATmega48      | 4K    | 512B      | 256B      | 20MHz | 131           | 2004              |
| ATmega88      | 8K    | 1024B     | 512B      | 20MHz | 131           | 2004              |
| ATmega168     | 16K   | 1024B     | 512B      | 20MHz | 131           | 2004              |
| ATtiny48      | 4K    | 256B      | 64B       | 12MHz | 123           | 2008              |
| ATtiny88      | 8K    | 512B      | 64B       | 12MHz | 123           | 2008              |
| ATmega328     | 32K   | 2048B     | 1024B     | 20MHz | 131           | 2009              |


| Pin   | Common    | AT90S2333<br /> AT90S4433 | ATmega8           | ATtiny48<br /> ATtiny88       | ATmega48<br />ATmega88<br />ATmega168<br />ATmega328  |
| --:   | --        | --                        | --                | --                            | --                                                    |
| 1     | RESET     |                           | **PC6**           | PC6, **PCINT14**, **dW**      | PC6, PCINT14, dW                                      |
| 2     | PD0       | **RXD**                   | RXD               | **PCINT16**                   | RXD, PCINT16                                          |
| 3     | PD1       | **TXD**                   | TXD               | **PCINT17**                   | TXD, PCINT17                                          |
| 4     | PD2, INT0 |                           |                   | **PCINT18**                   | PCINT18                                               |
| 5     | PD3, INT1 |                           |                   | **PCINT19**                   | **OC2B**, PCINT19                                     |
| 6     | PD4, T0   |                           | **XCK**           | **PCINT20**                   | XCK, PCINT20                                          |
| 7     | VCC       |                           |                   |                               |                                                       |
| 8     | GND       |                           |                   |                               |                                                       |
| 9     | -         | **XTAL1**                 | **TOSC1**, XTAL1  | **PB6**, **CLKI**, **PCINT6** | TOSC1, XTAL1, PCINT6                                  |
| 10    | -         | **XTAL2**                 | **TOSC2**, XTAL2  | **PB7**, **PCINT7**           | TOSC2, XTAL2, PCINT7                                  |
| 11    | PD5, T1   |                           |                   | **PCINT21**                   | **OC0B**, PCINT21                                     |
| 12    | PD6, AIN0 |                           |                   | **PCINT22**                   | **OC0A**, PCINT22                                     |
| 13    | PD7, AIN1 |                           |                   | **PCINT23**                   | PCINT23                                               |
| 14    | PB0       | **ICP**                   | **ICP1**          | ICP1, **CLKO**, **PCINT0**    | ICP1, CLKO, PCINT0                                    |
| 15    | PB1       | **OC1**                   | **OC1A**          | OC1A, **PCINT1**              | OC1A, PCINT1                                          |
| 16    | PB2, SS   |                           | **OC1B**          | OC1B, **PCINT2**              | OC1B, PCINT2                                          |
| 17    | PB3, MOSI |                           | **OC2**           | **PCINT3**                    | PCINT3                                                |
| 18    | PB4, MISO |                           |                   | **PCINT4**                    | PCINT4                                                |
| 19    | PB5, SCK  |                           |                   | **PCINT5**                    | PCINT5                                                |
| 20    | AVCC      |                           |                   |                               |                                                       |
| 21    | -         | **AREF**                  | AREF              | **PC7**, **PCINT15**          | AREF                                                  |
| 22    | -         | **AGND**                  | GND               | **GND**                       | GND                                                   |
| 23    | PC0, ADC0 |                           |                   | **PCINT8**                    | PCINT8                                                |
| 24    | PC1, ADC1 |                           |                   | **PCINT9**                    | PCINT9                                                |
| 25    | PC2, ADC2 |                           |                   | **PCINT10**                   | PCINT10                                               |
| 26    | PC3, ADC3 |                           |                   | **PCINT11**                   | PCINT11                                               |
| 27    | PC4, ADC4 |                           | **SDA**           | SDA, **PCINT12**              | SDA, PCINT12                                          |
| 28    | PC5, ADC5 |                           | **SCL**           | SCL, **PCINT13**              | SCL, PCINT13                                          |

# 40-pin

| Model         | Flash | RAM       | EEPROM    | Fmax  | Instructions  | Available since   |
| --            | --:   | --:       | --:       | --:   | --:           | --                |
| AT90S4414     | 4K    | 256B      | 256B      | 8MHz  | 118           | 1999              |
| AT90S8515     | 8K    | 512B      | 512B      | 8MHz  | 118           | 1999              |
| ATmega8515    | 8K    | 512B      | 512B      | 16MHz | 130           | 2002              |
| ATmega161     | 16K   | 1024B     | 512B      | 8MHz  | 130           | 2002              |
| ATmega162     | 16K   | 1024B     | 512B      | 16MHz | 131           | 2002              |

| Pin   | Common    | AT90S8414<br />AT90S8515  | ATmega8515        | ATmega161 | ATmega162                     |
| --:   | --        | --                        | --                | --        | --                            |
| 1     | PB0, T0   |                           | **OC0**           | OC0       | OC0                           |
| 2     | PB1, T1   |                           |                   | **OC2**   | OC2                           |
| 3     | PB2, AIN0 |                           |                   | **RXD1**  | RXD1                          |
| 4     | PB3, AIN1 |                           |                   | **TXD1**  | TXD1                          |
| 5     | PB4, SS   |                           |                   |           | **OC3B**                      |
| 6     | PB5, MOSI |                           |                   |           |                               |
| 7     | PB6, MISO |                           |                   |           |                               |
| 8     | PB7, SCK  |                           |                   |           |                               |
| 9     | RESET     |                           |                   |           |                               |
| 10    | PD0, RXD  |                           |                   | **RXD0**  | RXD0                          |
| 11    | PD1, TXD  |                           |                   | **TXD0**  | TXD0                          |
| 12    | PD2, INT0 |                           |                   |           | **XCK1**                      |
| 13    | PD3, INT1 |                           |                   |           | **ICP3**                      |
| 14    | PD4       |                           | **XCK**           | **TOSC1** | **OSC3A**, **XCK0**, TOSC1    |
| 15    | PD5, OC1A |                           |                   | **TOSC2** | TOSC2                         |
| 16    | PD6, WR   |                           |                   |           |                               |
| 17    | PD7, WD   |                           |                   |           |                               |
| 18    | XTAL2     |                           |                   |           |                               |
| 19    | XTAL1     |                           |                   |           |                               |
| 20    | GND       |                           |                   |           |                               |
| 21    | PC0, A8   |                           |                   |           | **PCINT8**                    |
| 22    | PC1, A9   |                           |                   |           | **PCINT9**                    |
| 23    | PC2, A10  |                           |                   |           | **PCINT10**                   |
| 24    | PC3, A11  |                           |                   |           | **PCINT11**                   |
| 25    | PC4, A12  |                           |                   |           | **TCK**, **PCINT12**          |
| 26    | PC5, A13  |                           |                   |           | **TMS**, **PCINT13**          |
| 27    | PC6, A14  |                           |                   |           | **TDO**, **PCINT14**          |
| 28    | PC7, A15  |                           |                   |           | **TDI**, **PCINT15**          |
| 29    | OC1B      |                           | **PE2**, **OC1B** | PE2, OC1B | PE2, OC1B                     |
| 30    | ALE       |                           | **PE1**           | PE1       | PE1                           |
| 31    | ICP       |                           | **PE0**, **INT2** | PE0, INT2 | PE0, **ICP1**, INT2           |
| 32    | PA7, AD7  |                           |                   |           | **PCINT7**                    |
| 33    | PA6, AD6  |                           |                   |           | **PCINT6**                    |
| 34    | PA5, AD5  |                           |                   |           | **PCINT5**                    |
| 35    | PA4, AD4  |                           |                   |           | **PCINT4**                    |
| 36    | PA3, AD3  |                           |                   |           | **PCINT3**                    |
| 37    | PA2, AD2  |                           |                   |           | **PCINT2**                    |
| 38    | PA1, AD1  |                           |                   |           | **PCINT1**                    |
| 39    | PA0, AD0  |                           |                   |           | **PCINT0**                    |
| 40    | VCC       |                           |                   |           |                               |

| Model         | Flash | RAM       | EEPROM    | Fmax  | Instructions  | Available since   |
| --            | --:   | --:       | --:       | --:   | --:           | --                |
| AT90S4434     | 4K    | 256B      | 256B      | 8MHz  | 118           | 1999              |
| AT90S8535     | 8K    | 512B      | 512B      | 8MHz  | 118           | 1999              |
| ATmega8535    | 8K    | 512B      | 512B      | 16MHz | 130           | 2001              |
| ATmega163     | 16K   | 1024B     | 512B      | 8MHz  | 130           | 2001              |
| ATmega323     | 32K   | 2048B     | 1024B     | 8MHz  | 130           | 2001              |
| ATmega16      | 16K   | 1024B     | 512B      | 16MHz | 131           | 2002              |
| ATmega32      | 32K   | 2048B     | 1024B     | 16MHz | 131           | 2002              |
| ATmega644     | 64K   | 4096B     | 2048B     | 20MHz | 131           | 2006              |
| ATmega1284    | 128K  | 16384B    | 4096B     | 20MHz | 131           | 2008              |
| ATmega164     | 16K   | 1024B     | 512B      | 20MHz | 131           | 2010              |
| ATmega324     | 32K   | 2048B     | 1024B     | 20MHz | 131           | 2010              |

| Pin   | Common        | AT90S4434<br />AT90S8535  | ATmega163         | ATmega323<br />ATmega16<br />ATmega32 | ATmega644             | ATmega164P<br />ATmega324P<br />ATmega644P    | ATmega164(P)A<br />ATmega324(P)A<br />ATmega644(P)A<br />ATmega1284(P)    |
| --:   | --            | --                        | --                | --                                    | --                    | --                                            | --                                                                        |
| 1     | PB0, T0       |                           |                   | **XCK**                               | **XCK0**, **PCINT8**  | XCK0, PCINT8                                  | XCK0, PCINT8
| 2     | PB1, T1       |                           |                   |                                       | **CLKO**, **PCINT9**  | CLKO, PCINT9                                  | CLKO, PCINT9
| 3     | PB2, AIN0     |                           |                   | **INT2**                              | INT2, **PCINT10**     | INT2, PCINT10                                 | INT2, PCINT10
| 4     | PB3, AIN1     |                           |                   | **OC0**                               | **OC0A**, **PCINT11** | OC0A, PCINT11                                 | OC0A, PCINT11
| 5     | PB4, SS       |                           |                   |                                       | **OC0B**, **PCINT12** | OC0B, PCINT12                                 | OC0B, PCINT12
| 6     | PB5, MOSI     |                           |                   |                                       | **PCINT13**           | PCINT13                                       | **ICP3**, PCINT13
| 7     | PB6, MISO     |                           |                   |                                       | **PCINT14**           | PCINT14                                       | **OC3A**, PCINT14
| 8     | PB7, SCK      |                           |                   |                                       | **PCINT15**           | PCINT15                                       | **OC3B**, PCINT15
| 9     | RESET         |                           |                   |                                       |                       |                                               |
| 10    | VCC           |                           |                   |                                       |                       |                                               |
| 11    | GND           |                           |                   |                                       |                       |                                               |
| 12    | XTAL2         |                           |                   |                                       |                       |                                               |
| 13    | XTAL1         |                           |                   |                                       |                       |                                               |
| 14    | PD0, RXD      |                           |                   |                                       | **RXD0**, **PCINT24** | RXD0, PCINT24                                 | **T3**, RXD0, PCINT24
| 15    | PD1, TXD      |                           |                   |                                       | **TXD0**, **PCINT25** | TXD0, PCINT25                                 | TXD0, PCINT25
| 16    | PD2, INT0     |                           |                   |                                       | **PCINT26**           | **RXD1**, PCINT26                             | RXD1, PCINT26
| 17    | PD3, INT1     |                           |                   |                                       | **PCINT27**           | **TXD1**, PCINT27                             | TXD1, PCINT27
| 18    | PD4, OC1B     |                           |                   |                                       | **PCINT28**           | **XCK1**, PCINT28                             | XCK1, PCINT28
| 19    | PD5, OC1A     |                           |                   |                                       | **PCINT29**           | PCINT29                                       | PCINT29
| 20    | PD6, ICP      |                           |                   |                                       | **OC2B**, **PCINT30** | OC2B, PCINT30                                 | OC2B, PCINT30
| 21    | PD7, OC2      |                           |                   |                                       | **OC2A**, **PCINT31** | OC2A, PCINT31                                 | OC2A, PCINT31
| 22    | PC0           |                           | **SCL**           | SCL                                   | SCL, **PCINT16**      | SCL, PCINT16                                  | SCL, PCINT16
| 23    | PC1           |                           | **SDA**           | SDA                                   | SDA, **PCINT17**      | SDA, PCINT17                                  | SDA, PCINT17
| 24    | PC2           |                           |                   | **TCK**                               | TCK, **PCINT18**      | TCK, PCINT18                                  | TCK, PCINT18
| 25    | PC3           |                           |                   | **TMS**                               | TMS, **PCINT19**      | TMS, PCINT19                                  | TMS, PCINT19
| 26    | PC4           |                           |                   | **TDO**                               | TDO, **PCINT20**      | TDO, PCINT20                                  | TDO, PCINT20
| 27    | PC5           |                           |                   | **TDI**                               | TDI, **PCINT21**      | TDI, PCINT21                                  | TDI, PCINT21
| 28    | PC6, TOSC1    |                           |                   |                                       | **PCINT22**           | PCINT22                                       | PCINT22
| 29    | PC7, TOSC2    |                           |                   |                                       | **PCINT23**           | PCINT23                                       | PCINT23
| 30    | AVCC          |                           |                   |                                       |                       |                                               |
| 31    | AGND          |                           |                   |                                       |                       |                                               |
| 32    | AREF          |                           |                   |                                       |                       |                                               |
| 33    | PA7, ADC7     |                           |                   |                                       | **PCINT7**            | PCINT7                                        | PCINT7
| 34    | PA6, ADC6     |                           |                   |                                       | **PCINT6**            | PCINT6                                        | PCINT6
| 35    | PA5, ADC5     |                           |                   |                                       | **PCINT5**            | PCINT5                                        | PCINT5
| 36    | PA4, ADC4     |                           |                   |                                       | **PCINT4**            | PCINT4                                        | PCINT4
| 37    | PA3, ADC3     |                           |                   |                                       | **PCINT3**            | PCINT3                                        | PCINT3
| 38    | PA2, ADC2     |                           |                   |                                       | **PCINT2**            | PCINT2                                        | PCINT2
| 39    | PA1, ADC1     |                           |                   |                                       | **PCINT1**            | PCINT1                                        | PCINT1
| 40    | PA0, ADC0     |                           |                   |                                       | **PCINT0**            | PCINT0                                        | PCINT0

[![License](https://img.shields.io/badge/License-Apache%202.0-blue.svg)](https://opensource.org/licenses/Apache-2.0)
