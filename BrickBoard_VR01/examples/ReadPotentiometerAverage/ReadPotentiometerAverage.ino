#include <BrickBoard.h>
#include <BrickBoard_VR01.h>

BrickBoard_VR01  myVr(PC);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  unsigned int recv = myVr.readPotentiometer(10);

  Serial.println(recv);
  delay(300);
}

