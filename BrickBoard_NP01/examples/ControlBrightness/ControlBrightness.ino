#include <BrickBoard_NP01.h>

BrickBoard_NP01 myLed(PA);

void setup() {
  myLed.begin();
}

void loop() {
  myLed.setLedColor(1, C_RED);
  myLed.setLedColor(2, C_GREEN);
  myLed.setLedColor(3, C_BLUE);
  myLed.setLedColor(4, C_WHITE);

  myLed.setBrightness(10);  //모든 LED에 동일하게 밝기가 적용됨.
  myLed.show();
  delay(1000);

  myLed.setBrightness(50);
  myLed.show();
  delay(1000);

  myLed.setBrightness(150);
  myLed.show();
  delay(1000);

  myLed.setBrightness(255);
  myLed.show();
  delay(1000);

  myLed.clear();  //모든 LED를 초기화함
  myLed.show();   //초기화 후 show() 메소드를 통해 모두 off함.
  delay(2000);
}
