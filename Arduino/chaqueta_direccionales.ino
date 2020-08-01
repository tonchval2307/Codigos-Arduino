const int I1 = 1;
const int I2 = 0;
const int I3 = 2;
// 3 -5 -6
const int D1 = 3;
const int D2 = 5;
const int D3 = 6;

enum estados{izquierda,derecha,apagado};
int estado;
void setup() {
  // put your setup code here, to run once:
  luces_init(I1,I2,I3,D1,D2,D3);
  estado = apagado;
  pinMode(7,INPUT);
  pinMode(8,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  switch(estado)
  {
    case apagado:
      turnoff();
      digitalWrite(1,LOW);
      digitalWrite(0,LOW);
      digitalWrite(2,LOW);
      digitalWrite(3,LOW);
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
      if(digitalRead(7) == LOW)
      {
        estado = izquierda;
      }
      else if(digitalRead(8) == LOW)
      {
        estado = derecha;
      }
      else
      {
        estado = apagado;
      }
    break;
    case izquierda:
      voltearIzquierda();
      if(digitalRead(7) == LOW)
      {
        estado = apagado;
      }
      else if(digitalRead(8) == LOW)
      {
        estado = derecha;
      }
      else
      {
        estado = izquierda;
      }
    break;
    case derecha:
      voltearDerecha();
      if(digitalRead(7) == LOW)
      {
        estado = izquierda;
      }
      else if(digitalRead(8) == LOW)
      {
        estado = apagado;
      }
      else
      {
        estado = derecha;
      }
    break;
  }

}

void luces_init(const int L1, const int L2, const int L3, const int R1, const int R2, const int R3)
{
  pinMode(L1,OUTPUT);
  pinMode(L2,OUTPUT);
  pinMode(L3,OUTPUT);
  pinMode(R1,OUTPUT);
  pinMode(R2, OUTPUT);
  pinMode(R3,OUTPUT);
  digitalWrite(L1,LOW);
  digitalWrite(L2,LOW);
  digitalWrite(L3,LOW);
  digitalWrite(R1,LOW);
  digitalWrite(R2,LOW);
  digitalWrite(R3,LOW);
}

void patron1(void)
{
  

}

  void voltearIzquierda(void)
  {
    int aizquierda[3] = {I1,I2,I3};
    int aderecha[3] = {D1,D2,D3};
    for(int i=0;i<=2;i++)
    {
      digitalWrite(aizquierda[i],HIGH);
      delay(100);
      digitalWrite(aizquierda[i],LOW);
      delay(100);
    }
  }

  void voltearDerecha(void)
  {
    int aizquierda[3] = {I1,I2,I3};
  int aderecha[3] = {D1,D2,D3};
  for(int i=0;i<=2;i++)
  {
    digitalWrite(aderecha[i],HIGH);
    delay(100);
    digitalWrite(aderecha[i],LOW);
    delay(100);
  }
  }
  //1-0-2
void turnoff(void)
{
    int aizquierda[3] = {I1,I2,I3};
  int aderecha[3] = {D1,D2,D3};
  for(int i=0;i<=2;i++)
  {
    digitalWrite(aizquierda[i],LOW);
    digitalWrite(aderecha[i],LOW);
    delay(100);
    digitalWrite(aizquierda[i],LOW);
    digitalWrite(aderecha[i],LOW);
    delay(100);
  }
}

