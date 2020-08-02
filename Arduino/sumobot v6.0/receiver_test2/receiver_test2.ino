#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
//Varialbes de la radio
const int CE = 9;
const int CSN = 10;
RF24 radio(CE,CSN);
const byte address[6] = "00001";

//Variables de los motores
const int M1P = 2;
const int M1N = 3;
const int M2P = 5;
const int M2N = 4;
const int vel = 6;

//Varialbes de text
char text = "";
char text2 ="";


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  motores_init(M1P,M1N,M2P,M2N,vel);
  radio.begin();
  radio.openReadingPipe(0,address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}

void loop() {
  // put your main code here, to run repeatedly:
    if(radio.available())
    {
      radio.read(&text, sizeof(text));
      if(text2 == text)
      {
        detener();
      }
      else
      {
        Serial.println(text);
        parameter_process(text);
        text2 = text;
      }
    }
}


void motores_init(int A, int B, int C, int D, int PWM)
{
  pinMode(A,OUTPUT);
  pinMode(B,OUTPUT);
  pinMode(C,OUTPUT);
  pinMode(D,OUTPUT);
  pinMode(PWM,OUTPUT);
  digitalWrite(A,LOW);
  digitalWrite(B,LOW);
  digitalWrite(C,LOW);
  digitalWrite(D,LOW);
  analogWrite(PWM,0);
}

void adelante(int vel2)
{
  analogWrite(vel,vel2);
  digitalWrite(M1P,HIGH);
  digitalWrite(M1N,LOW);
  digitalWrite(M2P,HIGH);
  digitalWrite(M2N,LOW);
}

void atras(int vel2)
{
  analogWrite(vel,vel2);
  digitalWrite(M1P,LOW);
  digitalWrite(M1N,HIGH);
  digitalWrite(M2P,LOW);
  digitalWrite(M2N,LOW);
}

void derecha(int vel2)
{
  analogWrite(vel,vel2);
  digitalWrite(M1P,LOW);
  digitalWrite(M1N,LOW);
  digitalWrite(M2P,HIGH);
  digitalWrite(M2N,LOW);
}

void izquierda(int vel2)
{
  analogWrite(vel,vel2);
  digitalWrite(M1P,LOW);
  digitalWrite(M1N,LOW);
  digitalWrite(M2P,LOW);
  digitalWrite(M2N,HIGH);
}

void detener(void)
{
  analogWrite(vel,0);
  digitalWrite(M1P,LOW);
  digitalWrite(M1N,LOW);
  digitalWrite(M2P,LOW);
  digitalWrite(M2N,LOW);
}

void parameter_process(char data)
{
  switch (data)
  {
    case 'F':
      adelante(90);
      delay(500);
      detener();
    break;
    case 'B':
      atras(90);
      delay(500);
      detener();
    break;
    case 'L':
      izquierda(90);
      delay(500);
      detener();
    break;
    case 'R':
      derecha(90);
      delay(500);
      detener();
    break;
  }
}

