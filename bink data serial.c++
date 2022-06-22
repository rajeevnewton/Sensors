
void setup() {
    //only one time
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  
 Serial.println("1 turning off Led");
 digitalWrite(13,LOW);
 delay(500);
 Serial.println("1 turning on Led");
 digitalWrite(13,HIGH);
 delay(500);
 Serial.println("2 turning off Led");
 digitalWrite(13,LOW);
 delay(500);
 Serial.println("2 turning on Led");
 digitalWrite(13,HIGH);
 delay(500);
 Serial.println("3 turning off Led");
 digitalWrite(13,LOW);
 delay(500);
 Serial.println("3 turning on Led");
 digitalWrite(13,HIGH);
 delay(500);
}

// the loop function runs over and over again forever
void loop() {
  
  Serial.println("turning on Led");
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)

  delay(2000);    //2 sec             
  
  Serial.println("turning off Led");
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW

  delay(2000);
}