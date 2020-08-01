const int in1 = 2;
const int in2 = 3;
const int in3 = 4;
const int in4 = 5;
const int arma = 6;
char dato;

void setup() {
  // put your setup code here, to run once:
  l298n(in1,in2,in3,in4);
  pinMode(arma,OUTPUT);
  Serial.begin(9600);
  detener();
}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available())
  {
    dato = Serial.read();
    Serial.println(dato);
    switch(dato)
    {
      case 'F':
        adelante();
        delay(500);
      break;
      case 'G':
        atras();
        delay(500);
      break;
      case 'L':
        izquierda();
        delay(500);
      break;
      case 'R':
        derecha();
        delay(500);
      break;
      case 'X':
        digitalWrite(arma,HIGH);
        delay(500);
        digitalWrite(arma,LOW);
      break;
      case 'Y':
        detener();
      break;
    }
  }
}

void l298n(const int a, const int b, const int c, const int d)
{
  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(c,OUTPUT);
  pinMode(d,OUTPUT);
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
}

void adelanteM1(void)
{
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
}
void atrasM1(void)
{
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
}
void adelanteM2(void)
{
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
}
void atrasM2(void)
{
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
}

void adelante(void)
{
  adelanteM1();
  adelanteM2();
}
void atras(void)
{
  atrasM1();
  atrasM2();
}
void izquierda(void)
{
  adelanteM1();
  atrasM2();
}

void derecha(void)
{
  atrasM1();
  adelanteM2();
}
void detener(void)
{
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
}

