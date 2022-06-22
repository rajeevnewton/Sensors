#include <Servo.h>

Servo servo1;  // create servo object to control a servo

void setup() {
  Serial.begin(9600);
  servo1.attach(9); 
}

void loop() {
  Serial.println("servo to 0 degrees: ");      

  servo1.write(); //0-180

  delay(500);  

  servo1.write(0); //0-180
  
  delay(500);  
  
}