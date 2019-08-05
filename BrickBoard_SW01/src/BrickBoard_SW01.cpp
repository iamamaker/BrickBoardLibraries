/*
 *  BrickBoard_SW01.cpp
 *  - BrickBoard 2 Switch Module(SW01) Library
 *
 *  (c) 2015-2016 IAMAMAKER
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU License...
 *  See the GNU License for more details.
 */

#include "BrickBoard_SW01.h"

/*****************
 *  Switch Debounce
 *****************/
SwitchDebouncing::SwitchDebouncing()
{ /* nothing */ }

bool SwitchDebouncing::check(bool switchState, uint8_t switchMode, uint16_t intervalMsec)
{
    uint32_t current_msec = millis();
    uint8_t i;

    if (TIME_DIFF(current_msec, _ts) >= intervalMsec)
    {
        _q[_i] = switchState;
        _i = (_i + 1) % QCNT;

        for (i = 0; i < QCNT; i++)
        {
            if (_q[i])
            {
                if ((i == (QCNT - 1)) && (_mask == false))
                {
                    if (switchMode != SWM_TOGGLE)
                    {
                        _state = true;
                    }
                    else
                    {
                        _state = !_state;
                    }

                    _mask = true;
                }
                else {}
            }
            else
            {
                if (switchMode != SWM_TOGGLE)
                {
                    _state = false;
                }
                else {}

                _mask = false;
                break;
            }
        }

        _ts = millis();
    }
    else
    {}

    return _state;
}



/*****************
 *  SW01
 *****************/
BrickBoard_SW01::BrickBoard_SW01(): BrickBoard_Ports()
{   /* nothing */   }

BrickBoard_SW01::BrickBoard_SW01(uint8_t portName): BrickBoard_Ports(portName, MODE0)
{   /* nothing */   }

BrickBoard_SW01::BrickBoard_SW01(uint8_t portName, uint8_t cppMode): BrickBoard_Ports(portName, cppMode)
{   /* nothing */   }

bool BrickBoard_SW01::readBlue()
{
    return BrickBoard_Ports::readDigital(S1);
}

bool BrickBoard_SW01::readRed()
{
    return BrickBoard_Ports::readDigital(S2);
}

bool BrickBoard_SW01::checkRed(uint8_t switchMode)
{
    /* Defaut : QCNT 5, INTERVAL 20 msec = 100msec */
    static SwitchDebouncing debounceRed;
    return debounceRed.check(BrickBoard_Ports::readDigital(S2), switchMode, INTERVAL_20);
}

bool BrickBoard_SW01::checkRed(uint8_t switchMode, uint16_t intervalMsec)
{
    /* Config : intervalMsec(msec) * QCNT 5 */
    static SwitchDebouncing debounceRed;
    return debounceRed.check(BrickBoard_Ports::readDigital(S2), switchMode, intervalMsec);
}

bool BrickBoard_SW01::checkBlue(uint8_t switchMode)
{
    /* Defaut : QCNT 5, INTERVAL 20 msec = 100msec */
    static SwitchDebouncing debounceBlue;
    return debounceBlue.check(BrickBoard_Ports::readDigital(S1), switchMode, INTERVAL_20);
}

bool BrickBoard_SW01::checkBlue(uint8_t switchMode, uint16_t intervalMsec)
{
    /* Config : intervalMsec(msec) * QCNT 5 */
    static SwitchDebouncing debounceBlue;
    return debounceBlue.check(BrickBoard_Ports::readDigital(S1), switchMode, intervalMsec);
}
