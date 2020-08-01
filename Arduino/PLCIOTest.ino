
unsigned int Output[4] = {13, 12, 11, 10};
unsigned int Input[8] = {9, 8, 7, 6, 5, 4, 3, 2};


void setup() {
  // put your setup code here, to run once:
  for(int i=0;i<4;i++)
  {
    pinMode(Output[i],OUTPUT);
  }
  for(int j=0;j<8;j++)
  {
    pinMode(Input[j],INPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0;i<4;i++)
  {
    digitalWrite(Output[i],HIGH);
    delay(250);
    digitalWrite(Output[i],LOW);
    delay(250);
  }
}
