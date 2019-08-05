/*
 *  BrickBoard_US01.cpp
 *  - BrickBoard Ultarsonic Sensor Module(US01) Library
 *
 *  (c) 2015-2016 IAMAMAKER
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU License...
 *  See the GNU License for more details.
 */

#include "BrickBoard_US01.h"


/*****************
 *  US01
 *****************/
BrickBoard_US01::BrickBoard_US01(): BrickBoard_Ports()
{   /* Nothing */   }

BrickBoard_US01::BrickBoard_US01(uint8_t portName): BrickBoard_Ports(portName, MODE0)
{   /* Nothing */   }

BrickBoard_US01::BrickBoard_US01(uint8_t portName, uint8_t cppMode): BrickBoard_Ports(portName, cppMode)
{   /* Nothing */   }

/* Utrasonic I/F */
double BrickBoard_US01::measureUltrasonic(float unitDiv)
{
    pinMode(_pin1, INPUT);    /* ECHO */
    pinMode(_pin2, OUTPUT);   /* TRIGGER */

    digitalWrite(_pin2, LOW);
    delayMicroseconds(2);
    digitalWrite(_pin2, HIGH);
    delayMicroseconds(10);
    digitalWrite(_pin2, LOW);

    return (((double)(pulseIn(_pin1, HIGH)) / unitDiv) / 2.0);
}

double BrickBoard_US01::measureUltrasonic(float unitDiv, uint32_t timeout)
{
    pinMode(_pin1, INPUT);    /* ECHO */
    pinMode(_pin2, OUTPUT);   /* TRIGGER */

    digitalWrite(_pin2, LOW);
    delayMicroseconds(2);
    digitalWrite(_pin2, HIGH);
    delayMicroseconds(10);
    digitalWrite(_pin2, LOW);

    return (((double)(pulseIn(_pin1, HIGH, timeout)) / unitDiv) / 2.0);
}

double BrickBoard_US01::measureUltrasonic(float unitDiv, uint8_t measureSample, uint8_t measureDelay)
{
  double measureSum = 0;
  double maxValue = 0, minValue = 0;

  if (measureSample < 3)
  {
	measureSample = 3;
  }
  else {}

  for (int i = 0; i < measureSample; i++)
  {
    double curValue = measureUltrasonic(unitDiv);

    if (i == 0)
    {
      maxValue = minValue = curValue;
    }
    else
    {
      maxValue = max(maxValue, curValue);
      minValue = min(minValue, curValue);
    }

    measureSum += curValue;
    delay(measureDelay);
  }

  return ((measureSum - maxValue - minValue) / (measureSample - 2));
}
