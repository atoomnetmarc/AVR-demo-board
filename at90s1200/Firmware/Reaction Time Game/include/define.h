/*

Copyright 2024 Marc Ketel
SPDX-License-Identifier: Apache-2.0

*/

#ifndef define_H
#define define_H

#define LEDPORT PORTB
#define LEDPIN  PINB
#define LEDDDR  DDRB
#define LED1R   PB2
#define LED1G   PB3
#define LED1B   PB4
#define LED2R   PB5
#define LED2G   PB6
#define LED2B   PB7

#define BUTTONDDR DDRD
#define BUTTONPORT PORTD
#define BUTTONPIN PIND
#define BUTTON1 PD2
#define BUTTON2 PD3

#define LOOPDEBUGDDR  DDRD
#define LOOPDEBUGPORT PORTD
#define LOOPDEBUG     PD0

#define TIMERDEBUGDDR  DDRD
#define TIMERDEBUGPORT PORTD
#define TIMERDEBUG     PD1

// Registers shared by ISR and program.
#define event r16
#define random r0

// Registers used by program.
#define temp1 r17
#define temp2 r18
#define game_state_current r1
#define game_state_next r2
#define game_timer r3

// Registers used by ISR.
#define isr_S r4
#define isr_temp r19
#define isr_button r20
#define isr_counter_1ms r5
#define isr_counter_100ms r6

// List of events that could happen at the same time in the event register.
#define EV_1ms 0
#define EV_100ms 1
#define EV_BUTTON1 2
#define EV_BUTTON2 3

// List of game states
#define GS_START 0
#define GS_WAIT 1
#define GS_LED_CHANGE 2
#define GS_PLAYER_WAIT 3
#define GS_WIN_NOBODY 4
#define GS_WIN_PLAYER1 5
#define GS_WIN_PLAYER2 6
#define GS_WIN_BOTH 7
#define GS_END 8
#define GS_END_WAIT 9

#endif