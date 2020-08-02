enum estados{subida,bajada};
int estado;
int i;
void setup() {
  // put your setup code here, to run once:
  pinMode(9,OUTPUT);
  pinMode(13,OUTPUT);
  TCCR1A = 0;
  TCCR1B = 0;
  TCCR1A |= (1<<WGM10) | (1<<COM1A1) | (COM1B1);
  TCCR1B |= (1<<CS10) | (1<<WGM12);
  estado = subida;
 // i = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  OCR1A = 128;

}

void maquina_estados(void)
{
  switch(estado)
  {
    case subida:
      if(i >= 255)
      {
        estado = bajada;
      }
      else
      {
        OCR1A = i;
        delay(10);
        i++;
      }
    break;
    case bajada:
      if(i <= 0)
      {
        estado = subida;
      }
      else
      {
        OCR1A = i;
        delay(10);
        i--;
      }
    break;
  }
}

