#include <Wire.h>                
#include <LiquidCrystal_I2C.h>  

LiquidCrystal_I2C lcd(0x27, 16, 2); 

void setup()
{
  Serial.begin(9600);
  
  lcd.begin();
  lcd.backlight();

  lcd.print("light value : "); 
}

void loop() { 
  int light = analogRead(A0);
  Serial.println(light);
  
  lcd.setCursor(0,1);
  lcd.print(light);

  lcd.scrollDisplayRight();
  delay(1000);
}
