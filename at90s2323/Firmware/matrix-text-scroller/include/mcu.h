/*

Copyright 2021 Marc Ketel
SPDX-License-Identifier: Apache-2.0

*/

#include <avr/io.h>

#if (defined(__AVR_AT90S2323__) || \
     defined(__AVR_AT90S2343__))

#define MCU_TIMER0_OVF_vect TIMER0_OVF0_vect
#define MCU_TCCR0 TCCR0

#elif (defined(__AVR_ATtiny25__) || \
       defined(__AVR_ATtiny45__) || \
       defined(__AVR_ATtiny85__))

#define MCU_TIMER0_OVF_vect TIM0_OVF_vect
#define MCU_TCCR0 TCCR0B

#else
#error "Unknown AVR model."
#endif