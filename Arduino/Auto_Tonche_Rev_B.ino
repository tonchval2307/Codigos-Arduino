// Auto de Experimentos de Tonche Rev B.
// software Basado en el codigo BMCB_REV_A
#include <Servo.h>

#define Relay 8
#define PWMR 6
#define PWML 5
#define M1LP 2
#define M1LN 3
#define M2RP 4
#define M2RN 7

#define ENABLE 1
#define DISABLE 0
#define WIFI 1
#define BT 0

Servo direccion;
static int pos;
int vel = 140;
enum direcciones{izq,der,reposo,fwd,bwd};
int estado;
void setup() {
  // put your setup code here, to run once:
  ComunicationInit(BT);
  powerTrain_Init();
  estado = reposo;
  Serial.begin(9600);
  detener();
  direccion.write(90);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available())
  {
    estado = Serial.read();
  }
  else
  {
    estado = Serial.read();
  }
  switch(estado)
  {
    case 'w':
      Serial.println("adelabnte");
      adelante(vel);
      DireccionCentro();
    break;
    case 's':
      Serial.println("atras");
      atras(vel);
      DireccionCentro();
    break;
    case 'a':
      Serial.println("izquierda");
      DireccionIzquierda();
      izquierda(vel);
    break;
    case 'd':
      Serial.println("derecha");
      DireccionDerecha();
      derecha(vel);
    break;
    case 'o':
      vel = 255;
      Serial.print("Velocidad = ");
      Serial.println(vel);
      estado = 0;
    break;
    case 'p':
      vel = 140;
      Serial.print("Velocidad = ");
      Serial.println(vel);
      estado = 0;
    break;
    case 'l':
      Attack(ENABLE);
      Serial.println("Atacando");
    break;
    case 'k':
      Attack(DISABLE);
      Serial.println("No atacando");
    break;
    case 'n':
      detener();
      DireccionCentro();
      delay(50);
    break;
    case '0':
      direccion.write(90);
      delay(100);
      direccion.write(125);
      delay(1000);
      direccion.write(65);
      delay(1000);
      direccion.write(90);
    break;
  }
}

void testRotation(void)
{
    switch(estado)
  {
    case reposo:
      Serial.println("Reposo");
      DireccionCentro();
      detener();
      delay(3000);
      estado = izq;
    break;
    case izq:
      Serial.println("Izquierda");
      DireccionIzquierda();
      izquierda(vel);
      delay(3000);
      estado = der;
    break;
    case der:
      Serial.println("Derecha");
      DireccionDerecha();
      derecha(vel);
      delay(3000);
      estado = fwd;
    break;
    case fwd:
      Serial.println("Adelante");
      adelante(vel);
      delay(3000);
      estado = bwd;
    break;
    case bwd:
      Serial.println("Atras");
      atras(vel);
      delay(3000);
      estado = reposo;
    break;
  }
}

void Attack(char mode)
{
  switch(mode)
  {
    case 1:
      digitalWrite(Relay,HIGH);
    break;
    case 0:
      digitalWrite(Relay,LOW);
    break;
  }
}

void ComunicationInit(char mode)
{
  if(mode == WIFI)
  {
    
  }
  else if(mode == BT)
  {
    Serial.begin(9600);
  }
}

void powerTrain_Init(void)
{
  direccion.attach(9);
  direccion.write(90);
  pinMode(Relay, OUTPUT);
  pinMode(PWMR,OUTPUT);
  pinMode(PWML,OUTPUT);
  pinMode(M1LP,OUTPUT);
  pinMode(M1LN,OUTPUT);
  pinMode(M2RP,OUTPUT);
  pinMode(M2RN,OUTPUT);

  digitalWrite(Relay,LOW);
  digitalWrite(M1LP,LOW);
  digitalWrite(M1LN,LOW);
  digitalWrite(M2RN,LOW);
  digitalWrite(M2RP,LOW);

  analogWrite(PWML,0);
  analogWrite(PWMR,0);
}

void DireccionDerecha(void)
{
  // max turn right = 125;
  for(int i=pos;i<=110;i++)
  {
    direccion.write(i);
    delay(15);
  }
  pos = 125;
  //direccion.write(125);
}

void DireccionIzquierda(void)
{
  //max turn left = 55
  for(int i=pos;i>=70;i--)
  {
    direccion.write(i);
    delay(15);
  }
  pos = 55;
  //direccion.write(55);
}

void DireccionCentro(void)
{
  direccion.write(90);
  delay(15);
  pos = 90;
}

void adelante(int velocidad)
{
 digitalWrite(M1LP,HIGH);
 digitalWrite(M1LN,LOW);
 digitalWrite(M2RN,HIGH);
 digitalWrite(M2RP,LOW);
 analogWrite(PWML,velocidad); 
 analogWrite(PWMR,velocidad);
}

void atras(int velocidad)
{
   digitalWrite(M1LP,LOW);
   digitalWrite(M1LN,HIGH);
   digitalWrite(M2RN,LOW);
   digitalWrite(M2RP,HIGH);
   analogWrite(PWML,velocidad); 
   analogWrite(PWMR,velocidad);
}

void izquierda(int velocidad)
{
   digitalWrite(M1LP,LOW);
   digitalWrite(M1LN,HIGH);
   digitalWrite(M2RN,HIGH);
   digitalWrite(M2RP,LOW);
   analogWrite(PWML,velocidad); 
   analogWrite(PWMR,velocidad);
  
}

void derecha(int velocidad)
{
   digitalWrite(M1LP,HIGH);
   digitalWrite(M1LN,LOW);
   digitalWrite(M2RN,LOW);
   digitalWrite(M2RP,HIGH);
   analogWrite(PWML,velocidad); 
   analogWrite(PWMR,velocidad);
}

void detener(void)
{
   digitalWrite(M1LP,LOW);
   digitalWrite(M1LN,LOW);
   digitalWrite(M2RN,LOW);
   digitalWrite(M2RP,LOW);
   analogWrite(PWML,0); 
   analogWrite(PWMR,0);
}
