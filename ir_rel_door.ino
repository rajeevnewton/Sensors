void setup() {

pinMode(2,INPUT);

pinMode(7,OUTPUT);
pinMode(8,OUTPUT);

Serial.begin(9600);

}


void loop() {

  if (digitalRead(2) == 1)
{

 Serial.println(digitalRead(2));

digitalWrite(8,LOW);
digitalWrite(7,HIGH);
Serial.println("move1");
delay(5000);
digitalWrite(8,HIGH);
digitalWrite(7,LOW);
Serial.println("move2");
delay(5000);
digitalWrite(8, LOW);
digitalWrite(7, LOW);
Serial.println("stop2");
}
delay(100);
}
