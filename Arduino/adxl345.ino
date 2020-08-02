#include <SparkFun_ADXL345.h>

ADXL345 adxl = ADXL345();
//int x,y,z;
//declaracion de Estructura para almacenar Variables.
struct adxl345 {
  int x;
  int y;
  int z;
};

adxl345 aceleracion = {0,0,0};
void setup() {
  // put your setup code here, to run once:
  //Tap configuration
  Serial.begin(9600);
  adxl.printAllRegister();
  Serial.println();
  adxl.powerOn();
  adxl.setRangeSetting(16);
  adxl.setTapThreshold(50);
  adxl.setTapDuration(15);
  adxl.setDoubleTapLatency(80);
  adxl.setDoubleTapWindow(200);

  //Free Fall Configuration.
  adxl.setFreeFallThreshold(7); //(5-9) Recomended
  adxl.setFreeFallDuration(30); //(20-70) Recomended
  
}

void loop() {
  // put your main code here, to run repeatedly:
  adxl.readAccel(&aceleracion.x,&aceleracion.y,&aceleracion.z);
  //delay(500);
  Serial.print(aceleracion.x);
  Serial.print(",");
  Serial.print(aceleracion.y);
  Serial.print(",");
  Serial.print(aceleracion.z);
  Serial.print(",");
  Serial.println();
  delay(250);
}
