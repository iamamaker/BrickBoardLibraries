#ifndef __BRICKBOARD_H__
#define __BRICKBOARD_H__

#include <Arduino.h>


/* BrickBoard List */
#define _BRICKBOARD_LED01_		0x01
#define _BRICKBOARD_SW01_		0x02
#define _BRICKBOARD_MT01_		0x03
#define _BRICKBOARD_PZ01_		0x04
#define _BRICKBOARD_VR01_		0x05
#define _BRICKBOARD_IR01_		0x06
#define _BRICKBOARD_MP01_		0x07
#define _BRICKBOARD_BT01_		0x08


/* Port Name Definition */
#define PA          0x01
#define PB          0x02
#define PC          0x03
#define PD          0x04
#define PE          0x05

/* Signal Definition */
#define S1          0x06
#define S2          0x07
#define S3          0x08
#define S4          0x09

/* Mode Definition */
#define MODE0         0x0A  /* Default */
#define MODE1         0x0B
#define MODE2         0x0C

/* Port Signal Pin Definition */
#define PA_S1       5
#define PA_S2       7
#define PA_S3       6
#define PA_S4       4

#define PB_S1       A4
#define PB_S2       A5
#define PB_S3       A0
#define PB_S4       A1

#define PC_S1       9
#define PC_S2       8
#define PC_S3       A2
#define PC_S4       A3

#define PD_S1       11
#define PD_S2       12
#define PD_S3       10
#define PD_S4       13

#define PE_S1       0
#define PE_S2       1
#define PE_S3       3
#define PE_S4       2

#define PXX_S1      A4
#define PXX_S2      A5
#define PBX_S1      3
#define PBX_S2      2

#define L           13

#define NOTHING     -1
#define NA          -1

#define INTERVAL_5SEC   5000
#define INTERVAL_1SEC   1000    /* 1 sec */
#define INTERVAL_100    100 /* 100 msec */
#define INTERVAL_20     20
#define INTERVAL_10     10
#define INTERVAL_5      5
#define INTERVAL_4      4
#define INTERVAL_3      3
#define INTERVAL_2      2
#define INTERVAL_1      1

#define TIME_DIFF(end_t, start_t)  ( (uint32_t)end_t > (uint32_t)start_t ? ~((uint32_t)start_t - (uint32_t)end_t) + 1 : (uint32_t)start_t - (uint32_t)end_t )


class CheckDuration
{
private:
    uint32_t _pre_msec;
public:
    CheckDuration();
    ~CheckDuration();
    void init();
    bool check(uint16_t msec);
};


/* Class of BrickBoard Ports */
class BrickBoard_Ports
{
private:

protected:
    uint8_t _pin1, _pin2, _pin3, _pin4, _port, _mode;

public:
    BrickBoard_Ports();
    BrickBoard_Ports(uint8_t portName, uint8_t mode);
    bool configSignal(uint8_t signalName, uint8_t pinNum);
    uint8_t getPin(uint8_t signalName);
    void writeDigital(uint8_t signalName, bool value);
    bool readDigital(uint8_t signalName);
    void writeAnalog(uint8_t signalName, uint8_t value);
    uint16_t readAnalog(uint8_t signalName);
};


#endif /* __BRICKBOARD_H__ */
