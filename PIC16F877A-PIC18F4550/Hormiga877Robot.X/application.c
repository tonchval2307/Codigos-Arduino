#include "system.h"
#include "RobotMovimientos.h"

uint8_t VelocidadA = 5;
uint8_t VelocidadB = 6;

uint8_t InUno = 8;
uint8_t InDos = 9;
uint8_t InTres = 10;
uint8_t InCuatro = 11;
uint8_t Led = 13;
char data = '0';

void setup()
{
    SerialBegin(9600);
    L298NInit(InUno,InDos,InTres,InCuatro,VelocidadA,VelocidadB);
    pinMode(Led,OUTPUT);
    digitalWrite(Led,LOW);
}

void loop()
{
    if(SerialAvailable() >=0)
    {
        data = SerialRead();
        switch(data)
        {
            case 'w':
                Adelante(500);
                SerialPrintLn("Adelante");
                break;
            case 's':
                Atras(500);
                SerialPrintLn("Atras");
                break;
            case 'a':
                Izquierda(500);
                SerialPrintLn("Izquierda");
                break;
            case 'd':
                Derecha(500);
                SerialPrintLn("Derecha");
                break;
            case 'c':
                Detener();
                SerialPrintLn("Detener");
                break;
            case 'f':
                digitalWrite(Led,HIGH);
                SerialPrintLn("Caso F");
                break;
            case 'j':
                digitalWrite(Led,LOW);
                SerialPrintLn("Caso J");
                break;
        }
    }
}



