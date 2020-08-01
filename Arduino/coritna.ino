
#define ENABLE 1
#define DISABLE 0
#define Bluetooth 1
#define WIFI 0
#define ARRIBA 1
#define ABAJO 0

const int stepper_dir = 4;
const int stepper_step = 3;

const int PasosUnCuarto = 200;

enum contadorCortina{Reposo, bajar, subir};
int posicion;
char data;
unsigned int contador = 0;
void setup() {
  // put your setup code here, to run once:
  ComunicationInit(Bluetooth);
  CortinaInit();
  posicion = Reposo;
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available())
  {
	switch(posicion)
	{
		case Reposo:
			data = Serial.read();
			if(data = 'a')
			{
				if(contador > 4)
				{
					if(contador > 8)
					{
						contador = 0;
					}
					else
					{
						posicion = subir;
					}
				}
				else
				{
					posicion = bajar;
				}
			}
		break;
		case bajar:
			contador++;
			if(contador > 4)
			{
				posicion = Reposo;
			}
			else
			{
				Bajar(10);
				posicion = Reposo;
			}
		break;
		case subir:
			contador++;
			Subir(10);
			posicion = Reposo;
		break;
	}
  }

}
void Subir(const int retardo)
{
	digitalWrite(stepper_dir,ARRIBA)
	for(int i=0;i<=PasosUnCuarto;i++)
	{
	digitalWrite(stepper_step,HIGH);
	delay(retardo);
	digitalWrite(stepper_step,LOW);
	delay(retardo);
	}
}
void Bajar(const int retardo)
{
	digitalWrite(stepper_dir,ABAJO)
	for(int i=0;i<=PasosUnCuarto;i++)
	{
	digitalWrite(stepper_step,HIGH);
	delay(retardo);
	digitalWrite(stepper_step,LOW);
	delay(retardo);
	}
}

void CortinaInit(void)
{
  pinMode(stepper_dir,OUTPUT);
  pinMode(stepper_step,OUTPUT);
}

void ComunicationInit(char mode)
{
  if(mode == WIFI)
  {
    
  }
  else if(mode == Bluetooth)
  {
    Serial.begin(9600);
  }
}