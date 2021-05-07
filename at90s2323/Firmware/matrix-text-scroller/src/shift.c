/*

Copyright 2021 Marc Ketel
SPDX-License-Identifier: Apache-2.0

*/

#include <avr/io.h>

#include "io.h"
#include "main.h"

void shift(void)
{
    static int8_t currentrow = 7;

    //Switch off output
    OE = 1;

    //Shift out columns
    for (int8_t column = sizeof(matrix) - 1; column >= 0; column--)
    {
        if (matrix[column] & _BV(currentrow))
            DATA = 1;
        else
            DATA = 0;

        SCK = 1;
        SCK = 0;
    }

    //Shift out current row
    for (int8_t row = 7; row >= 0; row--)
    {
        if (row == currentrow)
            DATA = 1;
        else
            DATA = 0;

        SCK = 1;
        SCK = 0;
    }

    //Strobe latch;
    OE = 0;
    OE = 1;

    //Switch on output
    OE = 0;

    currentrow--;

    if (currentrow < 0)
    {
        currentrow = 7;
    }
}