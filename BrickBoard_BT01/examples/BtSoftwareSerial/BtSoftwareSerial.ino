//#include <BrickBoard.h>
//#include <SoftwareSerial.h>
//아두이노 IDE 1.6.6 이후 버전에서 삭제 가능

#include <BrickBoard_BT01.h>

BrickBoard_BT01  myBtSerial(PB);


unsigned long cnt = 0;

void setup()
{
  /* HardwareSerial */
  Serial.begin(115200); /* USB 통한 시리얼 인터페이스 */

  /* SoftwareSerial */
  myBtSerial.begin(9600); /* BT01에 설정된 Baudrate */
}

void loop() 
{
  Serial.print("This is HardwareSerial!! - ");
  Serial.println(cnt);

  myBtSerial.print("This is SoftwareSerial!! - ");
  myBtSerial.println(cnt++);

  delay(1000); 
}

