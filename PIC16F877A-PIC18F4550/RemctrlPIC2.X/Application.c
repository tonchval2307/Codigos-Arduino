#include <xc.h>
#include "xlcd.h"
#include <stdlib.h>
#include <stdio.h>
#include "system.h"
#include <usart.h>
#include <conio.h>

#define JTS 0x01
#define JTR 0x02
#define Sync dataVector[0]
#define Operation dataVector[1]
#define Data0 dataVector[2]
#define Data1 dataVector[3]
//Receiver
//MAX Practical PWM = 1000;
//MAX ADCValue = 1023;
enum estados{inicio,enviar,recibir};
int state;
unsigned int vectorSize = 4;
char dataVector[4];
char SendData[4];
void setup(void)
{
    SerialBegin(9600);
    state = inicio;
    SerialWrite(0x01);
    delay(50);
}

void loop(void)
{
    for(int i=0;i<256;i++)
    {
        SerialWrite(i);
        delay(200);
    }
//    if(SerialAvailable())
//    {
//        switch(state)
//        {
//            case inicio:
//                SerialWrite(0x01);
//                state = recibir;
//                break;
//            case enviar:
//                digitalWrite(19,LOW);
//                Sync = JTS;
//                for(int i=0;i<vectorSize;i++)
//                {
//                    SerialWrite(dataVector[i]);
//                }
//                if(Sync == JTS)
//                {
//                    state = recibir;
//                }
//                else
//                {
//                    state = enviar;
//                }
//                break;
//            case recibir:
//                digitalWrite(19,HIGH);
//                for(int i=0;i<vectorSize;i++)
//                {
//                    dataVector[i] = SerialRead();
//                }
//                CommandProcess(Operation,Data0,Data1);
//                if(Sync == JTR)
//                {
//                    state = enviar;
//                }
//                else
//                {
//                    state = recibir;
//                }
//                break;
//        }
//    }
}

void CommandProcess(char operator, char databyte1, char databyte2)
{
    if(operator == 1)
    {
        digitalWrite(22,HIGH);
    }
    else
    {
        digitalWrite(22,LOW);
    }
    if(databyte1 == 2)
    {
        digitalWrite(21,HIGH);
    }
    else
    {
        digitalWrite(21,LOW);
    }
    if(databyte2 == 3)
    {
        digitalWrite(20,HIGH);
    }
    else
    {
        digitalWrite(20,LOW);
    }
}