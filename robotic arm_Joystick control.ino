#include <Servo.h>



Servo servoA; //waist
Servo servoB; //sholder
Servo servoC; //elbow
Servo servoD; //wrist roll
Servo servoE; //wrist pitch
Servo servoF; //gripper


  
int JoysiticA = A0; 
int JoysiticB = A1; 
int JoysiticC = A2; 
int JoysiticD = A3;
int JoysiticE = A4;
int JoysiticF = A5;


void setup()
{

// Pins for the servos
servoA.attach(5);
servoB.attach(6);
servoC.attach(7);
servoD.attach(8);
servoE.attach(9);
servoF.attach(10);

}



void loop(){

int s =10; // How fast you want the arm to go ???

JoysiticA= analogRead(A0);
JoysiticB= analogRead(A1);
JoysiticC= analogRead(A2);
JoysiticD= analogRead(A3);
JoysiticE= analogRead(A5);
JoysiticF= analogRead(A6);
 // Joysitics

 // the servos have  arange of motion defined ServoA 120 to 50 ServoB 110 to 10  ServoC 110

 
  if (JoysiticA > 600) {
     int i = servoA.read();
     if (i<170) {
      i=i+1;
          servoA.write(i);
          delay(s); }                            
    
  }
    if (JoysiticA < 400) {
     int i = servoA.read();
     if (i>10) {
      i=i-1;
          servoA.write(i);
          delay(s); }                           
    
  }
  
  if (JoysiticB < 400) {
     int i = servoB.read();
     if (i<170) {
      i=i+1;
          servoB.write(i);
          delay(s); }                           
    
  } 
    if (JoysiticB > 600) {
     int i = servoB.read();
     if (i>10) {
      i=i-1;
          servoB.write(i);
          delay(s); }                            
    
  }
    if (JoysiticC < 400) {
     int i = servoC.read();
     if (i<170) {
      i=i+1;
          servoC.write(i);
          delay(s); }                         
    
  }
    if (JoysiticC > 600) {
     int i = servoC.read();
     if (i>10) {
      i=i-1;
          servoC.write(i);
          delay(s); }                            
    
  }
    if (JoysiticD > 600) {
     int i = servoD.read();
     if (i<170) {
      i=i+1;
          servoD.write(i);
          delay(s+10); }                           
    
  } 
    if (JoysiticD <400) {
     int i = servoD.read();
     if (i>10) {
      i=i-1;
          servoD.write(i);
          delay(s+10); }                            
    
  }
    if (JoysiticE > 600) {
     int i = servoE.read();
     if (i<170) {
      i=i+1;
          servoE.write(i);
          delay(s+10); }                            
    
  }
    if (JoysiticE <400) {
     int i = servoE.read();
     if (i>10) {
      i=i-1;
          servoE.write(i);
          delay(s+10); }                           
    
  }
    if (JoysiticF > 600) {
     int i = servoF.read();
     if (i<170) {
      i=i+1;
          servoF.write(i);
          delay(s+10); }                            
    
  }
    if (JoysiticF <400) {
     int i = servoF.read();
     if (i>10) {
      i=i-1;
          servoF.write(i);
          delay(s+10); }                            
    
  }
 
  }
