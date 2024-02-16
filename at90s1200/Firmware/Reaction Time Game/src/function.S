/*

Copyright 2024 Marc Ketel
SPDX-License-Identifier: Apache-2.0

*/

#include "define.h"

.global modulo
modulo:
    /*
    Modulo function.

    temp1 = temp1 % temp2

    Parameter temp1: the value you want the modulus of
    Parameter temp2: the value you want to use when calculating the modulus.
    Returns temp1.

    */
modulo_loop:
    cp temp2, temp1
    brsh modulo_end
    sub temp1, temp2
    rjmp modulo_loop
modulo_end:
    ret