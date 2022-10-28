const int AOUTpin=A3;//the AOUT pin of the hydrogen sensor goes into analog pin A0 of the arduino
const int BUZZER=13;//the anode of the BUZZER connects to digital pin D13 of the arduino

int value;

void setup() {
Serial.begin(9600);//sets the baud rate
pinMode(BUZZER, OUTPUT);//sets the pin as an output of the arduino
}

void loop()
{
value= analogRead(AOUTpin);//reads the analaog value from the hydrogen sensor's AOUT pin
Serial.print("Hydrogen value: ");
Serial.println(value);//prints the hydrogen value
delay(100);
if (value >= 150){
digitalWrite(BUZZER, HIGH);//if limit has been reached, BUZZER turns on as status indicator
Serial.print(" GAS DETECTED ");
}
else{
digitalWrite(BUZZER, LOW);//if threshold not reached, BUZZER remains off
Serial.print(" NORMAL ");
}
}