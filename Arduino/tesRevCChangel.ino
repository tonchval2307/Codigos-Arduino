#define Diez 10
#define Nueve 9
#define Relay 8

#define M2RN 7
#define PWMR 6
#define PWML 5
#define M2RP 4
#define M1LN 3
#define M1LP 2

char data = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Diez,OUTPUT);
  pinMode(Nueve,OUTPUT);
  pinMode(Relay,OUTPUT);
  pinMode(M2RN,OUTPUT);
  pinMode(M2RP,OUTPUT);
  pinMode(M1LN,OUTPUT);
  pinMode(M1LP,OUTPUT);
  pinMode(PWML,OUTPUT);
  pinMode(PWMR,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() >= 0)
  {
    data = Serial.read();
    switch(data)
    {
      case 'a':
        digitalWrite(Diez,HIGH);
        digitalWrite(Nueve,LOW);
        digitalWrite(Relay,LOW);
        digitalWrite(M2RN,LOW);
        digitalWrite(M2RP,LOW);
        digitalWrite(M1LN,LOW);
        digitalWrite(M1LP,LOW);
        digitalWrite(PWML,LOW);
        digitalWrite(PWMR,LOW);
      break;
      case 'b':
        digitalWrite(Diez,LOW);
        digitalWrite(Nueve,HIGH);
        digitalWrite(Relay,LOW);
        digitalWrite(M2RN,LOW);
        digitalWrite(M2RP,LOW);
        digitalWrite(M1LN,LOW);
        digitalWrite(M1LP,LOW);
        digitalWrite(PWML,LOW);
        digitalWrite(PWMR,LOW);
      break;
      case 'c':
        digitalWrite(Diez,LOW);
        digitalWrite(Nueve,LOW);
        digitalWrite(Relay,HIGH);
        digitalWrite(M2RN,LOW);
        digitalWrite(M2RP,LOW);
        digitalWrite(M1LN,LOW);
        digitalWrite(M1LP,LOW);
        digitalWrite(PWML,LOW);
        digitalWrite(PWMR,LOW);
      break;
      case 'd':
        digitalWrite(Diez,LOW);
        digitalWrite(Nueve,LOW);
        digitalWrite(Relay,LOW);
        digitalWrite(M2RN,LOW);
        digitalWrite(M2RP,HIGH);
        digitalWrite(M1LN,LOW);
        digitalWrite(M1LP,HIGH);
        digitalWrite(PWML,HIGH);
        digitalWrite(PWMR,HIGH);
      break;
      case 'e':
        digitalWrite(Diez,LOW);
        digitalWrite(Nueve,LOW);
        digitalWrite(Relay,LOW);
        digitalWrite(M2RN,HIGH);
        digitalWrite(M2RP,LOW);
        digitalWrite(M1LN,HIGH);
        digitalWrite(M1LP,LOW);
        digitalWrite(PWML,HIGH);
        digitalWrite(PWMR,HIGH);
      break;
      case 'f':
        digitalWrite(Diez,LOW);
        digitalWrite(Nueve,LOW);
        digitalWrite(Relay,LOW);
        digitalWrite(M2RN,LOW);
        digitalWrite(M2RP,LOW);
        digitalWrite(M1LN,LOW);
        digitalWrite(M1LP,LOW);
        digitalWrite(PWML,LOW);
        digitalWrite(PWMR,LOW);
      break;
    }
  }
}
