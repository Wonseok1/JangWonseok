int ledPin = 13;
int detectPin = 7;
int sensor_state = LOW;
int input = LOW;
int count = 0;
int i=0;
void list[] = {red, green, blue};

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(detectPin, INPUT);
  Serial.begin(9600);
  
  attachInterrupt(0, list[i], RISING);
  attachInterrupt(1, inter, FALLING);
}

void inter(){
  
  i++;
  if(i=3){
    i=0;
  }
}

void red(){
      analogWrite(10, 0);
      analogWrite(11, 255);
      analogWrite(12, 255);
      count++;
}

void blue(){
      analogWrite(10, 255);
      analogWrite(11, 255);
      analogWrite(12, 0);
      count++;
}

void green(){
      analogWrite(10, 255);
      analogWrite(11, 0);
      analogWrite(12, 255);
      count++;
}

void loop() {
  input = digitalRead(detectPin);
  if(input == HIGH) {

   
    if(count%3 == 1){
      red();
    }else if(count%3 ==2){
      blue();
    }else if(count%3 ==0){
      green();
    }
    Serial.println("Motion detected!");
    Serial.print(count);
    Serial.println("명 지나감");
    
  } else {
     analogWrite(10, 255);
     analogWrite(11, 255);
     analogWrite(12, 255);
    Serial.println("Motion end!");
  }
  delay(1000);
} 
