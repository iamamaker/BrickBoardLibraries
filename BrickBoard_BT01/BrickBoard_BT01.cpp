/*
 *  BrickBoard_BT01.cpp
 *  - BrickBoard Bluetooth Module(BT01) Library
 *
 *  (c) 2015-2016 IAMAMAKER
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU License...
 *  See the GNU License for more details.
 */

#include "BrickBoard_BT01.h"

BrickBoard_BT01::BrickBoard_BT01(): BrickBoard_Ports(), SoftwareSerial(_pin1, _pin2)
{   /* nothing */   }

BrickBoard_BT01::BrickBoard_BT01(uint8_t portName): BrickBoard_Ports(portName, MODE0), SoftwareSerial(_pin1, _pin2)
{   /* nothing */   }

BrickBoard_BT01::BrickBoard_BT01(uint8_t portName, uint8_t cppMode): BrickBoard_Ports(portName, cppMode), SoftwareSerial(_pin1, _pin2)
{   /* nothing */   }

char *BrickBoard_BT01::sendAtCommand(const String &s)
{
    begin(38400);
    bool recvDone = false;
    static char str[50] = {0,};

    uint32_t prevTime = millis();
    Serial.println(s + " - Send AT Command!!");

    while (!recvDone)
    {
        if (TIME_DIFF(prevTime, millis()) > INTERVAL_5SEC)
        {
            Serial.println("AT Command Response Timeout!!");
            return NULL;
        }
        else {}

        write(s.c_str(), s.length());
        delay(500);

        uint8_t recvByte = available();
        if (recvByte > 0)
        {
            for (uint8_t i = 0; i < recvByte; i++)
            {
                str[i] = read();
            }
            recvDone = true;
            Serial.write(str);
        }
        else
        {
            Serial.println("Retry!! Send AT Command!!");
        }
    }
    return str;
}

bool BrickBoard_BT01::setBaudrate(const String &s)
{
    pinMode(L, OUTPUT);
    digitalWrite(L, LOW);
    begin(38400);

    String str = "";

    str = sendAtCommand("AT\r\n");
    if (str != "OK\r\n")
    {
        Serial.println("Check Fail!!");
        return false;
    }
    else {}

    str = "AT+UART=";
    str += s;
    str += "\r\n";

    str = sendAtCommand(str);
    if (str != "OK\r\n")
    {
        Serial.println("Baudrate Set Fail!!");
        return false;
    }
    else {}

    digitalWrite(L, HIGH);
    return true;
}

bool BrickBoard_BT01::setPassword(const String &s)
{
    pinMode(L, OUTPUT);
    digitalWrite(L, LOW);
    begin(38400);

    String str = "";

    str = sendAtCommand("AT\r\n");
    if (str != "OK\r\n")
    {
        Serial.println("Check Fail!!");
        return false;
    }
    else {}

    str = "AT+PSWD=";
    str += s;
    str += "\r\n";

    str = sendAtCommand(str);
    if (str != "OK\r\n")
    {
        Serial.println("Password Set Fail!!");
        return false;
    }
    else {}

    digitalWrite(L, HIGH);
    return true;
}

bool BrickBoard_BT01::setDeviceName(const String &s)
{
    pinMode(L, OUTPUT);
    digitalWrite(L, LOW);
    begin(38400);

    String str = "";

    str = sendAtCommand("AT\r\n");
    if (str != "OK\r\n")
    {
        Serial.println("Check Fail!!");
        return false;
    }
    else {}

    str = "AT+NAME=";
    str += s;
    str += "\r\n";

    str = sendAtCommand(str);
    if (str != "OK\r\n")
    {
        Serial.println("Device Name Set Fail!!");
        return false;
    }
    else {}

    digitalWrite(L, HIGH);
    return true;
}


bool BrickBoard_BT01::setDefaultMode()
{
    pinMode(L, OUTPUT);
    digitalWrite(L, LOW);
    begin(38400);

    String str = "";

    str = sendAtCommand("AT\r\n");
    if (str != "OK\r\n")
    {
        Serial.println("Check Fail!!");
        return false;
    }
    else {}

    str = sendAtCommand("AT+ORGL\r\n");
    if (str != "OK\r\n")
    {
        Serial.println("Set ORGL Fail!!");
        return false;
    }
    else {}

    str = sendAtCommand("AT+ROLE=0\r\n");
    if (str != "OK\r\n")
    {
        Serial.println("Set ROLE Fail!!");
        return false;
    }
    else {}

    str = sendAtCommand("AT+POLAR=1,0\r\n");
    if (str != "OK\r\n")
    {
        Serial.println("Set POLAR Fail!!");
        return false;
    }
    else {}

    str = sendAtCommand("AT+UART=57600,0,0\r\n");
    if (str != "OK\r\n")
    {
        Serial.println("Set UART Fail!!");
        return false;
    }
    else {}

    str = sendAtCommand("AT+NAME=IAMAMAKER\r\n");
    if (str != "OK\r\n")
    {
        Serial.println("Set NAME Fail!!");
        return false;
    }
    else {}

    str = sendAtCommand("AT+PSWD=1234\r\n");
    if (str != "OK\r\n")
    {
        Serial.println("Set PSWD Fail!!");
        return false;
    }
    else {}

#if 0
    sendAtCommand("AT+INIT\r\n");
#endif

    digitalWrite(L, HIGH);
    return true;
}

