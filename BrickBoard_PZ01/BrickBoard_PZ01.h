#ifndef __BRICKBOARD_PZ01_H__
#define __BRICKBOARD_PZ01_H__

#include <BrickBoard.h>
#include "pitches.h"


/* Class of BrickBoard PZ01 */
class BrickBoard_PZ01: public BrickBoard_Ports
{
private:

public:
    BrickBoard_PZ01();
    BrickBoard_PZ01(uint8_t portName);
    BrickBoard_PZ01(uint8_t portName, uint8_t cppMode);
    void playMelody(uint16_t *melodyArray, uint16_t arraySize);
    void playTone(uint16_t frequency);
    void playTone(uint16_t frequency, uint32_t duration);
    void stopTone();
};

#endif /* __BRICKBOARD_PZ01_H__ */