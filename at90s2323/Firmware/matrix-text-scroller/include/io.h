/*

Copyright 2021 Marc Ketel
SPDX-License-Identifier: Apache-2.0

*/

#include <avr/io.h>

//Access bits like variables
struct _io_reg
{
    uint8_t b0 : 1;
    uint8_t b1 : 1;
    uint8_t b2 : 1;
    uint8_t b3 : 1;
    uint8_t b4 : 1;
    uint8_t b5 : 1;
    uint8_t b6 : 1;
    uint8_t b7 : 1;
};

#define REGISTER_BIT(port, pin) ((*(volatile struct _io_reg *)&port).b##pin)

//Hardware definitions
#define DATA REGISTER_BIT(PORTB, 1)
#define DATA_DDR REGISTER_BIT(DDRB, 1)
#define SCK REGISTER_BIT(PORTB, 2)
#define SCK_DDR REGISTER_BIT(DDRB, 2)
#define OE REGISTER_BIT(PORTB, 0)
#define OE_DDR REGISTER_BIT(DDRB, 0)

