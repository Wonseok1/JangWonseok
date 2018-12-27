int pin_sensor = 3;
int pin_led = 7;

void setup() {
  Serial.begin(9600);
  pinMode(pin_led, OUTPUT);
  pinMode(pin_sensor, INPUT);
}

void loop() {
  int reedSW = digitalRead(pin_sensor);

  if(reedSW == LOW) {
    digitalWrite(pin_led, HIGH);
  } else {
    digitalWrite(pin_led, LOW);
  }
  Serial.print("reed : ");
  Serial.println(reedSW);
  delay(1000); 
}
