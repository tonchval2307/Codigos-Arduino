int analog = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(12,INPUT);
  pinMode(13,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
    analog = analogRead(0);
    Serial.println(analog);
    delay(50);
}
