#include <BrickBoard.h>
#include <BrickBoard_LED01.h>

BrickBoard_LED01  myLed(PB);
 
boolean state = false;
 
void setup() 
{
  // writeBlue()는 인자값에 따라 on/off 됨, true(or HIGH or 1)는 on
  myLed.writeBlue(true);
}
 
void loop() 
{
  /* 300msec 간격으로 빨간색 LED on/off 반복 */
  // writeRed()의 인자값을 300msec 간격으로 토글시켜 on/off 반복함
  myLed.writeRed(state);
  state = !state; 
  delay(300);
}
