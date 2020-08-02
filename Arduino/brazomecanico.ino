#include <Servo.h>

Servo pinza;
Servo cintura;
Servo hombro;
Servo codo;
Servo muneca;
const int button1 = 2;
const int pinzaAbierta = 50;
const int pinzaCerrada = 120;

void setup() {
  // put your setup code here, to run once:
  ServoInit();
  pinMode(button1,INPUT_PULLUP);
  pinMode(13,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 
 posicionInicial();
 delay(2000);
 recogerLapiz();
 delay(2000); 
}

void ServoInit(void)
{
  pinza.attach(12);
  muneca.attach(11);
  codo.attach(10);
  hombro.attach(9);
  cintura.attach(8);
}

void AbrirPinza(void)
{
  for(int i=100;i>=50;i--)
  {
    pinza.write(i);
    delay(10);
  }
  //pinza.write(50);
}

void CerrarPinza(void)
{
  for(int i=50;i<=100;i++)
  {
    pinza.write(i);
    delay(10); 
  }
  //pinza.write(100); 
}
void munecaIzq(void)
{
  int limiteSup = 90;
  muneca.write(limiteSup);
}
void munecaDer(void)
{
  int limiteInf = 45;
  muneca.write(45);
}
void CodoArriba(void)
{
  codo.write(90);
}
void CodoAbajo(void)
{
  codo.write(45);
}
void posicionInicial(void)
{
  //pinza.write(50);
  //delay(500);
  muneca.write(45);
  delay(500);
  codo.write(45);
  delay(500);
  hombro.write(70);
  delay(500);
  cintura.write(170);
  delay(500);
}
void erguido(void)
{
  for(int i=120;i>=70;i--)
  {
    hombro.write(i);
  }
  //hombro.write(70);
}
void agachado(void)
{
 for(int i=70;i<=130;i++)
 {
  hombro.write(i);
  delay(10);
 }
//hombro.write(120);
}
void izquierda(void)
{
  for(int i=80;i<=170;i++)
  {
    cintura.write(i);
    delay(10);
  }
  //cintura.write(170);
}
void derecha(void)
{
  for(int i=170;i>=80;i--)
  {
    cintura.write(i);
    delay(10);
  }
  //cintura.write(80);
}
void recogerLapiz(void)
{
  derecha();
  delay(700);
  AbrirPinza();
  delay(700);
  CodoAbajo();
  delay(700);
  agachado();
  delay(700);
  CerrarPinza();
  delay(700);
  erguido();
  delay(700);
  izquierda();
  delay(700);
  agachado();
  delay(700);
  AbrirPinza();
  delay(700);
  erguido();
  delay(250);
}

