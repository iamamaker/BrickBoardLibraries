#ifndef __BRICKBOARD_LED01_H__
#define __BRICKBOARD_LED01_H__

#include <BrickBoard.h>

/* Class of BrickBoard LED01 */
class BrickBoard_LED01: public BrickBoard_Ports
{
private:

public:
    BrickBoard_LED01();
    BrickBoard_LED01(uint8_t portName);
    BrickBoard_LED01(uint8_t portName, uint8_t cppMode);
    void writeBlue(bool value);
    void writeRed(bool value);
    void onBlue();
    void offBlue();
    void onRed();
    void offRed();
    void blinkBlue(uint16_t msec);
    void blinkRed(uint16_t msec);
};

#endif /* __BRICKBOARD_LED01_H__ */