#include "system.h"

void setup()
{
    SerialBegin(9600);
    pinMode(13,OUTPUT);
}

void loop()
{
    if(SerialAvailable() >= 0 )
    {
        digitalWrite(13,HIGH);
        delay(500);
        digitalWrite(13,LOW);
        delay(500);
    }
}