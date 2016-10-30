#include <BrickBoard.h>
#include <BrickBoard_VR01.h>

BrickBoard_VR01  myVr(PC);

unsigned long pre_msec = 0;
boolean state = false;

void setup()
{
  pinMode(L, OUTPUT);
}

void loop()
{
  unsigned long cur_msec = millis();
  int duration = myVr.readPotentiometer();

  if (cur_msec - pre_msec >= duration)
  {
    digitalWrite(L, state);
    state = !state;
    pre_msec = cur_msec;
  }
}
