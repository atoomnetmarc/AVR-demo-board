/*

Copyright 2024 Marc Ketel
SPDX-License-Identifier: Apache-2.0

*/

#include <avr/io.h>
#include "define.h"

.global statemachine
statemachine:
    // Activate next game state
    mov game_state_current, game_state_next

game_state_start_begin:
    ldi temp1, GS_START
    cp temp1, game_state_current
    brne game_state_start_end

    // LED1=blue, LED2=blue
    in temp1, _SFR_IO_ADDR(LEDPIN)
    cbr temp1, _BV(LED1R) | _BV(LED1G) | _BV(LED1B) | _BV(LED2R) | _BV(LED2G) | _BV(LED2B)
    sbr temp1, _BV(LED1B) | _BV(LED2B)
    out _SFR_IO_ADDR(LEDPORT), temp1

    // temp1=rand(0, 40)
    ldi temp2, 45
    mov temp1, random
    rcall modulo

    // temp1+=10
    ldi temp2, 10
    add temp1, temp2

    // Set timer to some value between 5 and 50.
    mov game_timer, temp1

    // Set next game state
    ldi temp1, GS_WAIT
    mov game_state_next, temp1
game_state_start_end:

game_state_wait_begin:
    ldi temp1, GS_WAIT
    cp temp1, game_state_current
    brne game_state_wait_end

    // Are both button pressed?
detect_loose_both_begin:
    sbrs event, EV_BUTTON1
    rjmp detect_loose_both_end
    sbrs event, EV_BUTTON2
    rjmp detect_loose_both_end
    ldi temp1, GS_WIN_NOBODY
    mov game_state_next, temp1
    rjmp game_state_wait_end
detect_loose_both_end:

    // Is button 1 pressed?
detect_loose_player1_begin:
    sbrs event, EV_BUTTON1
    rjmp detect_loose_player1_end
    ldi temp1, GS_WIN_PLAYER2
    mov game_state_next, temp1
    rjmp game_state_wait_end
detect_loose_player1_end:

    // Is button 2 pressed?
detect_loose_player2_begin:
    sbrs event, EV_BUTTON2
    rjmp detect_loose_player2_end
    ldi temp1, GS_WIN_PLAYER1
    mov game_state_next, temp1
    rjmp game_state_wait_end
detect_loose_player2_end:

    // Set next game state when timer reaches 0
    tst game_timer
    brne game_state_wait_end
    ldi temp1, GS_LED_CHANGE
    mov game_state_next, temp1
game_state_wait_end:

game_state_led_change_begin:
    ldi temp1, GS_LED_CHANGE
    cp temp1, game_state_current
    brne game_state_led_change_end

    // LED1=off, LED2=off
    in temp1, _SFR_IO_ADDR(LEDPIN)
    cbr temp1, _BV(LED1R) | _BV(LED1G) | _BV(LED1B) | _BV(LED2R) | _BV(LED2G) | _BV(LED2B)
    out _SFR_IO_ADDR(LEDPORT), temp1

    // Set 5 second timer
    ldi temp1, 50
    mov game_timer, temp1

    // Set next game state
    ldi temp1, GS_PLAYER_WAIT
    mov game_state_next, temp1
game_state_led_change_end:

game_state_player_wait_begin:
    ldi temp1, GS_PLAYER_WAIT
    cp temp1, game_state_current
    brne game_state_player_wait_end

    // Are both button pressed?
detect_win_both_begin:
    sbrs event, EV_BUTTON1
    rjmp detect_win_both_end
    sbrs event, EV_BUTTON2
    rjmp detect_win_both_end
    ldi temp1, GS_WIN_BOTH
    mov game_state_next, temp1
    rjmp game_state_player_wait_end
detect_win_both_end:

    // Is button 1 pressed?
detect_win_player1_begin:
    sbrs event, EV_BUTTON1
    rjmp detect_win_player1_end
    ldi temp1, GS_WIN_PLAYER1
    mov game_state_next, temp1
    rjmp game_state_player_wait_end
