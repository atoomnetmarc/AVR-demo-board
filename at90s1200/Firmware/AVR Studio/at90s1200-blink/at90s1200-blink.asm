/*

Copyright 2021 Marc Ketel
SPDX-License-Identifier: Apache-2.0

*/

.include "1200def.inc"

.equ led1r = PORTB2
.equ led1g = PORTB3
.equ led1b = PORTB4

.equ led2r = PORTB5
.equ led2g = PORTB6
.equ led2b = PORTB7

.def S     = R0
.def pause = R16
.def temp  = R22

.cseg
.org 	$0000
	rjmp setup
.org	OVF0addr			; Timer/Counter0 Overflow
	rjmp ISR_TOV0

; isr starts every 32.77 ms
ISR_TOV0:
	in S,sreg
	inc pause
	out sreg,S
	reti

setup:
	ldi temp, (1<<CS02) | (1<<CS00) ; Timer clock = system clock / 1024
	out TCCR0, temp
	ldi temp, 1<<TOV0
	out TIFR, temp ; Clear TOV0/ clear pending interrupts
	ldi temp, 1<<TOIE0
	out TIMSK, temp ; Enable Timer/Counter0 Overflow Interrupt

	ldi temp, (1<<led1r)|(1<<led1g)|(1<<led1b)|(1<<led2r)|(1<<led2g)|(1<<led2b)
	out DDRB, temp

	sei
	rjmp loop

delay:
	tst pause
 	breq delay
	ldi pause, 0x0
	ret

loop:

	sbi   PORTB, led1r
	rcall delay
	cbi   PORTB, led1r
	rcall delay

	sbi   PORTB, led1g
	rcall delay
	cbi   PORTB, led1g
	rcall delay

	sbi   PORTB, led1b
	rcall delay
	cbi   PORTB, led1b
	rcall delay

	sbi   PORTB, led2r
	rcall delay
	cbi   PORTB, led2r
	rcall delay

	sbi   PORTB, led2g
	rcall delay
	cbi   PORTB, led2g
	rcall delay

	sbi   PORTB, led2b
	rcall delay
	cbi   PORTB, led2b
	rcall delay

	rjmp	loop
