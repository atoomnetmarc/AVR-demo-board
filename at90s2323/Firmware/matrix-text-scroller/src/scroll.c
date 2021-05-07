/*

Copyright 2021 Marc Ketel
SPDX-License-Identifier: Apache-2.0

*/
#include <string.h>
#include <stdbool.h>

#include <avr/sfr_defs.h>

#include "font.h"
#include "main.h"
#include "scroll.h"

const __flash char line_01[] = "1998 called, they want their 8-bit microcontroller back";
const __flash char line_02[] = "Who would have thought a microcontroller over 23 years old would get a brand new pcb in 2021?";
const __flash char line_03[] = "Sit back and relax. This will only take a moment";
const __flash char line_04[] = "Did you know this 16x8 blue LED matrix is driven by only 3 I/O lines?";
const __flash char line_05[] = "The AT90S2323 microcontoller is the first 8-pin AVR. Features:";
const __flash char line_06[] = "118 Powerful Instructions";
const __flash char line_07[] = "32 Registers";
const __flash char line_08[] = "Up to 10 MIPS Throughput at 10 MHz";
const __flash char line_09[] = "2K Bytes of In-System Programmable Flash";
const __flash char line_10[] = "128 Bytes Internal RAM";
const __flash char line_11[] = "128 Bytes of In-System Programmable EEPROM";
const __flash char line_12[] = "Wow. Done :-) Thank you!!!!";

/*
const __flash char line_01[] = "1";
const __flash char line_02[] = "2";
const __flash char line_03[] = "3";
const __flash char line_04[] = "4";
const __flash char line_05[] = "5";
const __flash char line_06[] = "6";
const __flash char line_07[] = "7";
const __flash char line_08[] = "8";
const __flash char line_09[] = "9";
const __flash char line_10[] = "10";
const __flash char line_11[] = "11";
const __flash char line_12[] = "12";
*/

const __flash char *const __flash lines[] =
    {
        line_01,
        line_02,
        line_03,
        line_04,
        line_05,
        line_06,
        line_07,
        line_08,
        line_09,
        line_10,
        line_11,
        line_12,
};

void setPixel(int8_t x, int8_t y, bool value)
{
    if (x > 15 ||
        x < 0 ||
        y > 7 ||
        y < 0)
        return;

    if (value)
        matrix[x] |= _BV(y);
    else
        matrix[x] &= ~_BV(y);
}

void drawCharacter(int8_t x, int8_t y, uint8_t character)
{
    for (uint8_t fontRowCounter = 0; fontRowCounter < sizeof(font[0]); fontRowCounter++)
    {
        uint8_t fontRowData = font[character - 32][fontRowCounter];

        for (int8_t fontColumnCounter = 4; fontColumnCounter >= 0; fontColumnCounter--)
        {
            bool value = 0;

            if ((fontRowData & _BV(fontColumnCounter)) > 0)
                value = 1;

            setPixel(4 - fontColumnCounter + x, fontRowCounter + (y - (sizeof(font[0]) - 1)), value);
        }
    }
}

//Update the LED matrix with a new frame
void scroll(void)
{
    memset((void *)matrix, 0, sizeof(matrix));

    static uint8_t lineNr = 0;
    static int16_t xOffset = -15;
    static uint8_t nullCharPosition = 255;

    bool charDrawn = false;
    for (int8_t x = -5; x < 16; x++)
    {
        if ((xOffset + x) % 6 == 0)
        {
            if (xOffset + x >= 0)
            {
                int8_t characterPositionLine = (xOffset + x) / 6;
                uint8_t character = lines[lineNr][characterPositionLine];

                if (character == 0)
                {
                    nullCharPosition = characterPositionLine;
                }

                if (characterPositionLine < nullCharPosition)
                {
                    drawCharacter(x, 6, character);
                    charDrawn = true;
                }
            }
        }
    }

    if (charDrawn == false)
    {
        xOffset = -15;
        nullCharPosition = 255;

        lineNr++;

        if (lineNr == (sizeof(lines) / __SIZEOF_POINTER__))
            lineNr = 0;
    }
    else
    {
        xOffset++;
    }
}

void scrollLoop(void)
{
    //This function is called every 1ms
    static uint16_t msCounter = 0;

    if (msCounter == 0)
    {
        //Count to n*1ms
        msCounter = 100;

        //Do scrolling
        scroll();
    }

    msCounter--;
}