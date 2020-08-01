//Comunicacion Arduino con Bluetooth v0.1 Norma

char dato;
enum estados{DAQ,Exe};
int estado;
void setup() {
  // put your setup code here, to run once:
  blutot();
  estado = DAQ;
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available())
  {
    switch(estado)
    {
      case DAQ:
        dato = Serial.read();
        estado = Exe;
      break;
      case Exe:
        process_command(dato);
        estado = DAQ;
      break;
    }
  }
  else
  {
    detenido();
  }
}

void blutot(void)
{
  Serial.begin(9600);
}

void l293d(void)
{
  
}

void detenido(void)
{
  
}
void process_command(char info)
{
  switch(info)
  {
    case 'A':
      adelante();
    break;
    case 'B':
      atras();
    break;
    case 'C':
      izquierda();
    break;
    default:
      detenido();
    break;
  }
}

