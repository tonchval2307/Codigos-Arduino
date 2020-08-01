int analog;

void setup() {
  // put your setup code here, to run once:
  pinMode(2,OUTPUT);
  pinMode(3,INPUT);
  digitalWrite(13,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(20);
  digitalWrite(2,HIGH);
  digitalWrite(13,HIGH);
  delay(20);
  digitalWrite(2,LOW);
  digitalWrite(13,LOW);

}
