//Includes the Arduino Stepper Library
#include <Stepper.h>

// Defines the number of steps per rotation
const int stepsPerRevolution = 1200; //2038

// Creates an instance of stepper class
// Pins entered in sequence IN1-IN3-IN2-IN4 for proper step sequence
Stepper myStepper = Stepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
  // Nothing to do (Stepper Library sets pins as outputs)
  Serial.begin(9600);
}
//vcc to 9v
//gnd to -9v
void loop() {
  // Rotate CW slowly
  myStepper.setSpeed(20);
  myStepper.step(stepsPerRevolution);
  Serial.println("clock");
  delay(200);
  
  // Rotate CCW quickly
  myStepper.setSpeed(20);
  myStepper.step(-stepsPerRevolution);
  Serial.println("counter clock");
  delay(200);
}