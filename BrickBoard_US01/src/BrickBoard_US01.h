#ifndef __BRICKBOARD_US01_H__
#define __BRICKBOARD_US01_H__

#include <BrickBoard.h>

#define MP_MM           2.9
#define MP_CM           29.0
#define MP_INCH         74.0
#define MP_TIMEOUT      20000


/* Class of BrickBoard MP01 */
class BrickBoard_US01: public BrickBoard_Ports
{
public:
    BrickBoard_US01();
    BrickBoard_US01(uint8_t portName);
    BrickBoard_US01(uint8_t portName, uint8_t cppMode);

    /* Utrasonic I/F */
    double measureUltrasonic(float unitDiv);
    double measureUltrasonic(float unitDiv, uint32_t timeout);
    double measureUltrasonic(float unitDiv, uint8_t measureSample, uint8_t measureDelay);
};

#endif /* __BRICKBOARD_US01_H__ */
