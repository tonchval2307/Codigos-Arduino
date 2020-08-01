#include <xc.h>
#include <xlcd.h>
#include <stdlib.h>
#include <stdio.h>
#include "system.h"
#include <usart.h>
#include <conio.h>
//Emmiter
//MAX Practical PWM = 500;
//MAX ADCValue = 1023;
enum estados{inicio,enviar,recibir};
int estado1;
char data;
unsigned char dato[] = "Carlos Tonche /n";
void setup(void)
{
    SerialBegin(9600);
    delay(50);
}

void loop(void)
{
    if(PBRead(0))
    {
        SerialWrite(0x02);
        delay(20);
    }
    else if(PBRead(1))
    {
        SerialWrite(0x03);
        delay(20);
    }
    else if(PBRead(2))
    {
        SerialWrite(0x04);
        delay(20);
    }
}