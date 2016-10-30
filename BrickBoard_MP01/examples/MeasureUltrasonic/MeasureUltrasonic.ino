#include <BrickBoard.h> /* Arduino IDE 1.6.6 이후 버전에서는 삭제해도 가능 */
#include <BrickBoard_MP01.h>

BrickBoard_MP01 myMultiPort(PD);

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  double distance = myMultiPort.measureUltrasonic(MP_CM);
  Serial.print("distance : ");
  Serial.print(distance);
  Serial.println(" [cm]");
  delay(500);
}
