/*

Copyright 2021 Marc Ketel
SPDX-License-Identifier: Apache-2.0

*/

#include <avr/io.h>

#define led1r PB2
#define led1g PB3
#define led1b PB4

#define led2r PB5
#define led2g PB6
#define led2b PB7

#define S r0
#define pause r16
#define temp r22

; isr starts every 32.77 ms
.global TIMER0_OVF_vect
TIMER0_OVF_vect:
    in S, _SFR_IO_ADDR(SREG)
    inc pause
    out _SFR_IO_ADDR(SREG), S
    reti

.global main
main:
    ldi temp, (1<<CS02) | (1<<CS00) ; Timer clock = system clock / 1024
    out _SFR_IO_ADDR(TCCR0), temp
    ldi temp, 1<<TOV0
    out _SFR_IO_ADDR(TIFR), temp ; Clear TOV0/ clear pending interrupts

    ldi temp, 1<<TOIE0
    out _SFR_IO_ADDR(TIMSK), temp ; Enable Timer/Counter0 Overflow Interrupt

    ldi temp, (1<<led1r)|(1<<led1g)|(1<<led1b)|(1<<led2r)|(1<<led2g)|(1<<led2b)
    out _SFR_IO_ADDR(DDRB), temp

    sei
    rjmp loop

delay:
    tst pause
    breq delay
    ldi pause, 0x0
    ret

loop:

    sbi   _SFR_IO_ADDR(PORTB), led1r
    rcall delay
    cbi   _SFR_IO_ADDR(PORTB), led1r
    rcall delay

    sbi   _SFR_IO_ADDR(PORTB), led1g
    rcall delay
    cbi   _SFR_IO_ADDR(PORTB), led1g
    rcall delay

    sbi   _SFR_IO_ADDR(PORTB), led1b
    rcall delay
    cbi   _SFR_IO_ADDR(PORTB), led1b
    rcall delay

    sbi   _SFR_IO_ADDR(PORTB), led2r
    rcall delay
    cbi   _SFR_IO_ADDR(PORTB), led2r
    rcall delay

    sbi   _SFR_IO_ADDR(PORTB), led2g
    rcall delay
    cbi   _SFR_IO_ADDR(PORTB), led2g
    rcall delay

    sbi   _SFR_IO_ADDR(PORTB), led2b
    rcall delay
    cbi   _SFR_IO_ADDR(PORTB), led2b
    rcall delay

    rjmp	loop
