#include <stdio.h>
#include "system.h"
#include "LCD16x2.h"
#include "Keypad4x4.h"

#define RST 0x15
#define CNT 0x10
// Constantes del Teclado.
char Teclas[4][4] = {
	{'1','2','3','A'},
	{'4','5','6','B'},
	{'7','8','9','C'},
	{'*','0','#','D'},
};

char Tecla = 'n';

const int ROWS[4] = {20,21,22,23};
const int COLS[4] = {16,17,18,19};


//Constantes de LA pantalla LCD.
const char RS = 14;
const char RnW = 12;
const char En = 13;
const char D4 = 11;
const char D5 = 10;
const char D6 = 9;
const char D7 = 8;

char FirstROW[16];
char SecondROW[16];

//Maquina de Estados
enum MaquinaEstados{Encendido,Apagado};
enum MaquinaEstados Estado;

//Termianles de Actuadores.

const char MotorCanicas = 3;
const char Banda = 2;
const char Alarma = 4;
const char IndicadorCanicas = 5;
const char SensorCanicas = 24; // Input Terminal for TMR 0
const char SensorCajas = 7;

//Control Flow variables

uint8_t Latch = 0; // Latch Level 1 for overall operation ( staying in on and off state )
uint8_t LatchB = 0; // Lach Level 2 for second level of operatio of the machine ( staying in Paro, Arranque and configuration states0).
uint8_t LatchC = 0; //Latch Level 3 for thrid level of operation machine, (staying filling boxes with marbles or not.)

//Number Adquisition
char DataStorage[2]; //array for number storage from keypad
uint8_t counter = 0; //counter for number storage
uint8_t Number = 0; //Number recorden by the array DataStorage
unsigned int ContadorCanicasGlobal = 0; //total Marble counted
uint8_t CanicasActuales = 0; // MArblecounted by the TMR0 Terminal (D24)
uint8_t CajasCompletas = 0; // Box counter, after it filled with marbles.

enum ContadorCanicas{Paro,Arranque,Configuracion}; //overall operation of Marble counter Machine.
enum ContadorCanicas Modo; // Variable for mode Operation of Marble counter MAchine

enum Operacion{MoverCaja,ContarCanicas};
enum Operacion Paso;

char dato = 0;

void setup()
{
	Estado = Apagado;
	lcdBegin(RS,En,RnW,D4,D5,D6,D7);
	KeypadBegin(ROWS,COLS,Teclas);
	SerialBegin(9600);
	ContadorBegin();
	IOConfiguration();
	Latch = 0;
	LatchB = 0;
	LatchC = 0;
	lcdClear();
	lcdSetCursor(1,1);
	lcdPrint(" EQUIPO  WiCoRe ");
	lcdSetCursor(2,1);
	for(char i=0;i<16;i++)
	{
		lcdWrite('.');
		delay(100);
	}
	lcdClear();
	lcdSetCursor(1,1);
	lcdPrint(" Marble Counter ");
    	lcdSetCursor(2,1);
	for(char j=0;j<16;j++)
	{
		lcdWrite('.');
		delay(100);
	}
	delay(250);
}


