enum estados{inicio,enviar,recibir};
int estado;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(6,OUTPUT);
  estado = inicio;
  delay(1000);
  Serial.print("sync");
  Serial.flush();
  
}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available() >= 1)
  {
    switch(estado)
     {
      case inicio:
        Serial.print("sync");
        Serial.flush();
        estado = recibir;
      break;
      case enviar:
        Serial.write(analogRead(0));
        //Serial.print(",");
        Serial.flush();
        estado = recibir;
      break;
      case recibir:
        analogWrite(6,Serial.read());
        Serial.flush();
        estado = enviar;
      break;
     }
  }
}
