/*
 *  BrickBoard_IR01.cpp
 *  - BrickBoard IR Sensor Module(IR01) Library
 *
 *  (c) 2015-2016 IAMAMAKER
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU License...
 *  See the GNU License for more details.
 */

#include "BrickBoard_IR01.h"

/*****************
 *  IR01
 *****************/
BrickBoard_IR01::BrickBoard_IR01(): BrickBoard_Ports()
{   /* Nothing */   }

BrickBoard_IR01::BrickBoard_IR01(uint8_t portName): BrickBoard_Ports(portName, MODE0)
{   /* Nothing */   }

BrickBoard_IR01::BrickBoard_IR01(uint8_t portName, uint8_t cppMode): BrickBoard_Ports(portName, cppMode)
{   /* Nothing */   }

void BrickBoard_IR01::writeIred(bool value)
{
    BrickBoard_Ports::writeDigital(S2, value);
}

bool BrickBoard_IR01::readPhotoTr()
{
    return BrickBoard_Ports::readDigital(S1);
}

void BrickBoard_IR01::onIred()
{
    BrickBoard_Ports::writeDigital(S2, HIGH);
}

void BrickBoard_IR01::offIred()
{
    BrickBoard_Ports::writeDigital(S2, LOW);
}