#ifndef __BRICKBOARD_MP01_H__
#define __BRICKBOARD_MP01_H__

#include <BrickBoard.h>
#include <BrickBoard_US01.h>


/* Class of BrickBoard MP01 */
class BrickBoard_MP01: public BrickBoard_Ports
{
public:
    BrickBoard_MP01();
    BrickBoard_MP01(uint8_t portName);
    BrickBoard_MP01(uint8_t portName, uint8_t cppMode);

    /* Utrasonic I/F */
    double measureUltrasonic(float unitDiv);
    double measureUltrasonic(float unitDiv, uint32_t timeout);
    double measureUltrasonic(float unitDiv, uint8_t measureSample, uint8_t measureDelay);
};

#endif /* __BRICKBOARD_MP01_H__ */
