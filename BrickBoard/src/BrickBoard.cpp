/*
 *  BrickBoard.cpp
 *  - BrickBoard M01 Configurable Plug-Port Library
 *
 *  (c) 2015-2016 IAMAMAKER
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU License...
 *  See the GNU License for more details.
 *
 *  modified - added BRICKBOARD_M02, 2019
 */

#include "BrickBoard.h"


CheckDuration::CheckDuration() {}
CheckDuration::~CheckDuration() {}
void CheckDuration::init()
{
    _pre_msec = millis();
}

bool CheckDuration::check(uint16_t msec)
{
    uint32_t cur_msec = millis();
    if (TIME_DIFF(_pre_msec, cur_msec) >= msec)
    {
        _pre_msec = cur_msec;
        return true;
    }
    else
        return false;
}



/*****************
 *  Ports of M01
 *****************/
BrickBoard_Ports::BrickBoard_Ports() {}

BrickBoard_Ports::BrickBoard_Ports(uint8_t portName, uint8_t mode)
{
    _port = portName;
    _mode = mode;

    if (_port == PA) {
        if (mode == MODE1) {
            _pin1 = PXX_S1;   _pin2 = PXX_S2;
        }
        else {
            _pin1 = PA_S1;    _pin2 = PA_S2;
        }
        _pin3 = PA_S3; _pin4 = PA_S4;
    }
    else if (_port == PB) {
        if (mode == MODE1) {
#if defined (ARDUINO_BRICKBOARD_M01)
            _pin1 = PBX_S1;   _pin2 = PBX_S2;
#elif defined (ARDUINO_BRICKBOARD_M02)
            _pin1 = PXX_S1;   _pin2 = PXX_S2;
#endif
        }
        else {
            _pin1 = PB_S1;    _pin2 = PB_S2;
        }
        _pin3 = PB_S3; _pin4 = PB_S4;
    }
    else if (_port == PC) {
        if (mode == MODE1) {
            _pin1 = PXX_S1;   _pin2 = PXX_S2;
        }
        else {
            _pin1 = PC_S1;    _pin2 = PC_S2;
        }
        _pin3 = PC_S3; _pin4 = PC_S4;
    }
    else if (_port == PD) {
        if (mode == MODE1) {
            _pin1 = PXX_S1;   _pin2 = PXX_S2;
        }
        else {
            _pin1 = PD_S1;    _pin2 = PD_S2;
        }
        _pin3 = PD_S3; _pin4 = PD_S4;
    }
    else if (_port == PE) {
#if defined (ARDUINO_BRICKBOARD_M01)
        if (mode == MODE1) {
            _pin4 = NOTHING;
        }
        else {
            _pin4 = PE_S4;
        }
        _pin1 = PE_S1; _pin2 = PE_S2; _pin3 = PE_S3;
#elif defined (ARDUINO_BRICKBOARD_M02)
        if (mode == MODE1) {
            _pin1 = PEX_S1;   _pin2 = PEX_S2;
        }
        else {
            _pin1 = PE_S1;    _pin2 = PE_S2;
        }
        _pin3 = PE_S3; _pin4 = PE_S4;
#endif
    }
    else{}
}

#if 0 // not used
bool BrickBoard_Ports::configSignal(uint8_t signalName, uint8_t pinNum)
{
    if (_port != PE) {
        if (signalName == S1)
            _pin1 = pinNum;
        else if (signalName == S2)
            _pin2 = pinNum;
        else
            return false;
    }
    else {
        if (signalName == S4)
            _pin4 = pinNum;
        else
            return false;
    }
    return true;
}
#endif

uint8_t BrickBoard_Ports::getPin(uint8_t signalName)
{
    uint8_t sig;
    if (signalName == S1)
        sig = _pin1;
    else if (signalName == S2)
        sig = _pin2;
    else if (signalName == S3)
        sig = _pin3;
    else if (signalName == S4)
        sig = _pin4;
    else
        sig = NOTHING;

    return sig;
}

void BrickBoard_Ports::writeDigital(uint8_t signalName, bool value)
{
    uint8_t pin = getPin(signalName);

    pinMode(pin, OUTPUT);
    digitalWrite(pin, value);
}

bool BrickBoard_Ports::readDigital(uint8_t signalName)
{
    uint8_t pin = getPin(signalName);

    pinMode(pin, INPUT);
    return digitalRead(pin);
}

void BrickBoard_Ports::writeAnalog(uint8_t signalName, uint8_t value)
{
    uint8_t pin = getPin(signalName);

    analogWrite(pin, value);
}

uint16_t BrickBoard_Ports::readAnalog(uint8_t signalName)
{
    uint8_t pin = getPin(signalName);

    return analogRead(pin);
}
