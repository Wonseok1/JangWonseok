#include <Wire.h>                
#include <LiquidCrystal_I2C.h>  
LiquidCrystal_I2C lcd(0x27, 16, 2); 

void setup() {
  // put your setup code here, to run once:
  lcd.begin();
  lcd.backlight();

}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.clear();
  lcd.home();
  lcd.print("(^o^)  @(^-')");
  delay(500);
  lcd.clear();
  lcd.print("('-^)@  (^o^)");
  delay(500);
}
