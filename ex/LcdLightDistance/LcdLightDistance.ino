#include <Wire.h>                
#include <LiquidCrystal_I2C.h>  


LiquidCrystal_I2C lcd(0x27, 16, 2); 
int trig_pin = 2;
int echo_pin = 3;

void setup() {
  // put your setup code here, to run once:

  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  pinMode(13,INPUT);
  pinMode(12, INPUT);
  
  Serial.begin(9600);

  lcd.begin();
  lcd.backlight();

}

void loop() {

   lcd.clear();
   lcd.home();
   lcd.print("select button");
   delay(1000);
  // put your main code here, to run repeatedly:
 

  if(digitalRead(12==HIGH)){//조도센서
    lcd.clear();
    lcd.home();
    lcd.print("light value : ");
    int light = analogRead(A0);
    Serial.println(light);
    lcd.setCursor(0,1);
    lcd.print(light); 
    lcd.scrollDisplayRight();
    delay(1000);
    
  }
   if(digitalRead(13==HIGH)){//거리조절센서
    lcd.clear();
    lcd.home();
    lcd.print("distance value : "); 
    lcd.setCursor(0,1);
    lcd.print(getDistance(trig_pin, echo_pin));   
    delay(1000);
  }


}

int getDistance(int aTrig_pin, int aEcho_pin) {
  digitalWrite(aTrig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(aTrig_pin, LOW);
  long duration = pulseIn(aEcho_pin, HIGH); 
  long distance = duration / 58.2;
  Serial.println(distance);
  delay(100);

  return distance;
}
