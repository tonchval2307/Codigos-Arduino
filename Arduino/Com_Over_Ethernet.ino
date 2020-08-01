
enum Modos{Idle,Enviar,Recibir};
enum Modos Estado;

// Constantes del Setup:
char dataUno = '0';
int Valor = 0;

void setup()
{
  ConfiguracionInicial();
  while(Valor  != 1)
  {
    Serial.println("10D");
    dataUno = Serial.read();
    if(dataUno == 'k')
    {
      Valor = 1;
    }
    else
    {
      Valor = 0;
    }
  }
  CosasDespuesDeDetectadoEnlace();
  Estado = Idle;
}

void loop()
{
  if(Serial.available() >= 0)
  {
    switch(Estado)
    {
      case Idle:
        
      break;
      case Enviar:
        
      break;
      case Recibir:
        
      break;
    }
  }
}


void CosasDespuesDeDetectadoEnlace(void)
{
  
}
void ConfiguracionInicial(void)
{
  
}
