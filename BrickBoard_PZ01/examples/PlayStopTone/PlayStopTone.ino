#include <BrickBoard.h>
#include <BrickBoard_PZ01.h>

BrickBoard_PZ01  myBuzzer(PA);

void setup() 
{
  myBuzzer.playTone(440);
}

void loop() 
{
  delay(5000);  /* 5초 대기 */
  myBuzzer.stopTone();
  
  while(true);
}
