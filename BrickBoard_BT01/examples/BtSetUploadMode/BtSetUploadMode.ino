/* 
 * BT01을 이용 무선업로드 기능을 위해 
 * BT01의 설정을 변경하는 예제
 */

#include <BrickBoard_BT01.h>

BrickBoard_BT01 bt01(PD);


void setup() 
{
  Serial.begin(115200);

  if (bt01.setUploadMode() == false)
  {
    while(1)
    {
      digitalWrite(L, HIGH);
      delay(200);
      digitalWrite(L, LOW);
      delay(200);
    }
  }  
}

void loop()
{
  /* nothing */
}
