

double analogMax = 0;
double current = 0;
double analogOut = 0;

double analogData[20];
void setup() {
  // put your setup code here, to run once:
  pinMode(6,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0;i<20;i++)
  {
    analogData[i] = analogRead(0);
    delay(50);
  }
  for(int j=0;j<20;j++)
  {
    if(analogData[j] > analogData[j - 1])
    {
      analogData[j] = analogMax;
    }
  }
  analogMax = map(analogMax,0,5,0,0.5);
  analogMax = analogMax / 0.14;
  analogMax = analogMax / 1.4142;
  analogMax = map(analogMax,0,1,0,255);
  
  analogWrite(6,analogMax);
}
