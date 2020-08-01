unsigned int led1 = 2;
unsigned int led2 = 3;
unsigned int led3 = 4;
unsigned int analog_input = 0;
double limit1 = 1;
double limit2 = 2.5;
double limit3 = 4;
int analog;
double voltage;
void setup() {
  // put your setup code here, to run once:
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analog = analogRead(analog_input);
  voltage = analog * 0.004;
  if(voltage < limit1)
  {
    valor_1();
  }
  if((voltage <limit2)&&(voltage>limit1))
  {
    valor_2();
  }
  if((voltage<limit3)&&(voltage>limit2))
  {
    valor_3();
  }
}

void valor_1(void)
{
  digitalWrite(led1,HIGH);
  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);
}
void valor_2(void)
{
  digitalWrite(led1,HIGH);
  digitalWrite(led2,HIGH);
  digitalWrite(led3,LOW);
}
void valor_3(void)
{
  digitalWrite(led1,HIGH);
  digitalWrite(led2,HIGH);
  digitalWrite(led3,HIGH);
}
