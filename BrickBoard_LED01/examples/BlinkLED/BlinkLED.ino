#include <BrickBoard.h>
#include <BrickBoard_LED01.h>

BrickBoard_LED01  myLed(PB);
 
void setup() 
{
  myLed.onBlue();
}
 
void loop() 
{
  /* 300msec 간격으로 빨간색 LED on/off 반복 */
  // blinkRed()의 인자값으로 duration(msec)값을 넘기며, delay() 없이 사용함
  myLed.blinkRed(300);
}
