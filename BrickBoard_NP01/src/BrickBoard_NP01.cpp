/*
 *  BrickBoard_NP01.cpp
 *  - BrickBoard NeoPixel Module(NP01) Library
 *  - Version : 1.0.0
 *
 *  (c) 2015-2019 IAMAMAKER
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU License...
 *  See the GNU License for more details.
 */

#include "BrickBoard_NP01.h"

/*****************
 *  NP01
 *****************/
BrickBoard_NP01::BrickBoard_NP01(): BrickBoard_Ports() {}
BrickBoard_NP01::BrickBoard_NP01(uint8_t portName): BrickBoard_Ports(portName, MODE0)
{
    begun = false;
    brightness = 0;
    pixels = NULL;
    endTime = 0;

    updateType(NEO_GRB + NEO_KHZ800);
    updateLength(4);
    setPin(_pin1);
}
BrickBoard_NP01::BrickBoard_NP01(uint8_t portName, uint8_t cppMode): BrickBoard_Ports(portName, cppMode)
{
    begun = false;
    brightness = 0;
    pixels = NULL;
    endTime = 0;

    updateType(NEO_GRB + NEO_KHZ800);
    updateLength(4);
    setPin(_pin1);
}


void BrickBoard_NP01::setLedColor(uint16_t n, uint8_t r, uint8_t g, uint8_t b)
{
    Adafruit_NeoPixel::setPixelColor(n - 1, r, g, b);
}

void BrickBoard_NP01::setLedColor(uint16_t n, uint8_t r, uint8_t g, uint8_t b, uint8_t w)
{
    Adafruit_NeoPixel::setPixelColor(n - 1, r, g, b, w);
}

void BrickBoard_NP01::setLedColor(uint16_t n, uint32_t c) {
    Adafruit_NeoPixel::setPixelColor(n - 1, c);
}

static const uint32_t _simpleColorSpectrum[25] PROGMEM = {
    0xFF0000, 0xFF2A00, 0xFF5500, 0xFF8000, 0xFFAA00,
    0xFFD500, 0xFFFF00, 0xD4FF00, 0xAAFF00, 0x80FF00,
    0x55FF00, 0x2BFF00, 0x00FF00, 0x00FF2A, 0x00FF55,
    0x00FF80, 0x00FFAA, 0x00FFD5, 0x00FFFF, 0x00D5FF,
    0x00AAFF, 0x0080FF, 0x0055FF, 0x002AFF, 0X0000FF };

uint32_t BrickBoard_NP01::simpleColorSpectrum(uint8_t idx) const {
    return pgm_read_dword(&_simpleColorSpectrum[idx]);
}
