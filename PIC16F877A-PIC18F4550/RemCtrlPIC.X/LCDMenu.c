#include <xc.h>
#include <xlcd.h>
#include <stdint.h>
#include <stdio.h>
#include "system.h"

void PantallaStartingState(void)
{
    WriteCmdXLCD(0x01); //Clear LCD
    SetDDRamAddr(0x00);
    putrsXLCD(".....SYSTEM.....");
    SetDDRamAddr(0x40);
    putrsXLCD("....STARTING....");
    delay(1000);
    for(int i=0;i<5;i++)
    {
        WriteCmdXLCD(0x1C);
        delay(50);
    }
    delay(1000);
    for(int j=0;j<5;j++)
    {
        WriteCmdXLCD(0x18);
        delay(50);
    }
    delay(1000);
}
void PantallaRun(void)
{
    WriteCmdXLCD(0x01); //Clear LCD
    SetDDRamAddr(0x00);
    putrsXLCD("UP***| RUN |****");
    SetDDRamAddr(0x40);
    putrsXLCD("DWN**|-----|****");
}
void PantallaTestLocal(void)
{
    WriteCmdXLCD(0x01); //Clear LCD
    SetDDRamAddr(0x00);
    putrsXLCD("UP*|TEST LOCAL|*");
    SetDDRamAddr(0x40);
    putrsXLCD("DWN*|---------|*");
}
void PantallaTestRemote(void)
{
    WriteCmdXLCD(0x01); //Clear LCD
    SetDDRamAddr(0x00);
    putrsXLCD("UP**|TEST RMT|**");
    SetDDRamAddr(0x40);
    putrsXLCD("DWN*|--------|**");
}
void PantallaGPIOConfig(void)
{
    WriteCmdXLCD(0x01); //Clear LCD
    SetDDRamAddr(0x00);
    putrsXLCD("UP**|GPIO CFG|**");
    SetDDRamAddr(0x40);
    putrsXLCD("DWN*|--------|**");
}
void PantallaSetRstGPIO(void)
{
    WriteCmdXLCD(0x01); //Clear LCD
    SetDDRamAddr(0x00);
    putrsXLCD("UP**|S/R GPIO|**");
    SetDDRamAddr(0x40);
    putrsXLCD("DWN*|--------|**");
}
void PantallaReadGPIO(void)
{
    WriteCmdXLCD(0x01); //Clear LCD
    SetDDRamAddr(0x00);
    putrsXLCD("UP**|GPIO READ|*");
    SetDDRamAddr(0x40);
    putrsXLCD("DWN*|---------|*");
}
void PantallaRotacionLlantas(void)
{
    WriteCmdXLCD(0x01); //Clear LCD
    SetDDRamAddr(0x00);
    putrsXLCD("UP**|WHEL TEST|*");
    SetDDRamAddr(0x40);
    putrsXLCD("DWN*|---------|*");
}
void PantallaPruebaUltrasonico(void)
{
    WriteCmdXLCD(0x01); //Clear LCD
    SetDDRamAddr(0x00);
    putrsXLCD("UP**|USC TEST|**");
    SetDDRamAddr(0x40);
    putrsXLCD("DWN*|--------|**");
}

void ProcessCommand(char data)
{
    switch(data)
    {
        case 0x30:
            WriteCmdXLCD(0x01);
            SetDDRamAddr(0x40);
            putrsXLCD("Cinco");
            break;
        case 0x31:
            WriteCmdXLCD(0x01);
            SetDDRamAddr(0x40);
            putrsXLCD("Seis");
            break;
        case 0x32:
            WriteCmdXLCD(0x01);
            SetDDRamAddr(0x40);
            putrsXLCD("Siete");
            break;
        case 0x33:
            WriteCmdXLCD(0x01);
            SetDDRamAddr(0x40);
            putrsXLCD("Ocho");
            break;
        case 0x34:
            WriteCmdXLCD(0x01);
            SetDDRamAddr(0x40);
            putrsXLCD("Nueve");
            break;
        case 0x35:
            WriteCmdXLCD(0x01);
            SetDDRamAddr(0x40);
            putrsXLCD("Dos");
            break;
        case 0x36:
            WriteCmdXLCD(0x01);
            SetDDRamAddr(0x40);
            putrsXLCD("Uno");
            break;
        case 0x37:
            WriteCmdXLCD(0x01);
            SetDDRamAddr(0x40);
            putrsXLCD("LLLL");
            break;
        case 0x38:
            WriteCmdXLCD(0x01);
            SetDDRamAddr(0x40);
            putrsXLCD("EEEE");
            break;
        case 0x39:
            WriteCmdXLCD(0x01);
            SetDDRamAddr(0x40);
            putrsXLCD("DDDD");
            break;
        case 0x3A:
            WriteCmdXLCD(0x01);
            SetDDRamAddr(0x40);
            putrsXLCD("IIII");
            break;
        case 0x3B:
            WriteCmdXLCD(0x01);
            SetDDRamAddr(0x40);
            putrsXLCD("UUUU");
            break;
        case 0x3C:
            WriteCmdXLCD(0x01);
            SetDDRamAddr(0x40);
            putrsXLCD("BBBB");
            break;
        case 0x3D:
            WriteCmdXLCD(0x01);
            SetDDRamAddr(0x40);
            putrsXLCD("AAAA");
            break;
        case 0x3E:
            WriteCmdXLCD(0x01);
            SetDDRamAddr(0x40);
            putrsXLCD("SSSS");
            break;
        case 0x3F:
            WriteCmdXLCD(0x01);
            SetDDRamAddr(0x40);
            putrsXLCD("RRRR");
            break;
    }
}
