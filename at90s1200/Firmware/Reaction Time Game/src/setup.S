/*

Copyright 2024 Marc Ketel
SPDX-License-Identifier: Apache-2.0

*/

#include <avr/io.h>
#include "define.h"

.global setup
setup:
    clr event
    clr game_state_next
    clr isr_counter_1ms
    clr isr_counter_100ms

#if defined (CLKPR)
    // Configure clkdiv = 1
    ldi temp1, _BV(CLKPCE)
    out _SFR_IO_ADDR(CLKPR), temp1
    clr temp1
    out _SFR_IO_ADDR(CLKPR), temp1
#endif

    // Timer/Counter0 clock = system clock / 64
    ldi temp1, _BV(CS01) | _BV(CS00)
#if defined (TCCR0)
    out _SFR_IO_ADDR(TCCR0), temp1
#elif defined (TCCR0B)
    out _SFR_IO_ADDR(TCCR0B), temp1
#else
    #error I do not know how to configure Timer/Counter0.
#endif

    // Clear TOV0/ clear pending interrupts
    ldi temp1, _BV(TOV0)
    out _SFR_IO_ADDR(TIFR), temp1

    // Enable Timer/Counter0 overflow interrupt
    ldi temp1, _BV(TOIE0)
    out _SFR_IO_ADDR(TIMSK), temp1

    // Many pins as output
    in temp1, _SFR_IO_ADDR(LEDDDR)
    sbr temp1, _BV(LED1R) | _BV(LED1G) | _BV(LED1B) | _BV(LED2R) | _BV(LED2G) | _BV(LED2B)
    out _SFR_IO_ADDR(LEDDDR), temp1

    sbi _SFR_IO_ADDR(LOOPDEBUGDDR), LOOPDEBUG
    sbi _SFR_IO_ADDR(TIMERDEBUGDDR), TIMERDEBUG

    // Some pins input with pull-up
    sbi _SFR_IO_ADDR(BUTTONPORT), BUTTON1
    sbi _SFR_IO_ADDR(BUTTONPORT), BUTTON2

    /// Enable interrupts
    sei
    ret