
void setup() {
    //only one time
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  
  Serial.println("turning on Led");
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)

  delay(1000);      //1 sec 1000  ms                 // wait for a second
  
  Serial.println("turning on Led");
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW

  delay(1000);                       // wait for a second
}