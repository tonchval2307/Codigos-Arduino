#include <Keypad.h>

const byte ROWS = 2;
const byte COLS = 2;

char keys[ROWS][COLS] = {
  {'f' , 'b'},
  {'l' , 'r'},
};

byte rowPins[ROWS] = {2,3};
byte colPins[COLS] = {4,5}; 
Keypad keypad = Keypad( makeKeymap(keys),rowPins,colPins,ROWS,COLS);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  char key = keypad.getKey();
  if(key != NO_KEY)
  {
    Serial.println(key);
  }
}
