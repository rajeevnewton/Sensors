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

int i = 30;
int j = 5;
int k = 15;
int l = 5;

void setup() {
  // put your setup code here, to run once:
  Servo1.attach(D5);
  pinMode(D1,OUTPUT);//green led
  pinMode(D2,OUTPUT);//red led
  pinMode(D3,OUTPUT);
  pinMode(D4,OUTPUT);
  digitalWrite(D1,LOW);//green led off
  digitalWrite(D2,LOW);//red led off
  digitalWrite(D3,LOW);
  Serial.begin(9600);
  }
  

void loop() {
  // put your main code here, to run repeatedly:
//  digitalWrite(D4,HIGH);
//  Servo1.write(0);
//  Serial.println("LED ON"); 
//  delay(2000);
//  
//  digitalWrite(D4,LOW);
//  Servo1.write(179);
//  Serial.println("LED OFF");
//  delay(2000);

    //GATE OPEN!
    digitalWrite(D1,HIGH);//green led on
    digitalWrite(D2,LOW);//red led off
    digitalWrite(D3,LOW);//relay off
    Servo1.write(0);
    Serial.println("HAPPY JOURNEY");
    Serial.println("GREEN LED ON");
    Serial.println("RED LED OFF");
   
    while(i>0){
    //Serial.print("HAPPY JOURNEY:");
    Serial.println(i);
    i--;  
    delay(1000);
    }
    if(i == 0){
      i = 30;
    }
    
    //GATE CLOSING
    digitalWrite(D1,LOW);//green led off
    digitalWrite(D2,HIGH);//red led on
    digitalWrite(D3,LOW);//relay off
    Serial.println("STOP");
    Serial.println("GREEN LED OFF");
    Serial.println("RED LED ON");
    
    while(j>0){
    //Serial.print("STOP :");
    Serial.println(j);
    j--;
    delay(1000);
    }
    if(j == 0){
      j = 5;
    }
    
    //GATE CLOSED  
    digitalWrite(D1,LOW); // green led off
    digitalWrite(D2,HIGH);// red led on
    digitalWrite(D3,HIGH);// realy on
    Serial.println("WAIT FOR SIGNAL");
    Serial.println("GREEN LED OFF");
    Serial.println("RED LED ON");
    Servo1.write(180);
    
    while(k>0){
    //Serial.print("WAIT FOR SIGNAL :");
    Serial.println(k);
    k--;//decrement
    delay(1000);
    }
    if(k == 0){
      k = 15;
    }
    
    //GATE OPENING  
    digitalWrite(D1,LOW);//green led off
    digitalWrite(D2,LOW);//red led on
    digitalWrite(D3,LOW);//relay on
    Serial.println("STOP");
    Serial.println("GREEN LED OFF");
    Serial.println("RED LED ON");
    
    while(l>0){
    //Serial.print("GATE WILL OPEN :");
    Serial.println(l);
    l--;
    delay(1000);
    }
    if(l == 0){
      l = 5;
    }
    
    }
