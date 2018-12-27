#include<Servo.h>
Servo myservo;
void setup() {
  // put your setup code here, to run once:
  
  myservo.attach(9);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0; i<180; i++){
    myservo.write(i);
    delay(15);
  }
  for(int i=180; i>0; i--){
    myservo.write(i);
    delay(15);
  }
}
