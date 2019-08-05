#include <BrickBoard_US01.h>

BrickBoard_US01 myUltrasonic(PD);

void setup()
{
  Serial.begin(57600);
}

void loop()
{
  double distance = myUltrasonic.measureUltrasonic(MP_MM, 10, 20);
  Serial.print("distance : ");
  Serial.print(distance);
  Serial.println(" [mm]");
  delay(500);
}
