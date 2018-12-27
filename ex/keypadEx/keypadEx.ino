#include <Key.h>
#include <Keypad.h>

#include <keypad.h>

const byte ROWS = 4;
const byte COLS = 4;


byte rowPins[ROWS] = { 9, 8, 7, 6 };
byte colPins[COLS] = { 5, 4, 3, 2 };
String pass ="";


char keys [ROWS][COLS] = {
  {'1','2','3','A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
Keypad keypad = Keypad(makeKeymap(keys), rowPins,colPins, ROWS, COLS);
int led_pin = 13;
boolean blink = false;

void listener(KeypadEvent key) {
  switch(keypad.getState()) {
    case PRESSED:
      if(key == '#') {
        digitalWrite(led_pin, true);
        Serial.println("PRESSED");
      }
      break;
    case RELEASED:
      if(key == '*') {
        digitalWrite(led_pin, false);
        Serial.println("RELEASED"); 
        pass = "";
        blink = true; 
        delay(1000);
        blink = false;
      }
      break;
    case HOLD:
      if(key == '*') {
        Serial.println("HOLDING");
      }
  }
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led_pin, OUTPUT);
  keypad.addEventListener(listener);
}

void loop() {
  // put your main code here, to run repeatedly:

  char key = keypad.getKey();
  
  
  if(key != NO_KEY) {
    Serial.println(key);
    pass = pass+key;
   
    Serial.println("pass"+pass);
    
    
    if(pass == "1234A"){
      digitalWrite(13, HIGH);
      
    }else{
      digitalWrite(13, LOW);
      
    }

    if(pass.length() > 5){
      pass = "";
      Serial.println(pass);
    }
   
  }
}
