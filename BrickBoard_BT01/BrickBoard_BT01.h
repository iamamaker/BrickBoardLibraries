#ifndef __BRICKBOARD_BT01_H__
#define __BRICKBOARD_BT01_H__

#include <BrickBoard.h>
#include <SoftwareSerial.h>


class BrickBoard_BT01: public BrickBoard_Ports, public SoftwareSerial
{
private:

public:
    BrickBoard_BT01();
    BrickBoard_BT01(uint8_t portName);
    BrickBoard_BT01(uint8_t portName, uint8_t cppMode);
    char *sendAtCommand(const String &s);
    bool setBaudrate(const String &s);
    bool setPassword(const String &s);
    bool setDeviceName(const String &s);
    bool setUploadMode();
};

#endif /* __BRICKBOARD_BT01_H__ */
