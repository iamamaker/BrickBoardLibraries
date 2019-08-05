/*
 *  BrickBoard_DS01.h
 *  - BrickBoard Dust Sensor Module(DS01) Library
 *  - Version : 1.0.1
 *
 *  (c) 2015-2019 IAMAMAKER
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU License...
 *  See the GNU License for more details.
 */

#ifndef __BRICKBOARD_DS01_H__
#define __BRICKBOARD_DS01_H__

#include <BrickBoard.h>

#define DS01_DEFAULT_INTV 300
#define DS01_MIN_INTV 200
#define DS01_MAX_QCNT 100

#define DS01_DEFAULT_VOC 0.5
#define DS01_VOC_AVG_CNT 30

class BrickBoard_DS01: public BrickBoard_Ports
{
private:
    uint32_t _prevMsec;
    bool _validData;

    bool _calMode;
    float _voc;

    uint16_t _q[DS01_MAX_QCNT];
    uint8_t _i;
    uint32_t _sum;

    float _returnValue;
    uint8_t _calAvgCnt;
    float _calSumVout;

    float avgDustData(uint16_t intervalMsec, uint8_t qCnt);

public:
    BrickBoard_DS01();
    BrickBoard_DS01(uint8_t portName);
    BrickBoard_DS01(uint8_t portName, uint8_t cppMode);

    float getDustDensity();
    float getDustDensity(uint8_t qCnt);
    float getDustDensity(uint16_t intervalMsec, uint8_t qCnt);
    void setVoc(float voc);
    float getVoc();
    bool calibrationVoc();
};

#endif /* __BRICKBOARD_DS01_H__ */
