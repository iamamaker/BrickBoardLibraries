/*
 *  BrickBoard_DS01.cpp
 *  - BrickBoard Dust Sensor Module(DS01) Library
 *  - Version : 1.0.1
 *
 *  (c) 2015-2019 IAMAMAKER
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU License...
 *  See the GNU License for more details.
 */

#include "BrickBoard_DS01.h"

/*****************
 *  DS01
 *****************/
BrickBoard_DS01::BrickBoard_DS01(): BrickBoard_Ports() {}
BrickBoard_DS01::BrickBoard_DS01(uint8_t portName): BrickBoard_Ports(portName, MODE0) {}
BrickBoard_DS01::BrickBoard_DS01(uint8_t portName, uint8_t cppMode): BrickBoard_Ports(portName, cppMode) {}

/* default */
// intervalMsec : min 200 msec
// qCnt         : max 100 cnt
float BrickBoard_DS01::avgDustData(uint16_t intervalMsec, uint8_t qCnt)
{
#if defined (ARDUINO_BRICKBOARD_M01)
    if (_port == PA || _port == PD || _port == PE)
        return NA;  // not available
#endif

    uint32_t currMsec = millis();

    if (intervalMsec < DS01_MIN_INTV)
        intervalMsec = DS01_MIN_INTV;

    if (TIME_DIFF(_prevMsec, currMsec) >= intervalMsec)
    {
        pinMode(_pin2, OUTPUT);
        digitalWrite(_pin2, HIGH);

        _prevMsec = currMsec;
        uint16_t rdc = _q[_i];

        pinMode(_pin1, OUTPUT); /* IRED */
        digitalWrite(_pin1, LOW);
        delayMicroseconds(280);
        uint16_t rawData = analogRead(_pin3);
        delayMicroseconds(40);
        digitalWrite(_pin1, HIGH);

        _q[_i] = rawData * (5.0 / 1024.0) * 100;

        if (qCnt > DS01_MAX_QCNT)
            qCnt = DS01_MAX_QCNT;

        if (_i == (qCnt - 1))
            _validData = true;

        _sum = _sum - rdc + _q[_i];
        _i = (_i + 1) % qCnt;

        if (_validData)
        {
            float dustVout = ((float)_sum / (float)qCnt) / 100.0;    // convert raw data to voltage

            if (!_calMode)
            {
                if (_voc == 0)
                    _voc = DS01_DEFAULT_VOC;

                if (dustVout < _voc)    // update voc
                    _voc = dustVout;

                _returnValue = (dustVout - _voc) / 0.005;   // typical K parameter
            }
            else
            {
                _returnValue = dustVout;
            }

            digitalWrite(_pin2, LOW);
        }
        else
        {
            _returnValue = 0.0;
        }
    }

    return _returnValue;
}

float BrickBoard_DS01::getDustDensity()
{
   return  avgDustData(DS01_DEFAULT_INTV, 30);
}

float BrickBoard_DS01::getDustDensity(uint8_t qCnt)
{
    return avgDustData(DS01_DEFAULT_INTV, qCnt);
}

float BrickBoard_DS01::getDustDensity(uint16_t intervalMsec, uint8_t qCnt)
{
    return avgDustData(intervalMsec, qCnt);
}

void BrickBoard_DS01::setVoc(float voc)
{
    _voc = voc;
}

float BrickBoard_DS01::getVoc()
{
    return _voc;
}

bool BrickBoard_DS01::calibrationVoc()
{
    _calMode = true;

    float getVoc = avgDustData(DS01_DEFAULT_INTV, DS01_MAX_QCNT);

    if (!_validData)
        return false;

    static uint32_t prevMsec = 0;
    uint32_t currMsec = millis();

    if (TIME_DIFF(prevMsec, currMsec) >= DS01_DEFAULT_INTV)
    {
        prevMsec = currMsec;
        _calAvgCnt++;
        _calSumVout = _calSumVout + getVoc;
    }

    if (_calAvgCnt == DS01_VOC_AVG_CNT)
    {
       _voc = _calSumVout / DS01_VOC_AVG_CNT;
       _calMode = false;
       return true;
    }
    else
    {
        return false;
    }
}
