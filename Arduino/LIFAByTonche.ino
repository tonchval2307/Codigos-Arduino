#define PINMODE       0x05
#define DIGITALWRITE  0x06
#define DIGTALREAD    0x07
#define ANALOGREAD    0x08
#define ANALOGWRITE   0x09

enum MaquinaEstados{Enviar,Recibir,Decode};
enum MaquinaEstados Estado;

uint8_t BufferLenght = 4;
char Informacion[4];
char DataEnviar[2];
char DatoDeEntrada = '0';
char DatoEstadoEnviar = '0';
uint8_t Val = 0;
uint16_t Dato = 0;


uint8_t Valor = 0;
char dada = 0;
void setup(void)
{
  Serial.begin(9600);
    pinMode(14,OUTPUT);
  while(Valor != 1)
  {
        digitalWrite(14,HIGH);
        dada = Serial.read();
        Serial.write('k');
        if(dada == 'k')
        {
            Valor = 1;
        }
        else
        {
            Valor = 0;
        }
  }
    Valor = 0;
    dada = 0;
    digitalWrite(14,LOW);
  Estado = Recibir;
}

void loop(void)
{
  if(Serial.available() >= 0)
  {
    switch(Estado)
    {
      case Decode:
        
        Dato = ProcessCommand(Informacion[0],Informacion[1],Informacion[2],Informacion[3]);
        DataEnviar[0] = Dato & 0xFF00;
        DataEnviar[0] = (Dato >> 8);
        DataEnviar[1] = Dato & 0xFF;
        Estado = Enviar;
      break;
      case Recibir:
        while(Valor != 1)
        {
          for(int i=0;i<BufferLenght;i++)
          {
            Informacion[i] = Serial.read();
          }
                    dada = Serial.read();
                    if(dada == 'k')
                    {
                        Valor = 1;
                    }
                    else
                    {
                        Valor = 0;
                    }
        }
                dada = 0;
                Valor = 0;
                Estado = Decode;
      break;
      case Enviar:
                while(Valor != 1)
                {
                    for(int j=0;j<2;j++)
                    {
                        Serial.write(DataEnviar[j]);
                        
                    }
                    Serial.write(';');
                    dada = Serial.read();
                    if(dada == 'k')
                    {
                        Valor = 1;
                    }
                    else
                    {
                        Valor = 0;
                    }
                }
                Valor = 0;
                dada = 0;
        Estado = Recibir;
      break;
    }
  }
}

uint16_t ProcessCommand(uint8_t instruction, uint8_t port, uint8_t MSBData, uint8_t LSBData)
{
  uint16_t data = 0;
    switch(instruction)
    {
      case PINMODE:
        if(port > 24)
        {
          port = 24;
        }
        pinMode(port,LSBData);
        return 1;
      break;
      case DIGITALWRITE:
        if(port > 24)
        {
          port = 24;
        }
        digitalWrite(port,LSBData);
        return LSBData;
      break;
      case DIGTALREAD:
        if(port > 24)
        {
          port = 24;
        }
        return digitalRead(port);
      break;
      case ANALOGREAD:
        return analogRead(port);
      break;
      case ANALOGWRITE:
//                Limites Agregados varian segund la placa Hormiga que se use
//        if(port > 6)
//        {
//          port = 6;
//        }
//        else if(port < 5)
//        {
//          port = 5;
//        }
        data = (MSBData << 8) + LSBData;
        analogWrite(port,data);
        return 1;
      break;
    }
}
