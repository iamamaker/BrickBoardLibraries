#include <BrickBoard_DS01.h>

BrickBoard_DS01 dustSensor(PC);

unsigned long prevMillisOfDisplay = 0;

void setup() {

  Serial.begin(57600);

  dustSensor.setVoc(0.50);  //calibrated Voc
}

void loop() {

  float value = dustSensor.getDustDensity();

  if (millis() - prevMillisOfDisplay >= 500) {
    prevMillisOfDisplay = millis();

    Serial.print("Dust Density = ");
    Serial.print(value);
    Serial.println(" [ug/m3]");
  }
}
