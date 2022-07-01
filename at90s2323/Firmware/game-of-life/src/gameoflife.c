/*

Copyright 2021-2022 Marc Ketel
SPDX-License-Identifier: Apache-2.0

*/
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include <avr/sfr_defs.h>
#include <avr/wdt.h>

#include <util/delay.h>

#include "main.h"
#include "gameoflife.h"

// Next frame of the matrix
volatile uint8_t matrixNew[MATRIX_WIDTH];

// Sets pixel on or off.
void setPixel(int8_t x, int8_t y, bool value)
{
    if (x > 15 ||
        x < 0 ||
        y > 7 ||
        y < 0)
        return;

    if (value)
        matrixNew[x] |= _BV(y);
    else
        matrixNew[x] &= ~_BV(y);
}

// Gets the value of a pixel. Negative values will wrap around.
bool getPixel(int8_t x, int8_t y)
{
    if (x > 15)
        x -= 16;
    if (x < 0)
        x += 16;

    if (y > 7)
        y -= 8;
    if (y < 0)
        y += 8;

    return matrix[x] & _BV(y);
}

// Get the number of alive neighbours.
uint8_t countNeighbours(int8_t x, int8_t y)
{
    uint8_t n = 0;
    n += (int)getPixel(x - 1, y - 1); // left above
    n += (int)getPixel(x, y - 1);     // above
    n += (int)getPixel(x + 1, y - 1); // right above
    n += (int)getPixel(x - 1, y);     // left
    n += (int)getPixel(x + 1, y);     // right
    n += (int)getPixel(x - 1, y + 1); // left below
    n += (int)getPixel(x, y + 1);     // below
    n += (int)getPixel(x + 1, y + 1); // right below

    return n;
}

void randomize(void)
{
    static uint16_t s = 42;
    srand(s++);

    for (uint8_t x = 0; x < 8; x++)
        matrixNew[x + 4] = (rand() | rand()) & 0b01111100;
}

uint8_t countbits(uint8_t var)
{
    uint8_t bits = 0;

    for (uint8_t i = 0; i < 8; i++)
        if (var & _BV(i))
            bits++;

    return bits;
}

// Update the LED matrix with a new frame
void game(void)
{
    static uint16_t deadcounter = 0;
    static uint16_t stablecounter = 0;
    static uint16_t samecounter = 0;
    static uint16_t cyclecounter = 0;
    // Determine game if game is frozen, dead or alive.

    uint16_t matrixNewPixels = 0;
    uint16_t matrixPixels = 0;
    bool sameMatrix = true;
    for (uint8_t x = 0; x < MATRIX_WIDTH; x++)
    {
        matrixNewPixels += countbits(matrixNew[x]);
        matrixPixels += countbits(matrix[x]);

        if (matrixNew[x] != matrix[x])
            sameMatrix = false;
    }

    if (matrixNewPixels == 0)
        deadcounter++;
    else if (sameMatrix)
        samecounter++;
    else if (matrixNewPixels == matrixPixels)
        stablecounter++;
    else
        samecounter = stablecounter = deadcounter = 0;

    cyclecounter++;

    // Erase matrix if number of cells alive stays the same for a while or if pattern does not end.
    if (samecounter > 8 || stablecounter > 40 || cyclecounter > 240)
    {
        memset((void *)matrixNew, 0, sizeof(matrixNew));
        cyclecounter = 0;
    }

    // Randomize matrix if all cells dead.
    if (deadcounter >= 4)
        randomize();

    memcpy((void *)matrix, (void *)matrixNew, sizeof(matrix));

    // Loop though all pixels.
    for (int8_t y = 0; y < 8; y++)
    {

        for (int8_t x = 0; x < MATRIX_WIDTH; x++)
        {
            wdt_reset();
            // Determine life or death based on number of neighboring cells.
            uint8_t neighbours = countNeighbours(x, y);

            switch (neighbours)
            {
            case 2:
                setPixel(x, y, getPixel(x, y));
                break;
            case 3:
                setPixel(x, y, true);
                break;
            default:
                setPixel(x, y, false);
            }
        }
    }
}

void gameSetup(void)
{
    randomize();
}

void gameLoop(void)
{
    // This function is called every 1ms
    static uint16_t msCounter = 0;

    if (msCounter == 0)
    {
        // Count to n*1ms
        msCounter = 250;

        // Do scrolling
        game();
    }

    msCounter--;
}