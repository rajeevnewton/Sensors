const int lm35_pin = A0;	/* LM35 O/P pin */
const int lm35_pin1 = A1;
void setup() {
  Serial.begin(9600);
  pinMode(10, OUTPUT);
  digitalWrite(10, LOW); 
}

void loop() {
  int temp_adc_val;
  float temp_val;
  temp_adc_val = analogRead(lm35_pin);	/* Read Temperature */
  temp_val = (temp_adc_val * 4.88);	/* Convert adc value to equivalent voltage */
  temp_val = (temp_val/10);	/* LM35 gives output of 10mv/°C */
  //lm35 2
   int temp_adc_val1;
  float temp_val1;
  temp_adc_val1 = analogRead(lm35_pin1);	/* Read Temperature */
  temp_val1 = (temp_adc_val1 * 4.88);	/* Convert adc value to equivalent voltage */
  temp_val1 = (temp_val1/10);	/* LM35 gives output of 10mv/°C */

  Serial.print("Temperature = ");
  Serial.print(temp_val);
  Serial.print("\t");
  Serial.print(temp_val1);
  Serial.print(" Degree Celsius\n");
  if(temp_val > temp_val1)
  {
   digitalWrite(10, HIGH);
   delay(5000);
   digitalWrite(10, LOW);
  }
  else
  {
   digitalWrite(10, LOW);
  }
  delay(1000);

}
