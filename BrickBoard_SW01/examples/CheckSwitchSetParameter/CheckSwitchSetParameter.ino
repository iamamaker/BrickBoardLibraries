#include <BrickBoard.h>
#include <BrickBoard_SW01.h>
 
BrickBoard_SW01  mySwitch(PC);
 
void setup() 
{
  pinMode(L, OUTPUT);  // digital pin 13
}
 
void loop() 
{
  /* 브릭보드의 LED "L"이 빨간색 스위치를 누른후 약 1초 뒤 이전 상태가 off 이면 on, 
     떼어도 계속 on 됨, 이후 다시 누르면 off 되고 떼어도 계속 off 됨 */
  // 빨간색 스위치 상태를 읽어옴 
  boolean state = mySwitch.checkRed(SWM_TOGGLE, 200);
  digitalWrite(L, state); 
}
