#include <BrickBoard.h>
#include <BrickBoard_IR01.h>

BrickBoard_IR01  myIr(PB);

void setup()
{
  pinMode(L, OUTPUT);
  myIr.onIred();
}

void loop()
{
  boolean det = myIr.readPhotoTr();

  if (det)
    digitalWrite(L, HIGH);
  else
    digitalWrite(L, LOW);
}