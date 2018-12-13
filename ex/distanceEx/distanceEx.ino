int trig_pin = 2;
int echo_pin = 3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);
  long duration = pulseIn(echo_pin, HIGH); //음파가 돌아와서 신호를 주는 시간
  if(duration ==0){
    return;
  }
  long distance = duration / 58.2;
  Serial.println(distance);

    if(distance>=5 && distance<10){
      digitalWrite(13,HIGH);
      digitalWrite(12,LOW);
    }else{
      digitalWrite(12,HIGH);
      digitalWrite(13,LOW);
    }
      delay(1000);
 


  
}
