#include <BrickBoard_NP01.h>

BrickBoard_NP01 rainbow(PC);

uint8_t led_idx = 4;
int8_t color_idx = 0;
boolean path = false;

void setup() {
  rainbow.begin();

  // all off
  rainbow.clear();
  rainbow.show();
}

void loop() {
  rainbow.setLedColor(led_idx, rainbow.simpleColorSpectrum(color_idx));
  rainbow.setBrightness(100);  //밝기를 약 절반이하로 줄임 (0~255)
  rainbow.show();
  delay(50);

  led_idx--;
  if (led_idx == 0) {
    led_idx = 4;
  }

  if (!path) {
    color_idx++;
  } else {
    color_idx--;
  }

  if (color_idx >= 24 || color_idx <= 0) {
    if (!path) {
      path = true;
    } else {
      path = false;
    }
  }
}
