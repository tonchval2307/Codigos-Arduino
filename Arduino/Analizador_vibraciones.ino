#include <SparkFun_ADXL345.h>
ADXL345 adxl = ADXL345();

enum estados{inicio,enviar,recibir};
int estado;
int x,y,z; //varIABLES DE ACELERACION
///Command variables
int data[3] = {x,y,z};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  configuracion_acelerometro();
  estado = inicio;
  pinMode(6,OUTPUT);
  delay(1000);
  Serial.print("sync");
  Serial.flush();
}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available() >= 1)
  {
    switch(estado)
     {
      case inicio:
        Serial.print("sync");
        Serial.flush();
        estado = enviar;
      break;
      case enviar:
        //Serial.print(analogRead(0));
        //Serial.print(",");
        //Serial.flush();
        adxl.readAccel(&data[0],&data[1],&data[2]);
        for(int j=0;j<=2;j++)
        {
          Serial.print(data[j]);
          Serial.print(",");
        }
        /*
         * Serial.print(x);
        Serial.print(",");
        Serial.print(y);
        Serial.print(",");
        Serial.print(z);
        Serial.print(",");
         */
        estado = enviar;
      break;
      case recibir:
        //OCR1A = Serial.read();
        //analogWrite(6,Serial.read());
        //Serial.flush();
        estado = enviar;
      break;
     }
  }
}

void configuracion_acelerometro(void)
{
  adxl.powerOn();
  adxl.setRangeSetting(16);
  adxl.setTapThreshold(50);
  adxl.setTapDuration(15);
  adxl.setDoubleTapLatency(80);
  adxl.setDoubleTapWindow(200);
  adxl.set_bw(0x0B);
  adxl.setFreeFallThreshold(7); //(5-9) Recomended
  adxl.setFreeFallDuration(30);
}

