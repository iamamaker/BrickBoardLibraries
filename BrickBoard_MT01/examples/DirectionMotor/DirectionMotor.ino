#include <BrickBoard.h>
#include <BrickBoard_MT01.h>

BrickBoard_MT01  myMotor(PD);
 
void setup() 
{
}
 
void loop() 
{
  /* 정방향, 브레이크, 역방향, 정지 */
  myMotor.forwardMotor();
  delay(1000);
  myMotor.breakMotor();
  delay(1000);
  myMotor.reverseMotor();
  delay(1000);
  myMotor.stopMotor();
  delay(1000);
}
