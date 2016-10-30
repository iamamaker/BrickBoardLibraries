/*
 * BT01 Configuration example
 * (Baudrate, Device Name, Password)
 */

#include <BrickBoard.h>
#include <BrickBoard_BT01.h>
#include <SoftwareSerial.h>

BrickBoard_BT01 bt01(PD);

void setup()
{
  Serial.begin(115200);

  if (bt01.setBaudrate("57600,0,0") == false)
    fail_indication();
  if (bt01.setDeviceName("IloveYou") == false)
    fail_indication();
  if (bt01.setPassword("metoo") == false)
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

