/*

Copyright 2024 Marc Ketel
SPDX-License-Identifier: Apache-2.0

*/

#include <avr/io.h>
#include "define.h"

.global main
main:
    rcall setup
    rjmp loop

loop:
    // Set the loopdebug pin low
    cbi _SFR_IO_ADDR(LOOPDEBUGPORT), LOOPDEBUG

wait_for_event:
    // Wait until some event occurs
    tst event
    breq wait_for_event
    // Set the loopdebug pin high
    sbi _SFR_IO_ADDR(LOOPDEBUGPORT), LOOPDEBUG

    rcall statemachine

event_handler_1ms_begin:
    sbrs event, EV_1ms
    rjmp event_handler_1ms_end
    cbr event, _BV(EV_1ms)
event_handler_1ms_end:

event_handler_100ms_begin:
    sbrs event, EV_100ms
    rjmp event_handler_100ms_end
    cbr event, _BV(EV_100ms)

    // Decrease game timer
    tst game_timer
    breq decrease_game_timer_end
    dec game_timer
decrease_game_timer_end:
event_handler_100ms_end:

event_handler_button1_begin:
    sbrs event, EV_BUTTON1
    rjmp event_handler_button1_end
    cbr event, _BV(EV_BUTTON1)
event_handler_button1_end:

event_handler_button2_begin:
    sbrs event, EV_BUTTON2
    rjmp event_handler_button2_end
    cbr event, _BV(EV_BUTTON2)
event_handler_button2_end:

    rjmp	loop
