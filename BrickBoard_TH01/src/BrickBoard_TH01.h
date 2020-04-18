/*
 *  BrickBoard_TH01.h
 *  - BrickBoard TH01 Sensor Module(AM2302) Library
 *
 *  (c) 2015-2019 IAMAMAKER
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU License...
 *  See the GNU License for more details.
 */

#ifndef __BRICKBOARD_TH01_H__
#define __BRICKBOARD_TH01_H__

#include <BrickBoard.h>

/*
 *  The BrickBoard TH01 library was created by inheriting the DHTlib library.
 *  You must register the DHTlib library.
 *  (https://github.com/RobTillaart/Arduino/tree/master/libraries/DHTlib)
 */
#include <dht.h>

#define TH01_READ_INTERVAL  2000    // 2sec
#define TH01_SKIP_READ      1
#define TH01_OK             0


class BrickBoard_TH01: public BrickBoard_Ports, public dht
{
private:
    uint32_t _prevMsec;

    int8_t nonBlockingRead(uint16_t intervalMsec);

public:
    BrickBoard_TH01();
    BrickBoard_TH01(uint8_t portName);
    BrickBoard_TH01(uint8_t portName, uint8_t cppMode);

    int8_t read();
    int8_t read(uint16_t intervalMsec);
    float getTemperature();
    float getHumidity();
};

#endif /* __BRICKBOARD_TH01_H__ */
