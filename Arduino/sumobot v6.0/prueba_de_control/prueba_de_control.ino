int buff = 8;
bool data_serial[8];
int clk = 2;
int ps = 4;
int input = 3;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(clk,OUTPUT);
  pinMode(input,INPUT);
  pinMode(ps,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ps,LOW);
  for(int i=0;i<=buff-1;i++)
  {
    data_serial[i] = digitalRead(input);
    Serial.print(data_serial[i]);
    Serial.print(" , ");
  }
  Serial.println();
}

bool encender(int n)
{
  digitalWrite(clk,LOW);
  delay(n);
  digitalWrite(clk,HIGH);
  delay(n);
  return true;
}
void apagar(int n)
{
  digitalWrite(clk,HIGH);
  delay(n);
  digitalWrite(clk,LOW);
  delay(n);
}
