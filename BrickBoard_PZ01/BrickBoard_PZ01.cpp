/*
 *  BrickBoard_PZ01.cpp
 *  - BrickBoard Piezo Module Library
 *
 *  (c) 2015-2016 IAMAMAKER
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU License...
 *  See the GNU License for more details.
 */

#include "BrickBoard_PZ01.h"

/*****************
 *  PZ01
 *****************/
BrickBoard_PZ01::BrickBoard_PZ01(): BrickBoard_Ports()
{   /* nothing */   }

BrickBoard_PZ01::BrickBoard_PZ01(uint8_t portName): BrickBoard_Ports(portName, MODE0)
{   /* nothing */   }

BrickBoard_PZ01::BrickBoard_PZ01(uint8_t portName, uint8_t cppMode): BrickBoard_Ports(portName, cppMode)
{   /* nothing */   }

void BrickBoard_PZ01::playMelody(uint16_t *melodyArray, uint16_t arraySize)
{
    for (uint16_t i = 0; i < (arraySize / sizeof(uint16_t)); i++)
    {
        uint32_t duration = 125 * *(melodyArray + (i + 1));
        tone(_pin1, *(melodyArray + i), duration);
        uint16_t pause = duration * 1.30;
        delay(pause);
        i++;
    }
    noTone(_pin1);
}

void BrickBoard_PZ01::playTone(uint16_t frequency)
{
    tone(_pin1, frequency);
}

void BrickBoard_PZ01::playTone(uint16_t frequency, uint32_t duration)
{
    tone(_pin1, frequency, duration);
}

void BrickBoard_PZ01::stopTone()
{
    noTone(_pin1);
}