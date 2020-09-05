#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Keypad.h>

// declaracion de variables para la Radio
const int CE_PIN  = 9;
const int CSN_PIN = 10;

byte direccion[6] = "00001";
RF24 radio(CE_PIN, CSN_PIN);
char dato;
////////////
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
  radio.begin();
  radio.openWritingPipe(direccion);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop() {
  // put your main code here, to run repeatedly:
  
  
  if(radio.write(dato,sizeof(dato)))
  {
    char key = keypad.getKey();
    Serial.print("Dato Enviado : ");
    Serial.println(key);
  }
  else
  {
    Serial.println("No se ha podido enviar");
  }
  delay(1000);
}
