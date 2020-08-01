
int vel_pin = 6;
int direccion1 = 2;
int direccion2 = 3;
int direccion3 = 4;
int direccion4 = 5;

void setup() {
  // put your setup code here, to run once:
  L293D(vel_pin,direccion1,direccion2,direccion3,direccion4);
}

void loop() {
  // put your main code here, to run repeatedly:

}

void L293D(const int PWM, const int M1A, const int M2A, const int M3A, const int M4A)
{
  pinMode(PWM,OUTPUT);
  pinMode(M1A,OUTPUT);
  pinMode(M2A,OUTPUT);
  pinMode(M3A,OUTPUT);
  pinMode(M4A,OUTPUT);
  digitalWrite(M1A,LOW);
  digitalWrite(M2A,LOW);
  digitalWrite(M3A,LOW);
  digitalWrite(M4A,LOW);
  analogWrite(PWM,0);
}
void adelanteM1(int velocidad)
{
  digitalWrite(direccion1,HIGH);
  digitalWrite(direccion2,LOW);
  analogWrite(vel_pin,velocidad);
}
void atrasM1(int velocidad)
{
  digitalWrite(direccion1,LOW);
  digitalWrite(direccion2,HIGH);
  analogWrite(vel_pin,velocidad);
}

void adelanteM2(int velocidad)
{
  digitalWrite(direccion3,HIGH);
  digitalWrite(direccion4,LOW);
  analogWrite(vel_pin,velocidad);
}
void atrasM2(int velocidad)
{
  digitalWrite(direccion3,LOW);
  digitalWrite(direccion4,HIGH); 
  analogWrite(vel_pin,velocidad);
}

