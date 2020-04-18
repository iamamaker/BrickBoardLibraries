#include <BrickBoard_TH01.h>

BrickBoard_TH01 sensor(PB);

void setup() {

    Serial.begin(57600);
}

void loop() {

    int state = sensor.read();   // default interval : 2000 msec

    if (state == TH01_OK)
    {
        Serial.print(sensor.getTemperature());
        Serial.print(" [C] \t");
        Serial.print(sensor.getHumidity());
        Serial.println(" [RH]");
    }
    else if (state < TH01_OK)
    {
        Serial.println("Read ERROR!!");
    }
    else
    {
        /* nothing */
    }
}
