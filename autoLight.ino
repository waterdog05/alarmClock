#include<Servo.h>
#include <SoftwareSerial.h>
 
SoftwareSerial mySerial(0, 1);  //시리얼 통신을 위한 객체선언

Servo myservo1;

void setup()
{
  myservo1.attach(12);
  Serial.begin(9600);   //시리얼모니터
  mySerial.begin(9600); //블루투스 시리얼
}
void loop()
{
  char i;
  if (mySerial.available()) {
    i = mySerial.read();  
    Serial.write(mySerial.read());  //블루투스측 내용을 시리얼모니터에 출력  
  }
  if (i == '1'){
    myservo1.write(50);
    delay(500);
  }
  else if (i == '0') {
    myservo1.write(-40);
    delay(500);
  }
}
