#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <DS1302.h>

DS1302 rtc(2, 3, 4);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void data();
void printTime();

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  //rtc.halt(false);
  //rtc.writeProtect(false);
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.backlight();
  //rtc.setDOW(FRIDAY);
  //rtc.setTime(2, 42, 30);
  //rtc.setDate(31, 12, 2021);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(rtc.getDOWStr());
  Serial.print(rtc.getDateStr());
  Serial.print("--");
  Serial.println(rtc.getTimeStr());

  lcd.clear();
  data();
  printTime();

  delay(1000);
}

void data() {
  lcd.setCursor(0, 0);
  lcd.print(rtc.getDOWStr());
  lcd.setCursor(3, 1);
  lcd.print(rtc.getDateStr());
}

void printTime() {
  lcd.setCursor(8, 0);
  lcd.print(rtc.getTimeStr());
}
