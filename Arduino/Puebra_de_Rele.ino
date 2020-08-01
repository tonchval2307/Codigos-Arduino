
const int in1 = 2;
const int in2 = 3;
const int in3 = 4;
const int in4 = 5;
const int in5 = 6;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("HOla");
  delay(1000);
  pinMode(13,OUTPUT);
  reley(in1,in2,in3,in4, in5);
}

void loop() {
  // put your main code here, to run repeatedly:
 digitalWrite(in1,HIGH);
 x();
 delay(3000);
 digitalWrite(in1,LOW);
 digitalWrite(in2,HIGH);
 x();
 delay(3000);
 digitalWrite(in2,LOW);
 digitalWrite(in3,HIGH);
 x();
 delay(3000);
 digitalWrite(in3,LOW);
 digitalWrite(in4,HIGH);
 x();
 delay(3000);
 digitalWrite(in4,LOW);
 digitalWrite(in5,HIGH);
 x();
 delay(3000);
 digitalWrite(in5,LOW);
  delay(1000);
}

void reley(const int a, const int b, const int c, const int d,const int e)
{
  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(c,OUTPUT);
  pinMode(d,OUTPUT);
  pinMode(e,OUTPUT);
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
}

void x(void)
{
  digitalWrite(13,HIGH);
  delay(1000);
  digitalWrite(13,LOW);
}

