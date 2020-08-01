unsigned int led = 6;
unsigned int potenciometro = 0;
int analog;
int valor;
void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analog = analogRead(potenciometro);
  valor = map(analog,0,1023,0,255);
  analogWrite(led,valor);
}
