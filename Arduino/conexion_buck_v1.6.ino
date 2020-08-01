enum estados{inicio,enviar,recibir};
int estado;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  configuracionPWM();
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
        Serial.print(analogRead(0));
        Serial.print(",");
        //Serial.flush();
        estado = recibir;
      break;
      case recibir:
        OCR1A = Serial.read();
        //analogWrite(6,Serial.read());
        //Serial.flush();
        estado = enviar;
      break;
     }
  }
}

void configuracionPWM(void)
{
  pinMode(9,OUTPUT);
  TCCR1A = 0;
  TCCR1B = 0;
  TCCR1A |= (1<<WGM10) | (1<<COM1A1) | (1<<COM1B1);
  TCCR1B |= (1<<CS10) | (1<<WGM12);
}

