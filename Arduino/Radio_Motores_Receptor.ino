#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

//variables de Radio.
const int CE_PIN = 9;
const int CSN_PIN = 10;

byte direccion[5] = {'c','a','n','a','l'};
RF24 radio(CE_PIN,CSN_PIN);
char dato;

void setup() {
  // put your setup code here, to run once:
  radio.begin();
  radio.openReadingPipe(1,direccion);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  analogWrite(6,0);
}

void loop() {
  // put your main code here, to run repeatedly:
  uint8_t numero_canal;
  if(radio.available())
  {
    radio.read(dato,sizeof(dato));
    switch(dato)
    {
      case 'f':
        digitalWrite(2,HIGH);
        digitalWrite(3,LOW);
        digitalWrite(4,LOW);
        digitalWrite(5,LOW);
        analogWrite(6,90);
      break;
      case 'b':
        digitalWrite(2,LOW);
        digitalWrite(3,HIGH);
        digitalWrite(4,LOW);
        digitalWrite(5,LOW);
        analogWrite(6,90);
      break;
      case 'l':
        digitalWrite(2,LOW);
        digitalWrite(3,LOW);
        digitalWrite(4,HIGH);
        digitalWrite(5,LOW);
        analogWrite(6,90);
      break;
      case 'r':
        digitalWrite(2,LOW);
        digitalWrite(3,LOW);
        digitalWrite(4,LOW);
        digitalWrite(5,HIGH);
        analogWrite(6,90);
      break;
    }
  }
  else
  {
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    analogWrite(6,0);
  }
  delay(1000);
}
