#include <Servo.h>

#define S0 2
#define S1 3
#define S2 4
#define S3 5
#define sensorOut 6
#define RED 1
#define BLUE 2
#define GREEN 3

#define CCafe 4
#define CRojo 5
#define CNaranja 6
#define CVerde 7
#define CAmarillo 8
#define CAzul 9

Servo topServo;
Servo bottomServo;

int freq = 0;
int color = 0;

const int PosicionVerde = 30;
const int PosicionRojo = 40;
const int PosicionCafe = 50;
const int PosicionAzul = 60;
const int PosicionAmarillo = 70;
const int PosicionNaranja = 80;
const int PosicionRecirculacion = 90;

int Color;

enum SortingStates{LeerBarra, RecogerBean, LeerColorBean, Cafe, Rojo, Naranja, Verde, Amarillo, Azul};
int estado;

const int BarraCafe = 0;
const int BarraRojo = 1;
const int BarraNaranja = 2;
const int BarraVerde = 3;
const int BarraAmarillo = 4;
const int BarraAzul = 5;
//const int Colores[6] = {BarraCafe, BarraRojo, BarraNaranja, BarraVerde, BarraAmarillo, BarraAzul};

void setup() {
  // put your setup code here, to run once:
  pinMode(S0,OUTPUT);
  pinMode(S1,OUTPUT);
  pinMode(S2,OUTPUT);
  pinMode(S3,OUTPUT);
  pinMode(sensorOut,INPUT);

  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);

  topServo.attach(7);
  bottomServo.attach(8);

  Serial.begin(9600);
  estado = LeerBarra;
}

void loop() {
  // put your main code here, to run repeatedly:
  switch(estado)
  {
    case LeerBarra:
      Serial.println("Leyendo Barra de Beans");
      ServoSortingPosition();
      ServoRecirculationPosition();
      if(ColorAusente(BarraCafe) == 1)
      {
        Color = CCafe;
        Serial.println("  Falta Cafe ");
        estado = RecogerBean;
      }
      else if (ColorAusente(BarraRojo) == 1)
      {
        
        Color = CRojo;
        Serial.println("  Falta Rojo ");
        estado = RecogerBean;
      }
      else if (ColorAusente(BarraNaranja) == 1)
      {
        Color = CNaranja;
        Serial.println("  Falta Naranja ");
        estado = RecogerBean;
      }
      else if (ColorAusente(BarraVerde) == 1)
      {
        Color = CVerde;
        Serial.println("  Falta VErde ");
        estado = RecogerBean;
      }
      else if (ColorAusente(BarraAmarillo) == 1)
      {
        Color = CAmarillo;
        Serial.println("  Falta  Amarillo ");
        estado = RecogerBean;
      }
      else if (ColorAusente(BarraAzul) == 1)
      {
        Color = CAzul;
        Serial.println("  Falta Azul ");
        estado = RecogerBean;
      }
      else
      {
        Color = 0;
        estado = LeerBarra;
      }
    break;
    case RecogerBean:
      Serial.println("Recoginedo bean");
      ServoPickPosition();
      ServoRecirculationPosition();
      delay(250);
      estado = LeerColorBean;
    break;
    case LeerColorBean:
      Serial.println("Leyendo Color de Bean");
      ServoScanPosition();
      ServoRecirculationPosition();
      PrintColors();
      if(EstimacionColor() != Color)
      {
        ServoRecirculationPosition();
        delay(250);
        ServoSortingPosition();
        delay(250);
        estado = RecogerBean;
      }
      else
      {
        if(Color == CCafe)
        {
          estado = Cafe;
        }
        else if(Color == CRojo)
        {
          estado = Rojo;
        }
        else if(Color == CNaranja)
        {
          estado = Naranja;
        }
        else if(Color == CVerde)
        {
          estado = Verde;
        }
        else if(Color == CAmarillo)
        {
          estado = Amarillo;
        }
        else if(Color == CAzul)
        {
          estado = Azul;
        }
        else
        {
          estado = LeerBarra;
        }
      }
    break;
    case Cafe:
      ServoBrownPosition();
      delay(100);
      ServoSortingPosition();
      delay(500); //Esperar a que caiga el bean.
      estado = LeerBarra;
    break;
    case Rojo:
      ServoRedPosition();
      delay(100);
      ServoSortingPosition();
      delay(500);
      estado = LeerBarra;
    break;
    case Naranja:
      ServoOrangePosition();
      delay(100);
      ServoSortingPosition();
      delay(500);
      estado = LeerBarra;
    break;
    case Verde:
      ServoGreenPosition();
      delay(100);
      ServoSortingPosition();
      delay(500);
      estado = LeerBarra;
    break;
    case Amarillo:
      ServoYellowPosition();
      delay(100);
      ServoSortingPosition();
      delay(500);
      estado = LeerBarra;
    break;
    case Azul:
      ServoBluePosition();
      delay(100);
      ServoSortingPosition();
      delay(500);
      estado = LeerBarra;
    break;
  }

}
void PrintColors(void)
{
  const int Ejemplos = 3;
  static double freqRojo = 0;
  static double freqVerde = 0;
  static double freqAzul = 0;
  for(int i=0;i<Ejemplos;i++)
  {
    freqRojo += ReadColor(RED);
  }
  freqRojo /= Ejemplos;
  for(int j=0;j<Ejemplos;j++)
  {
    freqVerde += ReadColor(GREEN);
  }
  freqVerde /= Ejemplos;
  for(int k=0;k<Ejemplos;k++)
  {
    freqAzul += ReadColor(BLUE);
  }
  freqAzul /= Ejemplos;

  Serial.print("Color Rojo : " );
  Serial.print(freqRojo);
  Serial.print(" Color Verde : " );
  Serial.print(freqVerde);
  Serial.print(" Color Azul : " );
  Serial.print(freqAzul);
  Serial.println();
}
int EstimacionColor(void)
{
  const int samples = 3;
  static double freqRed = 0;
  static double freqGreen = 0;
  static double freqBlue = 0;
  for(int i=0;i<samples;i++)
  {
    freqRed += ReadColor(RED);
  }
  freqRed /= samples;
  for(int j=0;j<samples;j++)
  {
    freqGreen += ReadColor(GREEN);
  }
  freqGreen /= samples;
  for(int k=0;k<samples;k++)
  {
    freqBlue += ReadColor(BLUE);
  }
  freqBlue /= samples;
  return 0;
}

