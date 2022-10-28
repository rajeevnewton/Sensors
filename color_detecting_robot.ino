#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

int red = 0;  
int green = 0;  
int blue = 0;  
    
void setup()   
{  
  Serial.begin(9600); 
  pinMode(8, OUTPUT);  
  pinMode(9, OUTPUT);  
  pinMode(12, OUTPUT);  
  pinMode(11, OUTPUT);  
  pinMode(10, INPUT);  
  
  digitalWrite(8, HIGH);  
  digitalWrite(9, HIGH); 

   lcd.init();
   lcd.backlight();
}  
    
void loop() 
{  
  digitalWrite(12, LOW);  
  digitalWrite(11, LOW);  
  red = pulseIn(10, digitalRead(10) == HIGH ? LOW : HIGH);  
  digitalWrite(11, HIGH);  
  blue = pulseIn(10, digitalRead(10) == HIGH ? LOW : HIGH);  
  digitalWrite(12, HIGH);  
  green = pulseIn(10, digitalRead(10) == HIGH ? LOW : HIGH);   
 
lcd.clear();
  if (red < blue && red < green && red < 20)
  {  
   Serial.println(" Red Color");  
   lcd.print("Red Color");
  }  

  else if (blue < red && blue < green)   
  {  
   Serial.println(" Blue Color");  
   lcd.print("Blue Color");
  }  

  else if (green < red && green < blue)  
  {  
   Serial.println(" Green Color");  
   lcd.print("Green Color");
  }  
  delay(500);   
 }  
