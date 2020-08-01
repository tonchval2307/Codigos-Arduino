//#include <stdio.h>
//#include "system.h"
//#include "LCD16x2.h"
//
//const char Rs = 20;
//const char En = 19;
//const char RW = 12;
//
//const char D4 = 15;
//const char D5 = 16;
//const char D6 = 17;
//const char D7 = 18;
//
//char data = 0;
//char datoA, datoB;
//void setup()
//{
//    SerialBegin(9600);
//    SerialPrint("Carlos");
//}
//
//
//void loop()
//{
//    if(SerialAvailable() >= 0)
//    {
//        data = SerialRead();
//        datoA = FirstEnablePulse(INSTRUCTION,READ,data);
//        SerialPrintLn(datoA);
//        delay(100);
//        datoB = SecondEnablePulse(INSTRUCTION,READ,data);
//        SerialPrintLn(datoB);
//    }
//}