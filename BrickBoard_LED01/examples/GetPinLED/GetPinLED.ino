#include <BrickBoard.h>
#include <BrickBoard_LED01.h>

BrickBoard_LED01  myLed(PB);
 
boolean state = false;
 
// getPin() 함수를 통해 PB포트에 대한 아두이노 핀번호 부여 
// CPP signal번호는 Fig-1에서 확인 가능
int bluePin = myLed.getPin(S1);
int redPin = myLed.getPin(S2);
 
void setup() 
{
  pinMode(bluePin, OUTPUT);
  pinMode(redPin, OUTPUT);
  
  digitalWrite(bluePin, HIGH);
}
 
void loop() 
{
  /* 300msec 간격으로 빨간색 LED on/off 반복 */
  digitalWrite(redPin, state);
  state = !state;
  delay(300);
}
