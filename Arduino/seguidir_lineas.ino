
const int M1A = 8;
const int M1B = 10; //Izquierdo

const int M2A = 12;
const int M2B = 13; //Derecho

const int Sens_Izq = 0;
const int Sens_Der = 1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  l293dBegin(M1A,M1B,M2A,M2B);
}

void loop() {
  // put your main code here, to run repeatedly:
  seguir_linea();
}
void seguir_linea(void)
{
  if(SensorDerecho(256) && (!SensorIzquierdo(256)))
  {
    Serial.println("Sensor Derecho Activado");
    giroCW();
  }
  else if(!SensorDerecho(256) && SensorIzquierdo(256))
  {
    Serial.println("Sensor Izquierdo Activado");
    giroCW();
  }
  else if (SensorDerecho(256) && SensorIzquierdo(256))
  {
    Serial.println("Ambos Sensores Detectando");
    adelante();
  }
  else
  {
    Serial .println("Ninguno detectando");
    atras();
  }
  delay(1000);
}
bool SensorDerecho(int a)
{
  if(analogRead(Sens_Der) >= a)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool SensorIzquierdo(int a)
{
  if(analogRead(Sens_Izq) >= a)
  {
    return true;
  }
  else
  {
    return false;
  }
}
void test(void)
{
  adelante();
//  Serial.println("adelante");
//  delay(2000);
//  atras();
//  Serial.println("atras");
//  delay(2000);
//  giroCW();
//  delay(2000);
//  Serial.println("giroCW");
//  giroCCW();
//  Serial.println("giroCCW");
//  delay(2000);
}
void l293dBegin(int a, int b, int c, int d)
{
  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(c,OUTPUT);
  pinMode(d,OUTPUT);
}

void adelanteIzq(void)
{
  digitalWrite(M1A,HIGH);
  digitalWrite(M1B,LOW);
}

void atrasIzq(void)
{
  digitalWrite(M1A,LOW);
  digitalWrite(M1B,HIGH);
}

void adelanteDer(void)
{
  digitalWrite(M2A,HIGH);
  digitalWrite(M2B,LOW);
}

void atrasDer(void)
{
  digitalWrite(M2A,LOW);
  digitalWrite(M2B,HIGH);
}

void adelante(void)
{
  adelanteIzq();
  adelanteDer();
}

void atras(void)
{
  atrasIzq();
  atrasDer();
}

void giroCW(void)
{
  adelanteIzq();
  atrasDer();
}

void giroCCW(void)
{
  adelanteDer();
  atrasIzq();
}

