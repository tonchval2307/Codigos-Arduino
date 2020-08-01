#include <AFMotor.h>

AF_DCMotor Izquierdo(1);
AF_DCMotor Derecho(4);
//----- Sensores de Linea Entradas Analogicas---
const int ANLeft = 0;
const int ANRight = 1;
//-----------------------------------------------

//Terminales del Motor L298N-------------------
const int Motor1A = 6;
const int Motor1B = 7;

const int Motor2A = 3;
const int Motor2B = 4;
//-----------------------------------------------
//Sensores de Obstaculos Laser-----------------
const int Frontal = 7;
const int Trasero = 8;
//-----------------------------------------------


void setup() {
  // put your setup code here, to run once:
  MotorInit();
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if((SensorRead(ANLeft) == HIGH) && (SensorRead(ANRight) == HIGH))
  {
    Serial.println("Avanzar");
    if((SensorLaser(Frontal) == HIGH) || (SensorLaser(Trasero) == HIGH))
    {
      Detener();
    }
    else
    {
      Avanzar();
    }
  }
  else if((SensorRead(ANLeft) == HIGH) && (SensorRead(ANRight) == LOW))
  {
    Serial.println("Izquierda");
    if((SensorLaser(Frontal) == HIGH) || (SensorLaser(Trasero) == HIGH))
    {
      Detener();
    }
    else
    {
      Izquierda();
    }
  }
  else if((SensorRead(ANLeft) == LOW) && (SensorRead(ANRight) == HIGH))
  {
    Serial.println("Derecha");
    if((SensorLaser(Frontal) == HIGH) || (SensorLaser(Trasero) == HIGH))
    {
      Detener();
    }
    else
    {
      Derecha();
    }
  }
  else if((SensorRead(ANLeft) == LOW) && (SensorRead(ANRight) == LOW))
  {
    Serial.println("Detener");
    Detener();
  }
}

void MotorInit(void)
{
  Izquierdo.run(RELEASE);
  Derecho.run(RELEASE);
  //pinMode(Motor1A,OUTPUT);
  //pinMode(Motor1B,OUTPUT);
  //pinMode(Motor2A,OUTPUT);
  //pinMode(Motor2B,OUTPUT);
}
void TestLight(void)
{
  Serial.print("[");
  Serial.print(analogRead(0));
  Serial.print(" , ");
  Serial.print(analogRead(1));
  Serial.println("]");
  delay(250);
}
unsigned int SensorRead(const int pin)
{
  unsigned int Threshold = 200;
  if(analogRead(pin) >= Threshold)
  {
    return HIGH;
  }
  else
  {
    return LOW;
  }
}


void Izquierda(void)
{
  Izquierdo.run(BACKWARD);
  Derecho.run(FORWARD);
  Izquierdo.setSpeed(200);
  Derecho.setSpeed(200);
  //digitalWrite(Motor1A,HIGH);
  //digitalWrite(Motor1B,LOW);
  //digitalWrite(Motor2A,LOW);
  //digitalWrite(Motor2B,HIGH);
}

void Derecha(void)
{
  Izquierdo.run(FORWARD);
  Derecho.run(BACKWARD);
  Izquierdo.setSpeed(200);
  Derecho.setSpeed(200);
  //digitalWrite(Motor1A,LOW);
  //digitalWrite(Motor1B,HIGH);
  //digitalWrite(Motor2A,HIGH);
  //digitalWrite(Motor2B,LOW);
}

void Avanzar(void)
{
    Izquierdo.run(FORWARD);
  Derecho.run(FORWARD);
  Izquierdo.setSpeed(200);
  Derecho.setSpeed(200);
  //digitalWrite(Motor1A,HIGH);
  //digitalWrite(Motor1B,LOW);
  //digitalWrite(Motor2A,HIGH);
  //digitalWrite(Motor2B,LOW);
}


void Detener(void)
{
    Izquierdo.run(RELEASE);
  Derecho.run(RELEASE);
 // digitalWrite(Motor1A,LOW);
  //digitalWrite(Motor1B,LOW);
  //digitalWrite(Motor2A,LOW);
  //digitalWrite(Motor2B,LOW);
}

unsigned int SensorLaser(int Sensor)
{
  if(digitalRead(Sensor))
  {
    delay(200);
      if(digitalRead(Sensor))
      {
        return HIGH;
      }
      else
      {
        return LOW;
      }
  }
}
