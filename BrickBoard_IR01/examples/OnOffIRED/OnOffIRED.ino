#include <BrickBoard.h>
#include <BrickBoard_IR01.h>

BrickBoard_IR01  myIr(PB);

void setup()
{
  myIr.onIred();
}

void loop()
{
  delay(5000); /* 5초 대기 후 IRED Off */
  myIr.offIred();
}