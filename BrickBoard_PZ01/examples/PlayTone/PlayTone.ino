#include <BrickBoard.h>
#include <BrickBoard_PZ01.h>

BrickBoard_PZ01  myBuzzer(PA);

void setup() 
{
  myBuzzer.playTone(440, 5000);
}

void loop() 
{
  pinMode(L, OUTPUT);
  delay(300);
  digitalWrite(L, HIGH);
  delay(300);
  digitalWrite(L, LOW);  
}
