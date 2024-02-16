/*

Copyright 2024 Marc Ketel
SPDX-License-Identifier: Apache-2.0

*/

#include <avr/io.h>
#include "define.h"

; Timer/Counter0 overflow handler.
#if defined (TIMER0_OVF_vect)
.global TIMER0_OVF_vect
TIMER0_OVF_vect:
#elif defined (TIMER0_OVF0_vect)
.global TIMER0_OVF0_vect
TIMER0_OVF0_vect:
#else
    #error I do not know the vector name for Timer/Counter0.
#endif

    // Set the timerdebug pin high
    sbi _SFR_IO_ADDR(TIMERDEBUGPORT), TIMERDEBUG

    // Save status register
    in isr_S, _SFR_IO_ADDR(SREG)

    // With prescaler on /64 this should result in a 1 millisecond overflow
    ldi isr_temp, 0x83
    out _SFR_IO_ADDR(TCNT0), isr_temp

    // Signal that 1 millisecond has passed
    sbr event, _BV(EV_1ms)

    // Increase millisecond counter
    inc isr_counter_1ms

    // Increase 100 millisecond counter
    inc isr_counter_100ms
    ldi isr_temp, 100
    cp isr_counter_100ms, isr_temp
    brne isr_counter_100ms_end
    clr isr_counter_100ms
    // Signal that 100 millisecond has passed
    sbr event, _BV(EV_100ms)
isr_counter_100ms_end:

    // Read all buttons at the same time
    in isr_temp, _SFR_IO_ADDR(BUTTONPIN)

    // Check if button 1 has been pressed
    sbrc isr_temp, BUTTON1
    rjmp button1_not_pressed
    sbrs isr_button, BUTTON1
    rjmp button1_still_pressed
    sbr event, _BV(EV_BUTTON1)
    mov random, isr_counter_1ms // Button press event generates random number
button1_not_pressed:
button1_still_pressed:

    // Check if button 2 has been pressed
    sbrc isr_temp, BUTTON2
    rjmp button2_not_pressed
    sbrs isr_button, BUTTON2
    rjmp button2_still_pressed
    sbr event, _BV(EV_BUTTON2)
    mov random, isr_counter_1ms // Button press event generates random number
button2_not_pressed:
button2_still_pressed:

    // Remember previous state of buttons
    mov isr_button, isr_temp

    // Restore status register
    out _SFR_IO_ADDR(SREG), isr_S

    // Set the timerdebug pin low
    cbi _SFR_IO_ADDR(TIMERDEBUGPORT), TIMERDEBUG
    reti