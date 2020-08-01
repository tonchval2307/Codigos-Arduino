const int pinInhabilitadoA = 4;
const int pinInhabilitadoB = 5;
const int pinInhabilitadoC = 6;
const int VelAlta = 7;
const int VelBaja = 8;
const int Bomba = 9;
enum Status{Online,Offline};
enum ModoOperacion{BombaAlta,BombaBaja,SoloBomba,Apagado};
int Operacion;
int estado;
char data;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  estado = Offline;
  abanicoEstadoInicial();
  Operacion = Apagado;

}

void loop() {
  switch(estado)
  {
    case Offline:
      if(Serial.available())
      {
        estado = Online;
      }
      else
      {
        switch(Operacion)
        {
          case BombaAlta:
            ModoOperacionUno();
          break;
          case BombaBaja:
            ModoOperacionDos();
          break;
          case SoloBomba:
            ModoOperacionTres();
          break;
          case Apagado:
            ModoReposo();
          break;
        }
      }
    break;
    case Online:
      while(Serial.available())
      {
        data = Serial.read();
        switch(data)
        {
          case 'w':
            Operacion = BombaAlta;
            ModoOperacionUno();
          break;
          case 's':
            Operacion = BombaBaja;
            ModoOperacionDos();
          break;
          case 'a':
            Operacion = SoloBomba;
            ModoOperacionTres();
          break;
          case 'd':
            Operacion = Apagado;
            ModoReposo();
          break;
        }
      }
      estado = Offline;
    break;
  }
}

void ModoOperacionUno(void) //Bomba encendida Velocidad baja Encendida, Velocidad alta Apagada.
{
  EncenderBomba();
  VelocidadBaja();
}

void ModoOperacionDos(void) //Bomba Encendida velocidad baja Apagada, Velocidad Alta Encendida.
{
  EncenderBomba();
  VelocidadAlta();
}

void ModoOperacionTres(void)
{
  EncenderBomba();
  abanicoApagado();
}

void abanicoApagado(void)
{
  delay(100);
  digitalWrite(VelAlta,LOW);
  delay(1000);
  digitalWrite(VelBaja,LOW);
  delay(250);
}
void abanicoEstadoInicial(void)
{
  pinMode(pinInhabilitadoA,INPUT);
  pinMode(pinInhabilitadoB,INPUT);
  pinMode(pinInhabilitadoC,INPUT);
  pinMode(VelAlta,OUTPUT);
  pinMode(VelBaja,OUTPUT);
  pinMode(Bomba,OUTPUT);
  digitalWrite(VelAlta,LOW);
  digitalWrite(VelBaja,LOW);
  digitalWrite(Bomba,LOW);
  delay(250);
}

void VelocidadBaja(void)
{
  delay(100);
  digitalWrite(VelAlta,LOW);
  delay(500);
  digitalWrite(VelBaja,HIGH);
  delay(250);
}
void VelocidadAlta(void)
{
  delay(100);
  digitalWrite(VelBaja,LOW);
  delay(250);
  digitalWrite(VelAlta,HIGH);
  delay(250);
}
void EncenderBomba(void)
{
  delay(100);
  digitalWrite(Bomba,HIGH);
  delay(250);
}

void ApagarBomba(void)
{
  delay(100);
  digitalWrite(Bomba,LOW);
  delay(100);
}
void ModoReposo(void)
{
  digitalWrite(VelAlta,LOW);
  digitalWrite(VelBaja,LOW);
  digitalWrite(Bomba,LOW);
}
