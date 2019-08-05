#include <BrickBoard_NP01.h>

BrickBoard_NP01 np01(PE);


void setup() {
  np01.begin();
}

void loop() {
  // NP01 모듈의 LED 1~4을 랜덤으로 선택하고 선택된 LED의 색상을 랜덤으로 출력하도록 설정함
  np01.setLedColor(random(1, 5), np01.simpleColorSpectrum(random(0, 25)));
  np01.show();
  delay(100);
  
  np01.clear();
  np01.show();
}
