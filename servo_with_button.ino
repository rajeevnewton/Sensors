#include <Servo.h>
int flag = 0;
Servo myservo;

void setup() {

pinMode(2,INPUT);

pinMode(7,OUTPUT);
pinMode(8,OUTPUT);
myservo.attach(9);
Serial.begin(9600);

}


void loop() {

  if (digitalRead(2) == 1 && flag == 0)
{
digitalWrite(8,LOW);
digitalWrite(7,HIGH);
Serial.println("move1");
delay(5000);

digitalWrite(8, LOW);
digitalWrite(7, LOW);
Serial.println("stop2");
flag = 1;
}

if (digitalRead(2) == 1 && flag == 1)
{
digitalWrite(8,HIGH);
digitalWrite(7,LOW);
Serial.println("move2");
delay(5000);
digitalWrite(8, LOW);
digitalWrite(7, LOW);
Serial.println("stop2");
flag = 0;
}
delay(100);
}
