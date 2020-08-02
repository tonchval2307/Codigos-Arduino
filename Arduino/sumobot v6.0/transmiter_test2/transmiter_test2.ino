#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

const int CE = 9;
const int CSN = 10;

RF24 radio(CE,CSN);
const byte address[6] = "00001";

void setup() {
  // put your setup code here, to run once:
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop() {
  // put your main code here, to run repeatedly:
  const char text[] = "Hellow World";
  radio.write(&text,sizeof(text));
  delay(1000);
}
