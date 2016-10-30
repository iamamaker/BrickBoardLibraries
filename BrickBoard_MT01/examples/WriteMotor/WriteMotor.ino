#include <BrickBoard.h>
#include <BrickBoard_MT01.h>

BrickBoard_MT01  myMotor(PD);
 
void setup() 
{
}
 
void loop() 
{
  /* 정방향, 브레이크, 역방향, 정지 */
  myMotor.writeMotor(MT_FORWARD);
  delay(1000);
  myMotor.writeMotor(MT_BREAK);
  delay(1000);
  myMotor.writeMotor(MT_REVERSE);
  delay(1000);
  myMotor.writeMotor(MT_STOP);
  delay(1000);
}
