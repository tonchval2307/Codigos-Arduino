int counter = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(6,OUTPUT);
  pinMode(7,INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(counter< 20)
  {
    if(digitalRead(7) != HIGH)
    {
      delay(100);
      if(digitalRead(7) != HIGH)
      {
        counter++;
        Serial.println(counter);
      }
    }
  }
}
