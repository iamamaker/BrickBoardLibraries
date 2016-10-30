#include <BrickBoard.h> /* Arduino IDE 1.6.6 이후 버전에서는 삭제해도 가능 */
#include <BrickBoard_MP01.h>

BrickBoard_MP01 myMultiPort(PD);

#include <Servo.h>
Servo myServo;

void setup() 
{
  myServo.attach(myMultiPort.getPin(S2));
}

void loop() 
{
  for (int i = 0; i <= 180; i++)
  {
    myServo.write(i);
    delay(10);
  }
  
  for (int i = 180; i > 0; i--)
  {
    myServo.write(i);
    delay(10);
  }
}
