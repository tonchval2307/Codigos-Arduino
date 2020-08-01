#include <Servo.h>
#define S0 2
#define S1 3
#define S2 4
#define S3 5
#define sensorOut 6
Servo topServo;
Servo bottomServo;
int frequency = 0;
int color=0;
void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  // Setting frequency-scaling to 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);
  topServo.attach(7);
  bottomServo.attach(8);
  Serial.begin(9600);
}
void loop() {
  
  topServo.write(60);
  delay(2000);
  
  color = readColor();
  delay(10);  
  switch (color) {
    case 1:
    bottomServo.write(50);
    break;
    case 2:
    bottomServo.write(75);
    break;
    case 3:
    bottomServo.write(100);
    break;
    case 4:
    bottomServo.write(125);
    break;
    case 5:
    bottomServo.write(150);
    break;
    case 6:
    bottomServo.write(175);
    break;
    
    case 0:
    break;
  }
  delay(1000);
 topServo.write(85);
    delay(500);
 topServo.write(2);
  delay(500);
  
  color = 0;
}
// Custom Function - readColor()
int readColor() {
  // Setting red filtered photodiodes to be read
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  int R = frequency;
  // Printing the value on the serial monitor
  Serial.print("R= ");//printing name
  Serial.print(frequency);//printing RED color frequency
  Serial.print("  ");
  delay(50);
  // Setting Green filtered photodiodes to be read
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  int G = frequency;
  // Printing the value on the serial monitor
  Serial.print("G= ");//printing name
  Serial.print(frequency);//printing RED color frequency
  Serial.print("  ");
  delay(50);
  // Setting Blue filtered photodiodes to be read
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  int B = frequency;
  // Printing the value on the serial monitor
  Serial.print("B= ");//printing name
  Serial.print(frequency);//printing RED color frequency
  Serial.println("  ");
  delay(50);
if((R>240) && (R<275) && (G>240) && (G<275) && (B>240) && (B<275))    // White
    {
      Serial.println("Color is white");
    }
    else if((R>155) && (R<165) && (G>155) && (G<165) && (B>100) && (B<110))  // Blue
    {
      Serial.println("Color is blue");
      color = 1;
      
    }else if((R>115) && (R<125) && (G>165) && (G<175) && (B>120) && (B<130))  // Orange
    {
      Serial.println("Color is Orange");
      color = 2; 
      
    }else if((R>145) && (R<160) && (G>175) && (G<185) && (B>125) && (B<140))  // Brown
    {
      Serial.println("Color is brown");
      color = 3; 
    }
    else if((R>105) && (R<115) && (G>125) && (G<140) && (B>110) && (B<130))  // Yellow
    {
      Serial.println("Color is yellow"); 
      color = 4;
    }
    else if((R>125) && (R<140) && (G>165) && (G<180) && (B>125) && (B<135))  // Red
    {
      Serial.println("Color is red");
      color = 5;    
    }
    else if((R>155) && (R<165) && (G>155) && (G<165) && (B>120) && (B<130))  // Green
    {
       Serial.println("Color is green");
       color = 6;  
  }
  return color;  
}
