#include <Servo.h>
#include <SoftwareSerial.h>
 
SoftwareSerial bt(0, 1);  //tx, rx

Servo myservo1;

void setup()
{
  myservo1.attach(12);
  //Serial.begin(9600);
  bt.begin(9600); //bluetooth
}
void loop()
{
  char i;
  if (bt.available()) {
    i = bt.read();  
    //Serial.write(mySerial.read());
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
