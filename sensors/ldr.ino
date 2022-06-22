int LDR = 2;
int sensorValue = 0;
int led = 13;

void setup() {
 pinMode(led, OUTPUT);
 Serial.begin(9600);
 // put your setup code here, to run once:
}
void loop() {
  
 Serial.println("Welcome to LDR tutorial");
 
 sensorValue = digitalRead(LDR);
 Serial.println(sensorValue);
 
 if(sensorValue == HIGH)
 {
   Serial.println("LED light on");
   digitalWrite(led,HIGH);
   delay(1000);
 }
 else{
 Serial.println("LED light off");
 digitalWrite(led,LOW);
 delay(1000);
 // put your main code here, to run repeatedly:
 }
 
}
