#ifndef __BRICKBOARD_VR01_H__
#define __BRICKBOARD_VR01_H__

#include <BrickBoard.h>


/* Class of BrickBoard VR01 */
class BrickBoard_VR01: public BrickBoard_Ports
{
private:

public:
    BrickBoard_VR01();
    BrickBoard_VR01(uint8_t portName);
    BrickBoard_VR01(uint8_t portName, uint8_t cppMode);
    uint16_t readPotentiometer();
    uint16_t readPotentiometer(uint8_t avgCount);
};

#endif /* __BRICKBOARD_VR01_H__ */