detect_win_player1_end:

    // Is button 2 pressed?
detect_win_player2_begin:
    sbrs event, EV_BUTTON2
    rjmp detect_win_player2_end
    ldi temp1, GS_WIN_PLAYER2
    mov game_state_next, temp1
    rjmp game_state_player_wait_end
detect_win_player2_end:

    // Nobody wins when timer reaches 0
    tst game_timer
    brne game_state_player_wait_end
    ldi temp1, GS_WIN_NOBODY
    mov game_state_next, temp1
    rjmp game_state_player_wait_end
game_state_player_wait_end:

game_state_win_nobody_begin:
    ldi temp1, GS_WIN_NOBODY
    cp temp1, game_state_current
    brne game_state_win_nobody_end

    // LED1=red, LED2=red
    in temp1, _SFR_IO_ADDR(LEDPIN)
    cbr temp1, _BV(LED1R) | _BV(LED1G) | _BV(LED1B) | _BV(LED2R) | _BV(LED2G) | _BV(LED2B)
    sbr temp1, _BV(LED1R) | _BV(LED2R)
    out _SFR_IO_ADDR(LEDPORT), temp1

    // Set next game state
    ldi temp1, GS_END
    mov game_state_next, temp1
game_state_win_nobody_end:

game_state_win_player1_begin:
    ldi temp1, GS_WIN_PLAYER1
    cp temp1, game_state_current
    brne game_state_win_player1_end

    // LED1=green, LED2=red
    in temp1, _SFR_IO_ADDR(LEDPIN)
    cbr temp1, _BV(LED1R) | _BV(LED1G) | _BV(LED1B) | _BV(LED2R) | _BV(LED2G) | _BV(LED2B)
    sbr temp1, _BV(LED1G) | _BV(LED2R)
    out _SFR_IO_ADDR(LEDPORT), temp1

    // Set next game state
    ldi temp1, GS_END
    mov game_state_next, temp1
game_state_win_player1_end:

game_state_win_player2_begin:
    ldi temp1, GS_WIN_PLAYER2
    cp temp1, game_state_current
    brne game_state_win_player2_end

    // LED1=red, LED2=green
    in temp1, _SFR_IO_ADDR(LEDPIN)
    cbr temp1, _BV(LED1R) | _BV(LED1G) | _BV(LED1B) | _BV(LED2R) | _BV(LED2G) | _BV(LED2B)
    sbr temp1, _BV(LED1R) | _BV(LED2G)
    out _SFR_IO_ADDR(LEDPORT), temp1

    // Set next game state
    ldi temp1, GS_END
    mov game_state_next, temp1
game_state_win_player2_end:

game_state_win_both_begin:
    ldi temp1, GS_WIN_BOTH
    cp temp1, game_state_current
    brne game_state_win_both_end

    // LED1=green, LED2=green
    in temp1, _SFR_IO_ADDR(LEDPIN)
    cbr temp1, _BV(LED1R) | _BV(LED1G) | _BV(LED1B) | _BV(LED2R) | _BV(LED2G) | _BV(LED2B)
    sbr temp1, _BV(LED1G) | _BV(LED2G)
    out _SFR_IO_ADDR(LEDPORT), temp1

    // Set next game state
    ldi temp1, GS_END
    mov game_state_next, temp1
game_state_win_both_end:

game_state_end_begin:
    ldi temp1, GS_END
    cp temp1, game_state_current
    brne game_state_end_end

    // Set 2 second timer
    ldi temp1, 20
    mov game_timer, temp1

    // Set next game state
    ldi temp1, GS_END_WAIT
    mov game_state_next, temp1
game_state_end_end:

game_state_end_wait_begin:
    ldi temp1, GS_END_WAIT
    cp temp1, game_state_current
    brne game_state_end_wait_end

    // Set next game state when timer reaches 0
    tst game_timer
    brne game_state_end_wait_end
    ldi temp1, GS_START
    mov game_state_next, temp1
game_state_end_wait_end:

    ret