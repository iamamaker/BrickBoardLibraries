/*
 * BT01 Configuration example
 * (Baudrate, Device Name, Password)
 *
 * Baudrate
 *   function
 *     setBaudrate("BAUDRATE,STOP_BIT,PARITY_BIT")
 *   parameters
 *     BAUDRATE : normal baudrate (4800, 9600, ... 115200)
 *     STOP_BIT : 1 bit (0), 2 bits (1)
 *     PARITY_BIT : none (0), odd (1), even (2)
 *
 * Device Name
 *   function
 *     setDeviceName("DEVICE_NAME")
 *   parameter
 *     DEVICE_NAME : default (IAMAMAKER)
 *
 * Password
 *   function
 *     setPassword("PASSWORD")
 *   parameter
 *     PASSWORD : default (1234)
 */

#include <BrickBoard.h>
#include <BrickBoard_BT01.h>
#include <SoftwareSerial.h>

BrickBoard_BT01 bt01(PB);

void setup()
{
  Serial.begin(115200);

  if (bt01.setBaudrate("57600,0,0") == false)
    fail_indication();
  if (bt01.setDeviceName("IAMAMAKER") == false)
    fail_indication();
  if (bt01.setPassword("1234") == false)
    fail_indication();
}

void loop()
{
  /* nothing */
}

void fail_indication()
{
  while(1)
  {
    digitalWrite(L, HIGH);
    delay(300);
    digitalWrite(L, LOW);
    delay(300);
  }
}

