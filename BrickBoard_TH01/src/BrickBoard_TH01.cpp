/*
 *  BrickBoard_TH01.cpp
 *  - BrickBoard TH01 Sensor Module(AM2302) Library
 *
 *  (c) 2015-2019 IAMAMAKER
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU License...
 *  See the GNU License for more details.
 */

#include "BrickBoard_TH01.h"

/*****************
 *  TH01
 *****************/
BrickBoard_TH01::BrickBoard_TH01(): BrickBoard_Ports() {}
BrickBoard_TH01::BrickBoard_TH01(uint8_t portName): BrickBoard_Ports(portName, MODE0) {}
BrickBoard_TH01::BrickBoard_TH01(uint8_t portName, uint8_t cppMode): BrickBoard_Ports(portName, cppMode) {}

int8_t BrickBoard_TH01::nonBlockingRead(uint16_t intervalMsec)
{
    uint32_t currMsec = millis();
    int8_t state;

    if (TIME_DIFF(_prevMsec, currMsec) >= intervalMsec)
    {
        pinMode(_pin2, OUTPUT);
        digitalWrite(_pin2, HIGH);
        _prevMsec = currMsec;
        state = dht::read22(_pin1);
        digitalWrite(_pin2, LOW);
    }
    else
    {
        state = TH01_SKIP_READ;
    }

    if (state < TH01_OK)
    {
        digitalWrite(_pin2, HIGH);
    }

    return state;
}

int8_t BrickBoard_TH01::read()
{
    return nonBlockingRead(TH01_READ_INTERVAL);
}

int8_t BrickBoard_TH01::read(uint16_t intervalMsec)
{
    return nonBlockingRead(intervalMsec);
}

float BrickBoard_TH01::getTemperature()
{
    return dht::temperature;
}

float BrickBoard_TH01::getHumidity()
{
    return dht::humidity;
}
