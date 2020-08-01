
const int in1 = 2;
const int in2 = 3;
const int in3 = 4;
const int in4 = 5;
const int pwm = 6;


void setup()
{
  Serial.begin(9600);
  l293d(in1,in2,in3,in4,pwm);
}

void loop()
{
  adelante(255);
}


void l293d(int pin1, int pin2, int pin3, int pin4, int vel)
{
  int pines[5] = {pin1,pin2,pin3,pin4,vel};
  for(int i=0;i<=4;i++)
  {
    pinMode(pines[i],OUTPUT);
  }
  digitalWrite(pin1,LOW);
  digitalWrite(pin2,LOW);
  digitalWrite(pin3,LOW);
  digitalWrite(pin4,LOW);
  analogWrite(vel,0);
}

void adelanteM1(void)
{
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
}

void adelanteM2(void)
{
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
}

void atrasM1(void)
{
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
}

void atrasM2(void)
{
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
}

void adelante(int velocidad)
{
  adelanteM2();
  adelanteM1();
  analogWrite(pwm,velocidad);
}
void atras(int velocidad)
{
  atrasM1();
  atrasM2();
  analogWrite(pwm,velocidad);
}

void CW(int velocidad)
{
  adelanteM1();
  atrasM2();
  analogWrite(pwm,velocidad);
}

void CCW(int velocidad)
{
  atrasM1();
  adelanteM2();
  analogWrite(pwm,velocidad);
}

void detenido(void)
{
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  analogWrite(pwm,0);
}

