const int ANLeft = 0;
const int ANRight = 1;

const int Motor1A = 2;
const int Motor1B = 3;

const int Motor2A = 4;
const int Motor2B = 7;

const int VelA = 5;
const int VelB = 6;

void setup() {
  pinMode(Motor1A,OUTPUT);
  pinMode(Motor1B,OUTPUT);
  pinMode(Motor2A,OUTPUT);
  pinMode(Motor2B,OUTPUT);
  
  pinMode(VelA,OUTPUT);
  pinMode(VelB,OUTPUT);
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if((SensorRead(ANLeft) == HIGH) && (SensorRead(ANRight) == HIGH))
  {
    Serial.println("Avanzar");
    Avanzar(255);
  }
  else if((SensorRead(ANLeft) == HIGH) && (SensorRead(ANRight) == LOW))
  {
    Serial.println("Izquierda");
    Izquierda(128);
  }
  else if((SensorRead(ANLeft) == LOW) && (SensorRead(ANRight) == HIGH))
  {
    Serial.println("Derecha");
    Derecha(128);
  }
  else if((SensorRead(ANLeft) == LOW) && (SensorRead(ANRight) == LOW))
  {
    Serial.println("Detener");
    Detener();
  }
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


void Izquierda(int Velocidad)
{
  digitalWrite(Motor1A,HIGH);
  digitalWrite(Motor1B,LOW);
  digitalWrite(Motor2A,LOW);
  digitalWrite(Motor2B,HIGH);
  analogWrite(VelA,Velocidad);
  analogWrite(VelB,Velocidad);
}

void Derecha(int Velocidad)
{
  digitalWrite(Motor1A,LOW);
  digitalWrite(Motor1B,HIGH);
  digitalWrite(Motor2A,HIGH);
  digitalWrite(Motor2B,LOW);
  analogWrite(VelA,Velocidad);
  analogWrite(VelB,Velocidad);
}

void Avanzar(int Velocidad)
{
  digitalWrite(Motor1A,HIGH);
  digitalWrite(Motor1B,LOW);
  digitalWrite(Motor2A,HIGH);
  digitalWrite(Motor2B,LOW);
  analogWrite(VelA,Velocidad);
  analogWrite(VelB,Velocidad);
}


void Detener(void)
{
  digitalWrite(Motor1A,LOW);
  digitalWrite(Motor1B,LOW);
  digitalWrite(Motor2A,LOW);
  digitalWrite(Motor2B,LOW);
  analogWrite(VelA,0);
  analogWrite(VelB,0);
}
