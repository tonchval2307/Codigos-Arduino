#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

const char *ssid = "MikyWifi";
const char *password = "@Miky123";

ESP8266WebServer ssh(80);
void setup() {
  // put your setup code here, to run once:
  delay(1000);
  Serial.begin(115200);
  WiFi.mode(WIFI_AP); 
  Serial.println();
  Serial.print("Configuring access point");
  WiFi.softAP(ssid,password);
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address:");
  Serial.println(myIP);
  ssh.on("/", handleRoot); 
  ssh.begin();
  Serial.println("SHH Server Started");
}

void loop() {
  // put your main code here, to run repeatedly:
  ssh.handleClient();

}

void handleRoot(void)
{
  ssh.send(200, "text/plain", "Hello from ESP8266");
}
