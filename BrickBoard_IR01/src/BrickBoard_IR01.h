#ifndef __BRICKBOARD_IR01_H__
#define __BRICKBOARD_IR01_H__

#include <BrickBoard.h>


/* Class of BrickBoard IR01 */
class BrickBoard_IR01: public BrickBoard_Ports
{
private:

public:
    BrickBoard_IR01();
    BrickBoard_IR01(uint8_t portName);
    BrickBoard_IR01(uint8_t portName, uint8_t cppMode);
    void writeIred(bool value);
    bool readPhotoTr();
    void onIred();
    void offIred();
};


#endif /* __BRICKBOARD_IR01_H__ */