/*

Copyright 2021-2024 Marc Ketel
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

; ISR starts every 32.77 ms.
#if defined (__AVR_AT90S1200__) || defined (__AVR_ATtiny2313__)
.global TIMER0_OVF_vect
TIMER0_OVF_vect:
#elif defined (__AVR_AT90S2313__)
.global TIMER0_OVF0_vect
TIMER0_OVF0_vect:
#else
    #error Unknown MCU
#endif

    in S, _SFR_IO_ADDR(SREG)
    inc pause
    out _SFR_IO_ADDR(SREG), S
    reti

.global main
main:

#if defined (SP)
    ; Initialize stack pointer.
    ldi temp, lo8(RAMEND)
    out _SFR_IO_ADDR(SP), temp
#endif

#if defined (__AVR_ATtiny2313__)
    ; Configure clkdiv = 1
    ldi temp, _BV(CLKPCE)
    out _SFR_IO_ADDR(CLKPR), temp
    clr temp
    out _SFR_IO_ADDR(CLKPR), temp
#endif

    ; Timer clock = system clock / 1024
    ldi temp, _BV(CS02) | _BV(CS00)
#if defined (__AVR_AT90S1200__) || defined (__AVR_AT90S2313__)
    out _SFR_IO_ADDR(TCCR0), temp
#elif defined (__AVR_ATtiny2313__)
    out _SFR_IO_ADDR(TCCR0B), temp
#endif

    ; Clear TOV0/ clear pending interrupts.
    ldi temp, _BV(TOV0)
    out _SFR_IO_ADDR(TIFR), temp

    ; Enable Timer/Counter0 Overflow Interrupt.
    ldi temp, _BV(TOIE0)
    out _SFR_IO_ADDR(TIMSK), temp

    ; Many pins output.
    ldi temp, _BV(led1r) | _BV(led1g) | _BV(led1b) | _BV(led2r) | _BV(led2g) | _BV(led2b)
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
