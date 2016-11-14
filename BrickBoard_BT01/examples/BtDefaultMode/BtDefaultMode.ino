/*
 * BT01 Default Configuration example
 */

#include <BrickBoard_BT01.h>

BrickBoard_BT01 defaultBT01(PC); /* user selection (PA, PB, PC, PD) */


void setup()
{
  Serial.begin(115200);

  if (defaultBT01.setDefaultMode() == false)
  {
    while(1)
    {
      digitalWrite(L, HIGH);
      delay(100);
      digitalWrite(L, LOW);
      delay(100);
    }
  }
}

void loop()
{
  /* nothing */
}