void loop()
{
		switch(Estado)
		{
			case Apagado:
				lcdClear();
				lcdSetCursor(2,1);
				lcdPrint(" 'A'  to  Start ");
				while(Latch != 1)
				{
					Tecla = KeypadRead();
					if(Tecla == 'A')
					{
						Latch = 1;
					}
				}
				Latch = 0;
				Estado = Encendido;
			break;
			case Encendido:
				lcdClear();
				Modo = Paro;
				while(Latch != 1)
				{
					switch(Modo)
					{
						case Paro:
							lcdSetCursor(1,1);
							lcdPrint(" * --> Configur ");
							lcdSetCursor(2,1);
							lcdPrint(" # ---> Apagar  ");
                            Contador(RST);
							while(LatchB != 1)
							{
								Tecla = KeypadRead();
								if(Tecla == '*')
								{
									Modo = Configuracion;
									LatchB = 1;
								}
								else if(Tecla == '#')
								{
									Modo = Paro;
									LatchB = 1;
									Latch = 1;
								}
							}
							counter = 0;
							lcdClear();
							LatchB = 0;
						break;
						case Arranque:
							lcdPrint("Modo Arranque");
							delay(100);
							lcdClear();
							lcdSetCursor(1,1);
							sprintf(FirstROW,"iMQ:%i  TMC:%i",Number,ContadorCanicasGlobal);
							lcdPrint(FirstROW);
							lcdSetCursor(2,1);
							sprintf(SecondROW,"iMC:%i    Box:%i",CanicasActuales,CajasCompletas);
							lcdPrint(SecondROW);
							Paso = MoverCaja;
							while(LatchB != 1)
							{
								switch(Paso)
								{
									case MoverCaja:
										digitalWrite(Banda,HIGH);
										digitalWrite(MotorCanicas,LOW);
										while(LatchC != 1)
										{
											Contador(RST);
											if(digitalRead(SensorCajas) == HIGH)
											{
												delay(250);
												if(digitalRead(SensorCajas) == HIGH)
												{
													LatchC = 1;
													digitalWrite(Banda,LOW);
													digitalWrite(MotorCanicas,LOW);
												}
											}
											Tecla = KeypadRead();
											if(Tecla == '#')
											{
												digitalWrite(Banda,LOW);
												LatchC = 1;
												LatchB = 1;
												Modo = Paro;
											}
											else if(Tecla == '*')
											{
												digitalWrite(Banda,LOW);
												LatchC = 1;
												LatchB = 1;
												Modo = Configuracion;
											}
										}
										LatchC = 0;
										Paso = ContarCanicas;
									break;
									case ContarCanicas:
										digitalWrite(MotorCanicas,HIGH);
										digitalWrite(Banda,LOW);
										lcdClear();
										while(LatchC != 1) 
										{
											CanicasActuales = Contador(CNT);
											Tecla = KeypadRead();
											if(CanicasActuales >= Number)
											{
												digitalWrite(MotorCanicas,LOW);
												CajasCompletas++;
												ContadorCanicasGlobal += CanicasActuales;
												CanicasActuales = 0;
												Paso = MoverCaja;
												Contador(RST);
												LatchC = 1;
											}
											else if(Tecla == '#')
											{
												digitalWrite(MotorCanicas,LOW);
												Contador(RST);
												Number = 0;
												CajasCompletas = 0;
												Paso = MoverCaja;
												LatchC = 1;
												LatchB = 1;
												Modo = Paro;
												
											}
											else if(Tecla == '*')
											{
												digitalWrite(MotorCanicas,LOW);
												Contador(RST);
												Number = 0;
												CajasCompletas = 0;
												Paso = MoverCaja;
												LatchC = 1;
												LatchB = 1;
												Modo = Configuracion;
											}
											lcdSetCursor(1,1);
											sprintf(FirstROW,"MQ:%i  TMC:%i",Number,ContadorCanicasGlobal);
											lcdPrint(FirstROW);
											lcdSetCursor(2,1);
											sprintf(SecondROW,"MC:%i    Box:%u",CanicasActuales,CajasCompletas);
											lcdPrint(SecondROW);
										}
										LatchC = 0;
										CanicasActuales = 0;
									break;
								}
							}
							Number = 0;
							counter = 0;
							lcdClear();
							LatchB = 0;
						break;
						case Configuracion:
							lcdSetCursor(1,1);
							lcdPrint("Cantidad Canicas");
							while(LatchB != 1)
							{
								Tecla = KeypadRead();
								if((Tecla != NO_KEY) & (Tecla != '#') & (Tecla != '*'))
								{
									if(counter < 2)
									{
										lcdSetCursor(2,1);
										DataStorage[counter] = Tecla - 48;
										Number = (DataStorage[0] * 10) + DataStorage[1];
										sprintf(SecondROW,"%i Canicas",Number);
										lcdPrint(SecondROW);
                                        counter++;
									}
									else
									{
										lcdSetCursor(2,1);
                                        lcdPrint("                ");
										counter = 0;
									}
								}
								else if(Tecla == '#')
								{
									Modo = Paro;
									LatchB = 1;
								}
								else if(Tecla == '*')
								{
									Modo = Arranque;
									LatchB = 1;
								}
							}
							Number = (DataStorage[0] * 10) + DataStorage[1];
							lcdClear();
							LatchC = 0;
							LatchB = 0;
							Modo = Arranque;
						break;
					}
				}
				lcdClear();
				Latch = 0;
				Estado = Apagado;
			break;
		}
}

void IOConfiguration(void)
{
	//Outputs
	pinMode(Banda,OUTPUT);
	pinMode(MotorCanicas,OUTPUT);
	pinMode(IndicadorCanicas,OUTPUT);
	pinMode(Alarma,OUTPUT);
	pinMode(SensorCanicas,INPUT);
	pinMode(SensorCajas,INPUT);
	//Inital Values
    digitalWrite(MotorCanicas,LOW);
    digitalWrite(Banda,LOW);
	digitalWrite(Alarma,LOW);
	digitalWrite(IndicadorCanicas,LOW);
}
void PruebaLCD_Keypad(void)
{
	Tecla = KeypadRead();
	if(Tecla != NO_KEY)
	{
		lcdSetCursor(1,7);
		lcdWrite(Tecla);
		delay(250);
		lcdClear();
		if(Tecla == '#')
		{
			Latch = 1;
		}
	}
}

uint8_t Contador(char mode)
{
	if(mode == CNT)
	{
		return TMR0;
	}
	else if(mode == RST)
	{
		TMR0 = 0;
		return 0;
	}
}

void ContadorBegin(void)
{
	OPTION_REGbits.T0CS = 1;
	OPTION_REGbits.T0SE = 0;
	OPTION_REGbits.PSA = 1;
	OPTION_REGbits.PS2 = 0;
	OPTION_REGbits.PS1 = 0;
	OPTION_REGbits.PS0 = 0;
}