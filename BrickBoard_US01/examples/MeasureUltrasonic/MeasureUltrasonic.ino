#include <BrickBoard_US01.h>

BrickBoard_US01 myUltrasonic(PD);

void setup()
{
  Serial.begin(57600);
}

void loop()
{
  double distance = myUltrasonic.measureUltrasonic(MP_CM);
  Serial.print("distance : ");
  Serial.print(distance);
  Serial.println(" [cm]");
  delay(500);
}
