/*
 *  BrickBoard_NP01.h
 *  - BrickBoard NeoPixel Module(NP01) Library
 *  - Version : 1.0.1
 *
 *  (c) 2015-2019 IAMAMAKER
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU License...
 *  See the GNU License for more details.
 */

#ifndef __BRICKBOARD_NP01_H__
#define __BRICKBOARD_NP01_H__

#include <BrickBoard.h>
#include <Adafruit_NeoPixel.h>

#define C_RED       0xff0000
#define C_AMBER     0xffbf00
#define C_YELLOW    0xffff00
#define C_GREEN     0x009900
#define C_BLUE      0x0000ff
#define C_INDIGO    0x4b0082
#define C_PURPLE    0x800080
#define C_WHITE     0xffffff
#define C_BLACK     0x000000


class BrickBoard_NP01: public BrickBoard_Ports, public Adafruit_NeoPixel
{
private:


public:
    BrickBoard_NP01();
    BrickBoard_NP01(uint8_t portName);
    BrickBoard_NP01(uint8_t portName, uint8_t cppMode);

    void setLedColor(uint16_t n, uint8_t r, uint8_t g, uint8_t b);
    void setLedColor(uint16_t n, uint8_t r, uint8_t g, uint8_t b, uint8_t w);
    void setLedColor(uint16_t n, uint32_t c);

    uint32_t simpleColorSpectrum(uint8_t idx) const;
};

#endif /* __BRICKBOARD_NP01_H__ */
