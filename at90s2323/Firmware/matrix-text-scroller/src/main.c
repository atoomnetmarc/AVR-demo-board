/*

Copyright 2021 Marc Ketel
SPDX-License-Identifier: Apache-2.0

*/

#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/wdt.h>

#include <util/delay.h>

#include "io.h"
#include "main.h"
#include "mcu.h"
#include "scroll.h"
#include "shift.h"

//array representing the 16x8 LED matrix
volatile uint8_t matrix[MATRIX_WIDTH];

#define EV_1MS 1
volatile uint8_t event = 0;

void setup(void)
{
    //Enable watchdog
    wdt_enable(WDTO_500MS);

    //All IO is output.
    DATA_DDR = 1;
    SCK_DDR = 1;
    OE_DDR = 1;

    //Configure timer0
    MCU_TCCR0 |= _BV(CS00) | _BV(CS01); //clk/64
    TIMSK |= _BV(TOIE0);

    //Enable interrupts
    sei();
}

ISR(MCU_TIMER0_OVF_vect)
{
    uint8_t clkdiv = 64;
    uint16_t timerHz = 1000;
    TCNT0 = 256 - (F_CPU / clkdiv / timerHz);

    //Output to LED matrix
    shift();

    //Signal that 1ms has passed.
    event |= EV_1MS;
}

void loop(void)
{
    wdt_reset();

    while (event == 0)
    {
        //Intensively do nothing while waiting for some event.
    }

    if (event & EV_1MS)
    {
        event &= ~EV_1MS;

        scrollLoop();
    }
}

__attribute__((OS_main)) int main(void)
{
    setup();

    for (;;)
    {
        loop();
    }
}
