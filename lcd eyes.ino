#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
byte Heart[8] = {
0b00000,
0b01010,
0b11111,
0b11111,
0b01110,
0b00100,
0b00000,
0b00000
};
void setup() {

  lcd.begin();
  lcd.createChar(0, Heart);
  lcd.backlight();
  lcd.clear();
 
}

void loop() {
    lcd.setCursor(3,0);
    lcd.write(byte(0));
    lcd.setCursor(4,0);
    lcd.write(byte(0));
    lcd.setCursor(5,0);
    lcd.write(byte(0));
    lcd.setCursor(12,0);
    lcd.write(byte(0));
    lcd.setCursor(10,0);
    lcd.write(byte(0));
    lcd.setCursor(11,0);
    lcd.write(byte(0));

 
  lcd.setCursor(4,1);
    lcd.write(byte(0));
    lcd.setCursor(3,1);
    lcd.write(byte(0));
    lcd.setCursor(5,1);
    lcd.write(byte(0));
    lcd.setCursor(12,1);
    lcd.write(byte(0));
    lcd.setCursor(10,1);
    lcd.write(byte(0));
    lcd.setCursor(11,1);
    lcd.write(byte(0));
  //lcd.print("uu    uu");

}
