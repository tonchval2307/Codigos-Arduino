const int trg = 4;
const int eco = 3;
double data;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trg,OUTPUT);
  pinMode(eco,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available())
  {
    data = measure_distance(trg,eco);
    Serial.println(data);
    delay(500);
  }
}

double measure_distance(byte trigger,byte echo)
{
  int duration;
  digitalWrite(trigger,LOW);
  delayMicroseconds(2);
  digitalWrite(trigger,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger,LOW);
  duration = pulseIn(echo,HIGH);
  return (duration * 0.034)/2;
}
