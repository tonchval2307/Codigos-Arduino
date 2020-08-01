#include <xc.h>
#include "xlcd.h"
#include <stdlib.h>
#include <stdio.h>
#include "system.h"
#include <usart.h>
#include <conio.h>


void stateMachine1(void)
{
    
}

//void setup(void)
//{
//    SerialBegin(9600);
//    delay(50);
//    state = inicio;
//    TRISCbits.RC2 = 0;
//    SerialWrite(0);
//    pinMode(22,OUTPUT);
//}
//
//void loop(void)
//{
//    if(SerialAvailable())
//    {
//        switch(state)
//        {
//            case inicio:
//                SerialWrite(1);
//                state = recibir;
//                break;
//            case enviar:
//                SerialWrite(data2);
//                state = recibir;
//                break;
//            case recibir:
//                data2 = 4 *SerialRead();
//                if(data2 >= 255)
//                {
//                    digitalWrite(22,HIGH);
//                }
//                else
//                {
//                    digitalWrite(22,LOW);
//                }
//                analogWrite(4,data2);
//                state = enviar;
//                break;
//        }
//    }
//}