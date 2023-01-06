// Author Rajeev
#include<Servo.h>
Servo Servo1;

//#define LED 2
//#define D0 16 
//#define D1 5
//#define D2 4
//#define D3 0
//#define D4 2
//#define D5 14
//#define D6 12
//#define D7 13
//#define D8 15
//#define RX 3
//#define TX 1
//#define SD2 9
//#define SD3 10


#define D1 2
#define D2 4
#define D3 8 
#define D5 11//servo


void setup() {
  // put your setup code here, to run once:
  Servo1.attach(D5);
  pinMode(D1,OUTPUT);//green led
  pinMode(3,OUTPUT);//green led gnd
  pinMode(D2,OUTPUT);//red led
  pinMode(5,OUTPUT);//red led gnd
 
  pinMode(D3,OUTPUT);// relay pin
  
  digitalWrite(D1,LOW);//green led off
  digitalWrite(3,LOW);//green led gnd
  digitalWrite(D2,LOW);//red led off
  digitalWrite(5,LOW);//red led gnd
  
  digitalWrite(D3,LOW);//relay pin
  Serial.begin(9600);
  }
  

void loop() {
  // put your main code here, to run repeatedly:
    
    //GATE OPEN!
    digitalWrite(D1,HIGH);//green led on
    digitalWrite(D2,LOW);//red led off
    digitalWrite(D3,LOW);//relay off
    Servo1.write(0);
    //Serial.println("HAPPY JOURNEY");
    
    int i = 30;
    while(i>0){
    Serial.print("HAPPY JOURNEY:");
    Serial.println(i);
    i--;  
    delay(1000);
    }
    
    //GATE CLOSING
    digitalWrite(D1,LOW);//green led off
    digitalWrite(D2,HIGH);//red led on
    digitalWrite(D3,LOW);//relay off
    //Serial.println("STOP");
    
    int j = 5;
    while(j>0){
    Serial.print("STOP :");
    Serial.println(j);
    j--;
    delay(1000);
    }
    
    //GATE CLOSED  
    digitalWrite(D1,LOW); //GREEN LED OFF
    digitalWrite(D2,HIGH);//RED LED OFF
    digitalWrite(D3,HIGH);//RELAY ON
    //Serial.println("WAIT FOR SIGNAL");
    Servo1.write(180);
    
    int k=15;
    while(k>0){
    Serial.print("WAIT FOR SIGNAL :");
    Serial.println(k);
    k--;
    delay(1000);
    }
    
    //GATE OPENING  
    digitalWrite(D1,LOW);//green led off
    digitalWrite(D2,LOW);//red led on
    digitalWrite(D3,LOW);//relay on
    //Serial.println("STOP");
    
    int l = 5;
    while(l>0){
    Serial.print("GATE WILL OPEN :");
    Serial.println(l);
    l--;
    delay(1000);
    }
    
    }
