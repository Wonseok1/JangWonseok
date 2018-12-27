#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 39, 2);

int pin_r = 10;
int pin_g = 9;
int pin_alcohol = A0;
int sum = 0;
int avg = 0;
int array [10];
String lcdResult;


void setup() {
  lcd.begin();
  lcd.backlight();
  Serial.begin(9600);
  lcd.print("Breathalyzer");
  delay(3000);
}

void loop() {
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
  array[0]= alcohol;
  
  for(int i = 0; i<10; i++){
    sum = sum+array[i];
  }
   avg = sum/10;


  //측정 결과 표시
  if(avg >= 800){
    lcdResult = "Licence Revoke ";
  }else if(avg >=500 && avg <800){
    lcdResult = "Licence Suspend";
  }else if(avg < 500 && avg > 300){
    lcdResult = "Warning";
  }else{
    lcdResult = "Normal";
  }
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("alcohol :");
  lcd.print(avg);
  lcd.setCursor(0,1);
  lcd.print(lcdResult);

  //시리얼 표시
  Serial.println("~~~~~~~~~~~~~~~");
  Serial.print("alcohol : ");
  Serial.println(avg);
  Serial.print("평균: ");
  Serial.println(avg);
  sum =0 ;
  delay(1000);
}
