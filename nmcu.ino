#include<Servo.h>

Servo Servo1;


#define LED 2
#define D0 16 
#define D1 5
#define D2 4
#define D3 0
#define D4 2
#define D5 14
#define D6 12
#define D7 13
#define D8 15
#define RX 3
#define TX 1
#define SD2 9
#define SD3 10


void setup() {
  // put your setup code here, to run once:
  Servo1.attach(D5);
  pinMode(D1,OUTPUT);
  pinMode(D2,OUTPUT);
  pinMode(D4,OUTPUT);
  Serial.begin(9600);
  }
  

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(D4,HIGH);
  Servo1.write(0);
  Serial.println("LED ON"); 
  delay(2000);
  
  digitalWrite(D4,LOW);
  Servo1.write(179);
  Serial.println("LED OFF");
  delay(2000);
    

}
