
#include <AFMotor.h>


AF_DCMotor motorML(1, MOTOR12_64KHZ);
AF_DCMotor motorMR(2, MOTOR12_64KHZ);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Motor Test");
  motor.setSpeed(200);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("tick");
  motor.run(FORWARD);
  delay(1000);
  Serial.print("tock");
  motor.run(BACKWARD);
  delay(1000);

  Serial.print("tack");
  motor.run(RELEASE);
  delay(1000);
}

void detener(void)
{
  motorML.run(RELEASE);
  motorMR.run(RELEASE);
}

void adelante(int velocidad)
{
  motorML.setSpeed(velocidad);
  motorMR.setSpeed(velocidad);
  motorMR.run(FORWARD);
  motorML.run(FORWARD);
}

void atras(int veloidad)
{
    motorML.setSpeed(velocidad);
  motorMR.setSpeed(velocidad);
  motorMR.run(BACKWARD);
  motorML.run(BACKWARD);
}

