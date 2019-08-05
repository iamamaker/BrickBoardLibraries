#ifndef __BRICKBOARD_MT01_H__
#define __BRICKBOARD_MT01_H__

#include <BrickBoard.h>

#define MT_STOP        0x0
#define MT_FORWARD     0x1
#define MT_REVERSE     0x2
#define MT_BREAK       0x3

/* Class of BrickBoard MT01 */
class BrickBoard_MT01: public BrickBoard_Ports
{
private:

public:
    BrickBoard_MT01();
    BrickBoard_MT01(uint8_t portName);
    BrickBoard_MT01(uint8_t portName, uint8_t cppMode);
    void writeMotor(uint8_t direction);
    void forwardMotor();
    void reverseMotor();
    void stopMotor();
    void breakMotor();
};

#endif /* __BRICKBOARD_MT01_H__ */
