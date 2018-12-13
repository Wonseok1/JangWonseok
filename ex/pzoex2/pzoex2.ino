int pzo = 6;
int diy = 250;


void setup() {
  // put your setup code here, to run once:
  pinMode(pzo, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(pzo, 64);
  delay(diy);
  analogWrite(pzo, 128);
  delay(diy);
  analogWrite(pzo, 255);
  delay(diy);
}
