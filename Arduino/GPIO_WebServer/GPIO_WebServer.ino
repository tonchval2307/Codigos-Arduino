#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include "index.h"

#define LED 0

const char *ssid = "MikyWifi";
const char *password = "@Miky123";

ESP8266WebServer server(80);

void setup() {
  // put your setup code here, to run once:
  delay(1000);
  Serial.begin(9600);
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid,password);
  pinMode(LED,OUTPUT);
  digitalWrite(LED,HIGH);
  Serial.println("");
  Serial.print("Connected to");
  Serial.print("IP Address: ");
  Serial.println(WiFi.softAPIP());
  server.on("/",handleRoot);
  server.on("/ledOn", handleLEDon);
  server.on("/ledOff", handleLEDoff);
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  // put your main code here, to run repeatedly:
  server.handleClient();

}

void handleRoot(void)
{
  Serial.println("You Called root page");
  String s = MAIN_page;
  server.send(200,"text/html",s);
}

void handleLEDon(void)
{
  Serial.println("LED OFF Page");
  digitalWrite(LED,LOW);
  server.send(200,"text/html","LED is ON");
}

void handleLEDoff(void) 
{ 
 Serial.println("LED off page");
 digitalWrite(LED,HIGH); //LED off
 server.send(200, "text/html", "LED is OFF");
}
