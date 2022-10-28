#include<SoftwareSerial.h>
int sensorPin=A0;
int sensorValue = 0;
int led = 3;
void setup() {
 pinMode(led, OUTPUT);
 Serial.begin(9600);
 // put your setup code here, to run once:
}
void loop() {
 
 sensorValue = analogRead(sensorPin);
 Serial.println(sensorValue);
 if(sensorValue > 200)
 {
   delay(sensorValue);
 Serial.println("LED light on");
   digitalWrite(led,HIGH);
   delay(50);
 }
 else{
 digitalWrite(led,LOW);
   Serial.println("LED light off");
  delay(50);
 }
 // put your main code here, to run repeatedly:
}
