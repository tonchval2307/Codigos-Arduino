#include <xc.h>
#include <stdint.h>
#include <stdio.h>
#include <delays.h>
#include <xlcd.h>
#include <float.h>
#include "system.h"
#include <usart.h>

//void interrupt SPIProcess(void)
//{
//    char data;
//    if(SSPIF == 1)
//    {
//        data = SPIRead();
//        switch(data)
//        {
//            case 0x04:
//                WriteCmdXLCD(0x01);
//                SetDDRamAddr(0x00);
//                putrsXLCD("NO DATA");
//                SSPIF = 0;
//                break;
//            case 0x05:
//                WriteCmdXLCD(0x01);
//                SetDDRamAddr(0x00);
//                putrsXLCD("HEX Val : 5");
//                SSPIF = 0;
//                break;
//            case 0x06:
//                PantallaRun();
//                SSPIF = 0;
//                break;
//            case 0x07:
//                PantallaTestLocal();
//                SSPIF = 0;
//                break;
//            case 0x08:
//                PantallaTestRemote();
//                SSPIF = 0;
//                break;
//            case 0x09:
//                PantallaPruebaUltrasonico();
//                SSPIF = 0;
//                break;
//            case 0x0A:
//                PantallaRotacionLlantas();
//                SSPIF = 0;
//                break;
//            case 0x0B:
//                PantallaGPIOConfig();
//                SSPIF = 0;
//                break;
//            case 0x0C:
//                PantallaReadGPIO();
//                SSPIF = 0;
//                break;
//            case 0x0D:
//                PantallaSetRstGPIO();
//                SSPIF = 0;
//                break;
//        }
//    }
//}
