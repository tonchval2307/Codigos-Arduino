#define Relay 8
#define PWMR 6
#define PWML 5
#define M1LP 2
#define M1LN 3
#define M2RP 4
#define M2RN 7

#define ENABLE 1
#define DISABLE 0
#define WIFI 1
#define BT 0

const int pines[4] = { M1LP,M1LN,M2RP,M2RN};
void setup() {
  // put your setup code here, to run once:
  RobotInit();
  for(int i=0;i<4;i++)
  {
    pinMode(pines[i],OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  run_it();
}
void run_it(void)
{
   for(int i=0;i<4;i++)
   {
      digitalWrite(pines[i],HIGH);
      delay(1000);
      digitalWrite(pines[i],LOW);
      delay(1000);
   }
}
void RobotInit(void)
{
  pinMode(Relay, OUTPUT);
  pinMode(PWMR,OUTPUT);
  pinMode(PWML,OUTPUT);
  pinMode(M1LP,OUTPUT);
  pinMode(M1LN,OUTPUT);
  pinMode(M2RP,OUTPUT);
  pinMode(M2RN,OUTPUT);

  digitalWrite(Relay,LOW);
  digitalWrite(M1LP,LOW);
  digitalWrite(M1LN,LOW);
  digitalWrite(M2RN,LOW);
  digitalWrite(M2RP,LOW);

  analogWrite(PWML,0);
  analogWrite(PWMR,0);
}
