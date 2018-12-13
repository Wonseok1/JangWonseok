void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  int light = analogRead(A0);
  int ledLight = map(light, 0, 50, 255, 0);//조도값, 원래값의 최소값
  //원래값의 최대값, 변환되는값의 최소값, 최대값
  analogWrite(9, ledLight);
  delay(500);
}
