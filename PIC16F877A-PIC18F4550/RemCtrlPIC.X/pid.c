#include <xc.h>
#include <xlcd.h>
#include <stdint.h>
#include <stdio.h>
#include "system.h"
/*
    `5 Octubre 2018 ---- La Maquina de Estados para configurara el controlador
 * En Modo Automatico o en Modo Manual y las constantes del controlador
 * esta incompleta. Revisar.
 */
char vKp[16];
char vKi[16];
char vKd[16];
char volts[16];
enum pantallas{
    Start, ProgramKP, ProgramKD, ProgramKI, Run, Set
};
unsigned int estado;
char marcador = 100;
char Duty[16];
double proporcional = 12;
double integral = 0.5;
double derivativo = 0.3;
double corriente = 0;
double SetPoint = 0;
double SalidaControl;
double adc;
double current;

void InitController(void)
{
    LCDInit();
    WriteCmdXLCD(0x06);
    WriteCmdXLCD(0x0C);
    adc = 0;
    SetPID1SampleTime(0.05);
    SetPID1Tunings(proporcional, derivativo, integral);
    SetOutputLimits(0,100);
    pinMode(20,OUTPUT);
}

void controllerOperation(void)
{
    digitalWrite(20,HIGH);
    delay(100);
    digitalWrite(20,LOW);
    delay(100);
    switch(estado)
    {
        case Start:
            WriteCmdXLCD(0x01);
            SetDDRamAddr(0x00);
            putrsXLCD("Control PID v1.0");
            SetDDRamAddr(0x40);
            putrsXLCD("E1=D E0=P E2=I");
            if(PBRead(0) == 0)  //Menu Proporcional
            {
                estado = ProgramKP;
            }
            else if(PBRead(1) == 1) //Menu Derivativo
            {
                estado = ProgramKD;
            }
            else if(PBRead(2) == 1) //Menu Integral
            {
                estado = ProgramKI;
            }
            else
            {
                estado = Start;
            }
            break;
        case ProgramKP:
            WriteCmdXLCD(0x01);
            SetDDRamAddr(0x00);
            sprintf(vKp,"KP = %f",proporcional);
            putrsXLCD(vKp);
            SetDDRamAddr(0x40);
            putrsXLCD("E1=+ E0=I E2=-");
            if(PBRead(0) == 0)  //Ir a Integral
            {
                estado = ProgramKI;
            }
            else if(PBRead(1) == 1) //Incrementar Proporcional
            {
                proporcional += 0.1;
            }
            else if(PBRead(2) == 1) //Decrementar Proporcional
            {
                proporcional -= 0.1;
            }
            else
            {
                estado = ProgramKP;
            }
            break;
        case ProgramKI:
            WriteCmdXLCD(0x01);
            SetDDRamAddr(0x00);
            sprintf(vKi,"KI = %f",integral);
            putrsXLCD(vKi);
            SetDDRamAddr(0x40);
            putrsXLCD("E1=+ E0=D E2=-");
            if(PBRead(0) == 0)  //Ir a Derivativo
            {
                estado = ProgramKD;
            }
            else if(PBRead(1) == 1) //Incrementar Integral
            {
                integral += 0.05;
            }
            else if(PBRead(2) == 1) //Decrementar Integral
            {
                integral -= 0.05;
            }
            else
            {
                estado = ProgramKI;
            }
            break;
        case ProgramKD:
            WriteCmdXLCD(0x01);
            SetDDRamAddr(0x00);
            sprintf(vKd,"KI = %f",derivativo);
            putrsXLCD(vKd);
            SetDDRamAddr(0x40);
            putrsXLCD("E1=+ E0=S E2=-");
            if(PBRead(0) == 0)  //Ir a Derivativo
            {
                estado = Set;
            }
            else if(PBRead(1) == 1) //Incrementar Derivativo
            {
                derivativo += 0.05;
            }
            else if(PBRead(2) == 1) //Decrementar Derivtivo
            {
                derivativo -= 0.05;
            }
            else
            {
                estado = ProgramKD;
            }
            break;
        case Set:
            WriteCmdXLCD(0x01);
            SetDDRamAddr(0x00);
            putrsXLCD("Apply Changes?");
            SetDDRamAddr(0x40);
            putrsXLCD("E1/0=OK E2=STR");
            if(PBRead(0) == 0)  //Ejecutar PID
            {
                estado = Run;
            }
            else if(PBRead(1) == 1) //Ir a Ejecutar PID
            {
                estado = Run;
            }
            else if(PBRead(2) == 1) //Regresar al Mnu
            {
                estado = Start;
            }
            else
            {
                estado = Set;
            }
            break;
        case Run:
            break;
    }
    adc = analogRead(0);
    SetPoint = analogRead(1);
    adc = rescale(adc,0,1023,0,100);
    SetPoint = rescale(SetPoint,0,1023,0,100);
    SalidaControl = ComputePID1(adc,SetPoint);
    SalidaControl = rescale(SalidaControl,0,100,0,500);
    analogWrite(3,SalidaControl);
    sprintf(Duty, "adc = %f", adc);
    sprintf(volts,"Control = %f",SalidaControl);
    WriteCmdXLCD(0x01);
    SetDDRamAddr(0x00);
    putrsXLCD(Duty);
    SetDDRamAddr(0x40);
    putrsXLCD(volts);
}