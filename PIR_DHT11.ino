// Example testing sketch for various DHT humidity/temperature sensors
// Written by ladyada, public domain

// REQUIRES the following Arduino libraries:
// - DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library
// - Adafruit Unified Sensor Lib: https://github.com/adafruit/Adafruit_Sensor

#include "DHT.h"

#define DHTPIN 2     // Digital pin connected to the DHT sensor
#define PIR 3     // Digital pin connected to the PIR
#define LED 12     // Digital pin connected to the LED
#define Buzz 13     // Digital pin connected to the BUZZER

int val= 0; // Initializing the value as zero at the beginning
  
#define DHTTYPE DHT11   // DHT 11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  pinMode(Buzz, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(PIR, INPUT);  
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));

  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements.
  delay(1500);
  //////////////////////////////////////////////////////////////////////////////// PIR
  
  val = digitalRead(PIR); // The value read from PIR pin 3 will be assigned to 'val'
  if(val == HIGH){
  digitalWrite(LED, HIGH); // Turn LED ON
  digitalWrite(Buzz, HIGH); // Turn Buzzer ON
  Serial.println("Movement Detected"); // Print this text in Serial Monitor
  delay(500);
  }
  digitalWrite(LED, LOW); // Turn LED ON
  digitalWrite(Buzz, LOW); // Turn Buzzer ON

  //////////////////////////////////////////////////////////////////////////////// PIR
  
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.println(F("°C "));
}
