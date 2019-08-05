/*
 *  BrickBoard_VR01.cpp
 *  - BrickBoard Potentiometer Module(VR01) Library
 *
 *  (c) 2015-2016 IAMAMAKER
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU License...
 *  See the GNU License for more details.
 */

#include "BrickBoard_VR01.h"

/*****************
 *  VR01
 *****************/
BrickBoard_VR01::BrickBoard_VR01(): BrickBoard_Ports()
{   /* nothing */   }

BrickBoard_VR01::BrickBoard_VR01(uint8_t portName): BrickBoard_Ports(portName, MODE0)
{   /* nothing */   }

BrickBoard_VR01::BrickBoard_VR01(uint8_t portName, uint8_t cppMode): BrickBoard_Ports(portName, cppMode)
{   /* nothing */   }

uint16_t BrickBoard_VR01::readPotentiometer()
{
#if defined (ARDUINO_BRICKBOARD_M01)
    if (!(_port == PB || _port == PC))
        return NA;  // not available
    else
#endif
        return BrickBoard_Ports::readAnalog(S3);
}

uint16_t BrickBoard_VR01::readPotentiometer(uint8_t avgCount)  /* avgCount : 1 ~ 255 */
{
    uint32_t sum = 0;

#if defined (ARDUINO_BRICKBOARD_M01)
    if (!(_port == PB || _port == PC))
        return NA;  // not available
    else {}
#endif

    if (avgCount < 1)
        return NA;

    for (int i = 0; i < avgCount; i++)
    {
        sum += BrickBoard_Ports::readAnalog(S3);
    }

    return (uint16_t)(sum / avgCount);
}
