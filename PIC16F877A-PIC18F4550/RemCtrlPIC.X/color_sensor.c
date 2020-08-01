#include <xc.h>
#include <xlcd.h>
#include <stdlib.h>
#include <stdio.h>
#include "system.h"
#include <usart.h>
#include <conio.h>

/* Variables Globales para los Sensores RGB */
char SensorUnoRojo;
char SensorUnoVerde;
char SensorUnoAzul;
char SensorDosRojo;
char SensorDosVerde;
char SensorDosAzul;
char SensorTresRojo;
char SensorTresVerde;
char SensorTresAzul;

char TerminalAzul;
char TerminalRojo;
char TerminalVerde;

void SelectColorInit(char pinRed, char pinGreen, char pinBlue)
{
    TerminalRojo = pinRed;
    TerminalVerde = pinGreen;
    TerminalAzul = pinBlue;
    pinMode(pinRed, OUTPUT);
    pinMode(pinGreen,OUTPUT);
    pinMode(pinBlue,OUTPUT);
}

void SelectColor(char color)
{
    switch(color)
    {
        case 0: //Color Rojo
            digitalWrite(TerminalRojo,HIGH);
            digitalWrite(TerminalVerde,LOW);
            digitalWrite(TerminalAzul,LOW);
            break;
        case 1: // Color Verde
            digitalWrite(TerminalRojo,LOW);
            digitalWrite(TerminalVerde,HIGH);
            digitalWrite(TerminalAzul,LOW);
            break;
        case 2:  //Azul
            digitalWrite(TerminalRojo,LOW);
            digitalWrite(TerminalVerde,LOW);
            digitalWrite(TerminalAzul,HIGH);
            break;
    }
}

void SensoresRGBInit(char S1R, char S1G, char S1B,char S2R, char S2G, char S2B,char S3R, char S3G, char S3B)
{
    SensorUnoRojo = S1R;
    SensorUnoVerde = S1G;
    SensorUnoAzul = S1B;
    SensorDosRojo = S2R;
    SensorDosVerde = S2G;
    SensorDosAzul = S2B;
    SensorTresRojo = S3R;
    SensorTresVerde = S3G;
    SensorTresAzul = S3B;
    pinMode(SensorUnoRojo,OUTPUT);
    pinMode(SensorUnoVerde,OUTPUT);
    pinMode(SensorUnoAzul,OUTPUT);
    pinMode(SensorDosRojo,OUTPUT);
    pinMode(SensorDosVerde,OUTPUT);
    pinMode(SensorDosAzul,OUTPUT);
    pinMode(SensorTresRojo,OUTPUT);
    pinMode(SensorTresVerde,OUTPUT);
    pinMode(SensorTresAzul,OUTPUT);
    
}
void SensorRGB1(void)
{
    digitalWrite(SensorUnoRojo,HIGH);
    digitalWrite(SensorUnoVerde,HIGH);
    digitalWrite(SensorUnoAzul,HIGH);
}
void SensorRGB2(void)
{
    digitalWrite(SensorDosRojo,HIGH);
    digitalWrite(SensorDosVerde,HIGH);
    digitalWrite(SensorDosAzul,HIGH);  
}
void SensorRGB3(void)
{
    digitalWrite(SensorTresRojo,HIGH);
    digitalWrite(SensorTresVerde,HIGH);
    digitalWrite(SensorTresAzul,HIGH);
}
double ReadColorSensor(char sensor, char color)
{
    double Mfreq;
    switch(sensor)
    {
        case 1: //Sensor Uno
            SensorRGB1();
            SelectColor(color);
            Mfreq = Frequency();
            break;
        case 2:
            SensorRGB2();
            SelectColor(color);
            Mfreq = Frequency();
            break;
        case 3:
            SensorRGB3();
            SelectColor(color);
            Mfreq = Frequency();
            break;
    }
    return Mfreq;
}
