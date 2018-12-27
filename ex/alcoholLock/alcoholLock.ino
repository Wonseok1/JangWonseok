#include <Wire.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 39, 2);
Servo myservo;
int pin_r = 10;
int pin_g = 9;
int pin_sensor = 3;
int pin_alcohol = A0;
int sum = 0;
int avg = 0;
int array [10];
String lcdResult;
boolean start2 = false;
int count = 0;


void setup() {

  pinMode(13, INPUT);

  lcd.begin();
  lcd.backlight();
  lcd.print("Breathalyzer");

  myservo.attach(9);
  myservo.write(120);

  Serial.begin(9600);

  delay(3000);
}

void loop() {
    
    int start = digitalRead(13);
    
    if(start == HIGH){
      lcd.clear();
      lcd.print("Check Alcohol");
      lcd.setCursor(0,1);
      lcd.print("Before Start");
      delay(2000);
      start2 = true;
     
      
    }
    if(start2 ==true && start == LOW){
      alco();
      lcd.clear();
      lcd.print("Alcohol :");
      lcd.print(avg);
      lcd.setCursor(0,1);
      lcd.print(lcdResult);
      lcd.print(" checking");
      count ++;
    }
    
    
  
    //시리얼 표시
    Serial.println("~~~~~~~~~~~~~~~");
    Serial.print("alcohol : ");
    Serial.println(avg);
    sum = 0 ;
    
    
    delay(1000);
    Serial.print(count);
  
    if(count >15){
      if (avg >= 800) {
      lcd.clear();
      lcd.print("Licence Revoke");
      
    } else if (avg >= 500 && avg < 800) {
      lcd.clear();
      lcd.print("Licence Suspend");
      
    } else if (avg < 500 && avg > 300) {
       lcd.clear();
       lcd.print("Warning");
  
    } else {
      lcd.clear(); 
      lcd.print("Engine Start");
      delay(1000);
      myservo.write(0);
    }
  }
}

void alco() {
  int alcohol = analogRead(pin_alcohol);
  //int result = map(alcohol, 0, 1023, 0, 255);


  //알콜지수 10초동안 평균 구하기
  array[9] = array[8];
  array[8] = array[7];
  array[7] = array[6];
  array[6] = array[5];
  array[5] = array[4];
  array[4] = array[3];
  array[3] = array[2];
  array[2] = array[1];
  array[1] = array[0];
  array[0] = alcohol;

  for (int i = 0; i < 10; i++) {
    sum = sum + array[i];
  }
  avg = sum / 10;


  //측정 결과 표시
  if (avg >= 800) {
    lcdResult = "Licence Revoke ";
    
  } else if (avg >= 500 && avg < 800) {
    lcdResult = "Licence Suspend";
    
  } else if (avg < 500 && avg > 300) {
    lcdResult = "Warning";

  } else {
    lcdResult = "Normal";
    
  }
}
