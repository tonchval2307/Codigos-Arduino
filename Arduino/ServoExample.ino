#include <Servo.h>

Servo direccion;

void setup() {
  // put your setup code here, to run once:
  direccion.attach(9);
  direccion.write(90);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=90;i>=135;i++)
  {
    direccion.write(i);
    delay(10);
  }
  delay(500);
  for(int i=135;i<=90;i--)
  {
    direccion.write(i);
    delay(10);
  }
  delay(500);
}
