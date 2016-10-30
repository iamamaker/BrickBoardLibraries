#include <BrickBoard.h>
#include <BrickBoard_LED01.h>

BrickBoard_LED01  myLed(PB);
 
void setup() 
{
  // onBlue(), 파란색 LED on
  myLed.onBlue();
}
 
void loop() 
{
  /* 300msec 간격으로 빨간색 LED on/off 반복 */
  // onRed(), 빨간색 LED on
  myLed.onRed();
  delay(300);
  // offRed(), 빨간색 LED off
  myLed.offRed();
  delay(300);
}
