#ifndef __BRICKBOARD_SW01_H__
#define __BRICKBOARD_SW01_H__

#include <BrickBoard.h>

#define QCNT        5
#define SWM_STATE   0
#define SWM_TOGGLE  1

/* Class of SwitchDebouncing */
class SwitchDebouncing
{
private:
    uint32_t _ts;
    bool _q[QCNT];
    uint8_t _i;
    bool _mask;
    uint8_t _mode; /* State or Toggle */
    bool _state;

public:
    SwitchDebouncing();
    bool check(bool switchState, uint8_t switchMode, uint16_t intervalMsec);
};

/* Class of BrickBoard SW01 */
class BrickBoard_SW01: public BrickBoard_Ports
{
private:

public:
    BrickBoard_SW01();
    BrickBoard_SW01(uint8_t portName);
    BrickBoard_SW01(uint8_t portName, uint8_t cppMode);
    bool readBlue();
    bool readRed();
    bool checkBlue(uint8_t switchMode);
    bool checkBlue(uint8_t switchMode, uint16_t intervalMsec);
    bool checkRed(uint8_t switchMode);
    bool checkRed(uint8_t switchMode, uint16_t intervalMsec);
};

#endif /* __BRICKBOARD_SW01_H__ */
