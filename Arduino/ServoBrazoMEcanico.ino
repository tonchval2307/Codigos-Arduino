#include <Servo.h>

Servo Cintura;
Servo Hombro;
Servo Cadera;
Servo muneca;
Servo pinza;

int pinza1 = 3;
int muneca1 = 4;
int Cadera1 = 5;
int Hombro1 = 6;
int Cintura1 = 7;

int data;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinza.attach(pinza1);
  muneca.attach(muneca1);
  Cadera.attach(Cadera1);
  Hombro.attach(Hombro1);
  Cintura.attach(Cintura1);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available())
  {
    data = Serial.read();
    
  }
  else
  {
    posicionInicial();
  }
}

void abrirPinza(unsigned int grado)
{
  
}
void cerrarPinza(unsigned int grado)
{
  
}
void cinturaDerecha(unsigned int giro)
{
  
}
void cinturaIzquierda(unsigned int giro)
{
  
}
void posicionInicial(void)
{
  
}


