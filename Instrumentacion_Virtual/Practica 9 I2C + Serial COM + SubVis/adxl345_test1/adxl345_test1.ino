#include <SparkFun_ADXL345.h>

ADXL345 adxl = ADXL345();
int x,y,z;
void setup() {
  // put your setup code here, to run once:
  //Tap configuration
  Serial.begin(9600);
  adxl.powerOn();
  adxl.setRangeSetting(4);
  adxl.setTapThreshold(50);
  adxl.setTapDuration(15);
  adxl.setDoubleTapLatency(80);
  adxl.setDoubleTapWindow(200);
  adxl.set_bw(0x0B);
  Serial.println(adxl.getRate());

  //Free Fall Configuration.
  adxl.setFreeFallThreshold(7); //(5-9) Recomended
  adxl.setFreeFallDuration(30); //(20-70) Recomended
  
}

void loop() {
  // put your main code here, to run repeatedly:
  adxl.readAccel(&x,&y,&z);
  //delay(500);
  Serial.print(x);
  Serial.print(",");
  Serial.print(y);
  Serial.print(",");
  Serial.print(z);
  Serial.print(",");
}
