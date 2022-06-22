///////////////////////////////////////////////////////
#include <Servo.h>

Servo servo1;  // create servo object to control a servo

int left = 0;
int front = 0;
int right = 0;

///////////////////////////////////////////////////////
int inches = 0;

int cm = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  Serial.begin(9600);
  servo1.attach(9); 
}

void loop()
{
  /////////////////////////////////////////////////////////////////////
  Serial.println("servo to 0 degrees: ");      
  servo1.write(0); //0 left
  calculate_distanceL();
  delay(1000);  
  
  Serial.println("servo to 90 degrees: ");   
  servo1.write(90); // 90 front
  calculate_distanceF();
  
  delay(1000);
   
  Serial.println("servo to 180 degrees: ");   
  servo1.write(180); //180 left
  calculate_distanceR();

  delay(1000); 

  Serial.println("servo to 90 degrees: ");   
  servo1.write(90); // 90 front
    
  calculate_distanceF();
  
  delay(1000);
  

  //////////////////////////////////////////////////////////////
 Serial.println("LEFT FRONT RIGHT ");   
 Serial.println(left);
 Serial.println(front);
 Serial.println(right);
  
}





void calculate_distanceL(){
  left = 0.01723 * readUltrasonicDistance(7, 7);
  // convert to inches by dividing by 2.54
  inches = (cm / 2.54);
  

  delay(100); // Wait for 100 millisecond(s)

}

void calculate_distanceF(){
  front = 0.01723 * readUltrasonicDistance(7, 7);
  // convert to inches by dividing by 2.54
  inches = (cm / 2.54);
  

  delay(100); // Wait for 100 millisecond(s)

}

void calculate_distanceR(){
  right = 0.01723 * readUltrasonicDistance(7, 7);
  // convert to inches by dividing by 2.54
  inches = (cm / 2.54);
  
  delay(100); // Wait for 100 millisecond(s)

}