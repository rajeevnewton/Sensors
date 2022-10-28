#include <Servo.h>
int flag = 0;
Servo myservo;
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {

pinMode(2,INPUT);
pinMode(3,OUTPUT); 
digitalWrite(3,HIGH);
pinMode(7,OUTPUT);
pinMode(8,OUTPUT);
myservo.attach(9);
Serial.begin(9600);
  lcd.begin();
  lcd.backlight();
  lcd.clear();
 
}

void loop() {

  if (digitalRead(2) == 1 && flag == 0)
{
myservo.write(180);
flag = 1;
delay(100);
  lcd.setCursor(2,0);
  lcd.print("WELCOME TO");
  lcd.setCursor(0,1);
  lcd.print("B&B HIGH SCHOOL");

}

if (digitalRead(2) == 1 && flag == 1)
{
myservo.write(90);
flag = 0;
delay(100);
}

delay(100);
}
