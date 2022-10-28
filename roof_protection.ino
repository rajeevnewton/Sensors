#include<Servo.h>
// constants won't change. They're used here to set pin numbers:
const int buttonPin = D0;     // the number of the pushbutton pin
const int ledPin =  D4;      // the number of the LED pin
const int servoPin =  D3;      // the number of the LED pin
Servo Servo1;

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  Serial.begin(9600);
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  Servo1.attach(servoPin);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
    Serial.println("DRY");
    Servo1.write(0);
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
    Serial.println("RAIN");
    Servo1.write(90);
  }
  delay(300);
}
