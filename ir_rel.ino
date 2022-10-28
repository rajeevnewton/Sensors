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

  digitalWrite(7,HIGH);
  delay(1000);
  digitalWrite(8,LOW);

}  


else{

    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);

    }

}
