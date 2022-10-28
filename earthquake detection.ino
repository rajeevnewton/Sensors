const int buzzer = 8; //Buzzer connected to pin 8 of Arduino uno / mega
int sensor;           //Variable to store analog value (0-1023)


void setup()
{
	Serial.begin(9600);      //Only for debugging
	pinMode(buzzer, OUTPUT);
}

void loop()
{
	sensor = analogRead(A0);
	//While sensor is not moving, analog pin receive 1023~1024 value
	if (sensor<1022){
		tone(buzzer, 500);
		Serial.print("vibration detected");
		Serial.println(sensor);
	}
	
	else{ 
		noTone(buzzer);
		Serial.print("vibration not detected");
		Serial.println(sensor);
	}
	
	
	delay(100); //Small delay
}