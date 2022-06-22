const int buzzer=7;
int i;
void setup() {

pinMode(buzzer,OUTPUT);
pinMode(2,INPUT);  
}

void loop() {


if(digitalRead(2)==1)
{
  digitalWrite(buzzer,HIGH);
  
}

else
{
  digitalWrite(buzzer,LOW);
  
}


}
