//sketch created by Akshay Joseph
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{

  lcd.begin();


  lcd.backlight();
  lcd.clear();
  lcd.setCursor(6,0);
  lcd.print("HAPPY");
  lcd.setCursor(0,1);
  lcd.print("VINAYAKACHAVITHI");
}

void loop()
{
  
}
