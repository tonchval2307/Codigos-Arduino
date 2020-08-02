#define Izquierda 5
#define Derecha 4
#define MCW 3
#define MCCW 2
#define start 1

void setup() {
  // put your setup code here, to run once:
  pinMode(Izquierda,INPUT);
  pinMode(Derecha,INPUT);
  pinMode(start,INPUT);
  pinMode(MCW,OUTPUT);
  pinMode(MCCW,OUTPUT);
  int a = 0;
}
static unsigned int state;
void loop() {
  // put your main code here, to run repeatedly:
  
  bool inicio, izq, der;
  inicio = digitalRead(start);
  izq = digitalRead(Izquierda);
  der = digitalRead(Derecha);

  if(inicio == LOW && izq == LOW && der == LOW)
  {
    a = 1;
  }
  if(inicio == LOW && izq == LOW && der == HIGH)
  {
    a = 2;
  }
  if(inicio == LOW && izq == HIGH && der == LOW)
  {
    a = 3;
  }
  if(inicio == LOW && izq == HIGH && der == HIGH)
  {
    a = 4;
  }
  if(inicio == HIGH && izq == LOW && der == LOW)
  {
    a = 5;
  }
  if(inicio == HIGH && izq == LOW && der == HIGH)
  {
    a = 6;
  }
  if(inicio == HIGH && izq == HIGH && der == LOW)
  {
    a = 7;
  }
  if(inicio == HIGH && izq == HIGH && der == HIGH)
  {
    a = 8;
  }

  switch (a)
    {
      case 1:
        
      break;
      case 2:
      break;
      case 3:
      break;
      case 4:
      break;
      case 5:
      break;
      case 6:
      break;
      case 7:
      break;
      case 8:
      break;
    }
  }
