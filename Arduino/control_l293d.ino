#include <SPI.h>
#include "RF24.h"

RF24 radio(9,10);
byte address[][6] = {"1Node"};
int data_tx;


void setup() {
  // put your setup code here, to run once:
  L293d_init(5,6,0,1,2,3);
  Serial.begin(9600);
  radio.begin();
  radio.setChannel(108);
  radio.setPALevel(RF24_PA_MIN);
  radio.openWritingPipe(address[0][0]);
}

void loop() {
  // put your main code here, to run repeatedly:
  radio.write(&data_tx,sizeof(data_tx));
  
}

void L293d_init(const int M12EN, const int M34EN, const int M1A, const int M2A, const int M3A, const int M4A)
{
  pinMode(M12EN,OUTPUT);
  pinMode(M34EN,OUTPUT);
  pinMode(M1A,OUTPUT);
  pinMode(M2A,OUTPUT);
  pinMode(M3A,OUTPUT);
  pinMode(M4A,OUTPUT);
  digitalWrite(M1A,LOW);
  digitalWrite(M2A,LOW);
  digitalWrite(M3A,LOW);
  digitalWrite(M4A,LOW);
  analogWrite(M12EN,0);
  analogWrite(M34EN,0);
}

void adelanteM1(int velocidad)
{
  digitalWrite(0,HIGH);
  digitalWrite(1,LOW);
  analogWrite(5,velocidad);
}
void atrasM1(int velocidad)
{
  digitalWrite(0,LOW);
  digitalWrite(1,HIGH);
  analogWrite(5,velocidad);
}

void adelanteM2(int velocidad)
{
  digitalWrite(2,HIGH);
  digitalWrite(3,LOW);
  analogWrite(6,velocidad);
}
void atrasM2(int velocidad)
{
  digitalWrite(2,LOW);
  digitalWrite(3,HIGH);
  analogWrite(6,velocidad);
}
void adelante(int velocidad)
{
  adelanteM1(velocidad);
  adelanteM2(velocidad);
}
void atras(int velocidad)
{
  atrasM1(velocidad);
  atrasM2(velocidad);
}

