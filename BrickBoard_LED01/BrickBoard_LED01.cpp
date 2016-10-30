/*
 *  BrickBoard_LED01.cpp
 *  - BrickBoard 2 Color LED Module(LED01) Library
 *
 *  (c) 2015-2016 IAMAMAKER
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU License...
 *  See the GNU License for more details.
 */

#include "BrickBoard_LED01.h"

BrickBoard_LED01::BrickBoard_LED01(): BrickBoard_Ports()
{ /* nothing */ }

BrickBoard_LED01::BrickBoard_LED01(uint8_t portName): BrickBoard_Ports(portName, MODE0)
{ /* nothing */ }

BrickBoard_LED01::BrickBoard_LED01(uint8_t portName, uint8_t cppMode): BrickBoard_Ports(portName, cppMode)
{ /* nothing */ }


void BrickBoard_LED01::writeBlue(bool value)
{
    BrickBoard_Ports::writeDigital(S1, value);
}

void BrickBoard_LED01::writeRed(bool value)
{
    BrickBoard_Ports::writeDigital(S2, value);
}

void BrickBoard_LED01::onBlue()
{
    BrickBoard_Ports::writeDigital(S1, HIGH);
}

void BrickBoard_LED01::offBlue()
{
    BrickBoard_Ports::writeDigital(S1, LOW);
}

void BrickBoard_LED01::onRed()
{
    BrickBoard_Ports::writeDigital(S2, HIGH);
}

void BrickBoard_LED01::offRed()
{
    BrickBoard_Ports::writeDigital(S2, LOW);
}

void BrickBoard_LED01::blinkBlue(uint16_t msec)
{
    static uint32_t pre_msec = 0;
    static bool state = false;
    uint32_t cur_msec = millis();

    if (TIME_DIFF(pre_msec, cur_msec) >= msec)
    {
        BrickBoard_Ports::writeDigital(S1, state);
        pre_msec = cur_msec;
        state = !state;
    }
}

void BrickBoard_LED01::blinkRed(uint16_t msec)
{
    static uint32_t pre_msec = 0;
    static bool state = false;
    uint32_t cur_msec = millis();

    if (TIME_DIFF(pre_msec, cur_msec) >= msec)
    {
        BrickBoard_Ports::writeDigital(S2, state);
        pre_msec = cur_msec;
        state = !state;
    }
}
