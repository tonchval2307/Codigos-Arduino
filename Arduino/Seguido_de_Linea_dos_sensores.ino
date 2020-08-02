//Declaracion de Variables.
//Variables de Sensores de Presencia.
int CNY0 = 0;
int CNY1 = 1;
int mpwm1 = 5;
int mpwm2 = 6;
int min1 = 2;
int min2 = 3;
int min3 = 4;
int min4 = 7;
void setup() {
  // put your setup code here, to run once:
  sensores_configuracion(CNY0,CNY1);
  configuracion_motores(mpwm1,mpwm2,min1,min2,min3,min4);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(deteccion_izquierda(CNY0) == true)
  {
    activar_Motor2(255);
    activar_Motor1(0);
  }
  else if(deteccion_derecha(CNY1) == true)
  {
    activar_Motor1(255);
    activar_Motor2(0);
  }
  else if(deteccion_izquierda(CNY0) && deteccion_derecha(CNY1) == true)
  {
    activar_Motor1(255);
    activar_Motor2(255);
  }
  else
  {
    activar_Motor1(0);
    activar_Motor2(0);
  }
}

void configuracion_motores(int pwm1, int pwm2, int in1, int in2, int in3, int in4)
{
  pinMode(pwm1,OUTPUT);
  pinMode(pwm2,OUTPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
}
void sensores_configuracion(int pin1, int pin2)
{
  pinMode(pin1,INPUT);//OUTPUT
  pinMode(pin2,INPUT);
}
bool deteccion_izquierda(int pin)
{
  if(digitalRead(pin) == HIGH)
  {
    return true;
  }
  else
  {
    return false;
  }
}
bool deteccion_derecha(int pin)
{
  if(digitalRead(pin) == HIGH)
  {
    return true;
  }
  else
  {
    return false;
  }
}
void activar_Motor2(int velocidad)
{
  digitalWrite(min1,HIGH);
  digitalWrite(min2,LOW);
  analogWrite(mpwm2,velocidad); ///0 <= velocidad <= 255
}

void activar_Motor1(int velocidad)
{
  digitalWrite(min3,HIGH);
  digitalWrite(min4,LOW);
  analogWrite(mpwm1,velocidad);
}

