#define Izquierda 5
#define Derecha 4
#define MCW 2
#define MCCW 3
#define start 13

static unsigned int state;
void setup() {
  pinMode(Izquierda,INPUT);
  pinMode(Derecha,INPUT);
  pinMode(start,INPUT);
  pinMode(MCW,OUTPUT);
  pinMode(MCCW,OUTPUT);
  state = 1;
  // put your setup code here, to run once:

}

void loop() {
  
  bool inicio, izq, der;
  inicio = digitalRead(start);
  izq = digitalRead(Izquierda);
  der = digitalRead(Derecha);
  
  switch (state)
    {
      case 1:
        if(inicio == LOW)
        {
          delay(100);
          if(inicio == LOW)
          {
          state = 2;
          }
        }
      break;
      case 2:
        if(inicio == LOW)
        {
          delay(100);
          if(inicio == LOW)
          {
          state = 1;
          }
        }
      break;
      default:
        state = 1;
      break;
    }
    if(state == 1)
    {
      digitalWrite(MCCW,LOW);
      digitalWrite(MCW,LOW);
    }
    if(state == 2)
    {
      if(izq == LOW)
      {
        digitalWrite(MCCW,LOW);
        digitalWrite(MCW,HIGH);
      }
      if(der == LOW)
      {
        digitalWrite(MCCW,HIGH);
        digitalWrite(MCW,LOW);
      }
    }
  // put your main code here, to run repeatedly:

}
