#include <Servo.h>

Servo pinza;
Servo muneca;
Servo codo;
Servo hombro;
Servo cintura;

const int griper = 2;
const int doll = 3;
const int elbow = 4;
const int shoulder = 5;
const int waist = 6;

void setup() {
  // put your setup code here, to run once:
  articulaciones(griper,doll,elbow,shoulder,waist);
}

void loop() {
  // put your main code here, to run repeatedly:
  abrirPinza();
  cerrarPinza();
  
}

void articulaciones(const int a, const int b, const int c, const int d, const int e)
{
  pinza.attach(a);
  muneca.attach(b);
  codo.attach(c);
  hombro.attach(d);
  cintura.attach(e);
}

void abrirPinza(void)
{
  pinza.write(100);
  delay(1000);
}

void cerrarPinza(void)
{
  pinza.write(100);
  delay(1000);
}

