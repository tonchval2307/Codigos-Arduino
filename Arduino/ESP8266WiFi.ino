// Import required libraries
#include "ESP8266WiFi.h"
#include <aREST.h>
// The port to listen for incoming TCP connections 
#define LISTEN_PORT           80

// WiFi parameters
const char* ssid = "wifi-name";
const char* password = "wifi-pass";

// Create an instance of the server
WiFiServer server(LISTEN_PORT);

void setup(void)
{  
  // Start Serial
  Serial.begin(115200);
  
  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
 
  // Start the server
  server.begin();
  Serial.println("Server started");
  
  // Print the IP address
  Serial.println(WiFi.localIP());
  
}

void loop() {
  
  // Handle REST calls
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  while(!client.available()){
    delay(1);
  }
  rest.handle(client);
 
}
