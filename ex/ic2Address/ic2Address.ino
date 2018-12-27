#include <Wire.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial) {}
  Serial.println("address scanning");
  byte count = 0;
  Wire.begin();
  for(byte i =1; i < 120; i++) {
    Wire.beginTransmission(i);
    if(Wire.endTransmission() == 0) {
      Serial.print("Found address : ");
      Serial.print(i, DEC);
      Serial.print("( 0X");
      Serial.print(i, HEX);
      Serial.println(")");
      count++;
      delay(10);
    }
  }
  Serial.println("Done.");
  Serial.print("Found it ");
  Serial.print(count, DEC);
  Serial.println(" device(s).");
}

void loop() {
  // put your main code here, to run repeatedly:

}
