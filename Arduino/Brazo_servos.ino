#include <Servo.h>

Servo pinza;
Servo muneca;
Servo codo;
Servo hombro;
Servo cintura;


void setup() {
  // put your setup code here, to run once:
  articulaciones();
}

void loop() {
  // put your main code here, to run repeatedly:
  posicionInicial();
  delay(500);
  girarIzquierda();
  delay(500);
  bajar();
  delay(500);
  abrir_pinza();
  delay(500);
  cerrar_pinza();
  delay(500);
  subir();
  delay(500);
  girarDerecha();
  delay(500);
}

void articulaciones(void)
{
  pinza.attach(2);
  muneca.attach(3);
  codo.attach(4);
  hombro.attach(5);
  cintura.attach(6);
}

void abrir_pinza(void)
{
  pinza.write(100);
}
void cerrar_pinza(void)
{
  pinza.write(0);
}

void bajar(void)
{
  hombro.write(90);
  delay(100);
  codo.write(90);
  delay(100);  
}

void subir(void)
{
  hombro.write(0);
  delay(100);
  codo.write(0);
  delay(100);
}

void girarIzquierda(void)
{
  cintura.write(180);
  delay(100);
}

void girarDerecha(void)
{
  cintura.write(0);
  delay(100);
}

void posicionInicial(void)
{
  cintura.write(0);
  hombro.write(0);
  codo.write(0);
  muneca.write(0);
}

