#define Arranque 5
#define Paro 3
#define Encendido_Apagado 4
#define Motor 2

static unsigned int state;
void setup() {
  // put your setup code here, to run once:
  pinMode(Arranque,INPUT);
  pinMode(Paro,INPUT);
  pinMode(Encendido_Apagado,INPUT);
  pinMode(Motor,OUTPUT);
  state = 1;
}

void loop() {
  // put your main code here, to run repeatedly:
  bool start,stoped,emplayar;
  start = digitalRead(Encendido_Apagado);
  stoped = digitalRead(Paro);
  emplayar = digitalRead(Arranque);
  /*******Finite state Machine*******/
  /*
   * 
   * 
   */

      switch (state)
        {
          case 1:
            if(start == LOW)
            {
              state = 2;
            }
            else
            {
              state = 1;
            }
            break;
          case 2:
            if(emplayar == LOW)
            {
              state = 3;
            }
            else
            {
              state = 2;
            }
            break;
          case 3:
            if(stoped == LOW)
            {
              state = 2;
            }
            else
            {
              state = 3;
            }
            break;
          default:
            state = 1;
            break;
        }

        if(state == 1)
        {
          digitalWrite(Motor,LOW);
        }
        if(state == 2)
        {
          digitalWrite(Motor,LOW);
        }
        if(state == 3)
        {
          digitalWrite(Motor,HIGH);
        }
}
