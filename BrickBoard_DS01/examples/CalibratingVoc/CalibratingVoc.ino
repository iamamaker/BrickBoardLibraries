#include <BrickBoard_DS01.h>

BrickBoard_DS01 dustSensor(PC);

unsigned long previousMillis = 0;

void setup() {

  Serial.begin(57600);
}

void loop() {

  Serial.print("Voc Calibrating .");

  while(!dustSensor.calibrationVoc())
  {
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= 1000)
    {
      previousMillis = currentMillis;
      Serial.print(".");
    }
  }
  Serial.println(" Done!!");
  Serial.print("Voc = ");
  Serial.println(dustSensor.getVoc());

  for(;;);
}
