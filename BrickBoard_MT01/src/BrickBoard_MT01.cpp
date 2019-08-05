/*
 *  BrickBoard_MT01.cpp
 *  - BrickBoard DC-Motor Module Library
 *
 *  (c) 2015-2016 IAMAMAKER
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU License...
 *  See the GNU License for more details.
 */

#include "BrickBoard_MT01.h"

/*****************
 *  MT01
 *****************/
BrickBoard_MT01::BrickBoard_MT01(): BrickBoard_Ports()
{   /* nothing */   }

BrickBoard_MT01::BrickBoard_MT01(uint8_t portName): BrickBoard_Ports(portName, MODE0)
{   /* nothing */   }

BrickBoard_MT01::BrickBoard_MT01(uint8_t portName, uint8_t cppMode): BrickBoard_Ports(portName, cppMode)
{   /* nothing */   }

void BrickBoard_MT01::writeMotor(uint8_t state)
{
    if (state == MT_FORWARD) {
        BrickBoard_Ports::writeDigital(S1, HIGH);
        BrickBoard_Ports::writeDigital(S2, LOW);
    }
    else if (state == MT_REVERSE) {
        BrickBoard_Ports::writeDigital(S1, LOW);
        BrickBoard_Ports::writeDigital(S2, HIGH);
    }
    else if (state == MT_STOP) {
        BrickBoard_Ports::writeDigital(S1, LOW);
        BrickBoard_Ports::writeDigital(S2, LOW);
    }
    else if (state == MT_BREAK) {
        BrickBoard_Ports::writeDigital(S1, HIGH);
        BrickBoard_Ports::writeDigital(S2, HIGH);
    }
    else {}
}

void BrickBoard_MT01::forwardMotor()
{
    BrickBoard_Ports::writeDigital(S1, HIGH);
    BrickBoard_Ports::writeDigital(S2, LOW);
}

void BrickBoard_MT01::reverseMotor()
{
    BrickBoard_Ports::writeDigital(S1, LOW);
    BrickBoard_Ports::writeDigital(S2, HIGH);
}

void BrickBoard_MT01::stopMotor()
{
    BrickBoard_Ports::writeDigital(S1, LOW);
    BrickBoard_Ports::writeDigital(S2, LOW);
}

void BrickBoard_MT01::breakMotor()
{
    BrickBoard_Ports::writeDigital(S1, HIGH);
    BrickBoard_Ports::writeDigital(S2, HIGH);
}

