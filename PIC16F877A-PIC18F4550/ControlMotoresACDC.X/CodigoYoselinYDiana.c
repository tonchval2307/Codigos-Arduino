
#include <stdio.h>
#include "system.h"
#include "ControlMotores.h"
#include "LCD16x2.h"

#define CONTAR 0
#define RST 1
#define APAGADO 0
#define IZQUIERDA 1
#define DERECHA 2

//Terminales LCD16


//RS = 14 : EN = 13 : RW = 12 : D4 = 11 : D5 = 10 : D6 = 9 : D7 = 8


const int Rs = 14;
const int En = 13;
const int RW = 12;

const int D4 = 11;
const int D5 = 10;
const int D6 = 9;
const int D7 = 8;

const unsigned int MotorAC = 2;
const unsigned int MotorDCP = 3;
const unsigned int MotorDCN = 4;

const unsigned int SensorProximidad = 1;
const unsigned int Alarma = 6;

const unsigned int ControlEncendido = 0;

char FirstROW[16];
char SecondROW[16];

enum Maquina{Encendido,Apagado};
enum Maquina Estado = Apagado;


void setup()
{
	Estado = Apagado;
    lcdBegin(Rs,En,RW,D4,D5,D6,D7); 
    lcdClear();
	pinMode(Alarma,OUTPUT);
    pinMode(MotorDCP,OUTPUT);
    pinMode(MotorDCN,OUTPUT);
    pinMode(MotorAC,OUTPUT);
    lcdClear();
}


void loop()
{
	switch(Estado)
	{
		case Apagado:
			ModoApagado();
			if(PBRead(ControlEncendido) == HIGH)
			{
				delay(200);
				if(PBRead(ControlEncendido) == HIGH)
				{
					Estado = Encendido;
                    lcdClear();
				}
			}
			else
			{
				Estado = Apagado;
			}
		break;
		case Encendido:
			ModoEncendido();
			if(PBRead(ControlEncendido) == HIGH)
			{
				delay(200);
				if(PBRead(ControlEncendido) == HIGH)
				{
                    lcdClear();
                    for(char i=0;i<5;i++)
                    {
                        digitalWrite(Alarma,HIGH);
                        delay(250);
                        digitalWrite(Alarma,LOW);
                        delay(250);
                    }
					Estado = Apagado;
				}
			}
			else
			{
				Estado = Encendido;
			}
		break;
	}
}

void ModoApagado(void)
{
    lcdSetCursor(1,1);
    lcdPrint(" Equipo Divinas ");
    lcdSetCursor(2,1);
    lcdPrint("18:Feb:20-5BIEE");
	//Se coloca el mensaje con los datos del equipo:
	//Nombre del Equipo.
	//Fecha
	// Grupo.
}

void ModoEncendido(void)
{
    static int contar;
	contar = Contador(CONTAR);
    lcdSetCursor(1,1);
    sprintf(FirstROW,"Contador %i: ",contar);
    lcdPrint(FirstROW);
    lcdSetCursor(2,1);
	switch(contar)
	{
		case 0:
			digitalWrite(MotorAC,LOW);
			MotorDC(APAGADO);
            lcdPrint("DC-OFF/AC-OFF");
		break;
		case 1:
			digitalWrite(MotorAC,HIGH);
			MotorDC(DERECHA);
            
            lcdPrint("DC-DER/AC-ON ");
		break;
		case 2:
			digitalWrite(MotorAC,LOW);
			MotorDC(DERECHA);
            lcdPrint("DC-DER/AC-OFF");
		break;
		case 3:
			digitalWrite(MotorAC,HIGH);
			MotorDC(APAGADO);
            lcdPrint("DC-OFF/AC-ON ");
		break;
		case 4:
			digitalWrite(MotorAC,HIGH);
			MotorDC(IZQUIERDA);
            lcdPrint("DC-IZQ/AC-ON ");
		break;
		case 5:
			contar = Contador(RST);
		break;
	}
}
unsigned int Contador(unsigned int mode)
{
    const unsigned int Threshold = 20;
	static int cuenta;
	if(mode == CONTAR)
	{
		if(analogRead(SensorProximidad) >= Threshold)
        {
            delay(15);
            if(analogRead(SensorProximidad) >= Threshold)
            {
                return cuenta++;
            }
        }
        else
        {
            return cuenta;
        }
	}
	else if(mode == RST)
	{
        cuenta = 0;
		return 0;
	}
}

void MotorDC(unsigned int Mode)
{
	switch(Mode)
	{
		case IZQUIERDA:
			digitalWrite(MotorDCN,HIGH);
			digitalWrite(MotorDCP,LOW);
		break;
		case DERECHA:
			digitalWrite(MotorDCN,LOW);
			digitalWrite(MotorDCP,HIGH);
		break;
		case APAGADO:
			digitalWrite(MotorDCN,LOW);
			digitalWrite(MotorDCP,LOW);
		break;
	}
}
