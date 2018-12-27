#include <Servo.h>

Servo myservo;

void setup() {
  // put your setup code here, to run once:
  pinMode(8, INPUT);
  myservo.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
  myservo.write(0);
  int val = analogRead(A0);
  int rad = map(val, 0, 1023, 0, 180);
  if(digitalRead(8)==HIGH){
    myservo.write(rad);
  }
  
  delay(15);
}
