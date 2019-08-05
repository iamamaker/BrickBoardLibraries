/*
 *  BrickBoard_NP01.h
 *  - BrickBoard NeoPixel Module(NP01) Library
 *  - Version : 1.0.0
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
#include <avr/pgmspace.h>


class BrickBoard_NP01: public BrickBoard_Ports, public Adafruit_NeoPixel
{
private:


public:
    BrickBoard_NP01();
    BrickBoard_NP01(uint8_t portName);
    BrickBoard_NP01(uint8_t portName, uint8_t cppMode);

    void setPixelColor(uint16_t n, uint8_t r, uint8_t g, uint8_t b);
    void setPixelColor(uint16_t n, uint8_t r, uint8_t g, uint8_t b, uint8_t w);
    void setPixelColor(uint16_t n, uint32_t c);

    uint32_t colorSpectrum(uint8_t idx) const;
};

#endif /* __BRICKBOARD_NP01_H__ */
