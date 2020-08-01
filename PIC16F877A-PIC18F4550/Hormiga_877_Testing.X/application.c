#include "system.h"
#include "Servo.h"

void setup()
{
    ServoAttach(14);
}

void loop()
{
    ServoWrite(100);
    delay(100);
    ServoWrite(200);
    delay(100);
    ServoWrite(300);
    delay(100);
}