double Average(double data[], const int samples)
{
  double temp = 0;
  for(int i=0;i<samples;i++)
  {
    temp += data[i];
  }
  temp /= samples;
  return temp;
}
int ReadColor(int ColorParameter)
{
  int temp = 0;
  switch(ColorParameter)
  {
    case RED:
      digitalWrite(S2,LOW);
      digitalWrite(S3,LOW);
      temp = pulseIn(sensorOut,LOW);
      return temp;
    break;
    case GREEN:
      digitalWrite(S2,HIGH);
      digitalWrite(S3,HIGH);
      temp = pulseIn(sensorOut,LOW);
      return temp;
    break;
    case BLUE:
      digitalWrite(S2,LOW);
      digitalWrite(S3,HIGH);
      temp = pulseIn(sensorOut,LOW);
      return temp;
    break;
  }
}


void ServoPickPosition(void)
{
  delay(10);
  static int HomeValue = 5;
  topServo.write(HomeValue);
}

void ServoScanPosition(void)
{
  delay(10);
  static int ReadValue = 63;
  topServo.write(ReadValue);
}

void ServoSortingPosition(void)
{
  delay(10);
  static int SortingValue = 85;
  topServo.write(SortingValue);
}

void ServoGreenPosition(void)
{
  delay(10);
  bottomServo.write(PosicionVerde);
}

void ServoBluePosition(void)
{
  delay(10);
  bottomServo.write(PosicionAzul);
}

void ServoBrownPosition(void)
{
  delay(10);
  bottomServo.write(PosicionCafe);
}

void ServoRedPosition(void)
{
  delay(10);
  bottomServo.write(PosicionRojo);
}

void ServoOrangePosition(void)
{
  delay(10);
  bottomServo.write(PosicionNaranja);
}

void ServoYellowPosition(void)
{
  delay(10);
  bottomServo.write(PosicionAmarillo);
}

void ServoRecirculationPosition(void)
{
  delay(10);
  bottomServo.write(PosicionRecirculacion);
}

int ColorAusente(const int pin)
{
  int Threshold = 620;
  if(analogRead(pin) <= Threshold)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
