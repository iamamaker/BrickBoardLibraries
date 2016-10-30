#include <BrickBoard.h>
#include <BrickBoard_SW01.h>
 
BrickBoard_SW01  mySwitch(PC);
 
void setup() 
{
  pinMode(L, OUTPUT);  // digital pin 13
}
 
void loop() 
{
  /* 브릭보드의 LED "L"이 파란색 스위치를 누르면 on, 떼면 off 됨 */
  // 파란색 스위치 상태를 읽어옴 
  boolean state = mySwitch.readBlue();
  digitalWrite(L, state); 
}

