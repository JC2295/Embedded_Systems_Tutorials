#include <Arduino.h>
#include "WiFi.h"

#define WIFI_NETWORK "AndroidAP6392"
#define WIFI_PASSWORD "726f2b678904"
#define WIFI_TIMEOUT_MS 20000

void connectToWiFi()
{
  Serial.print("Connecting to WiFi");
  WiFi.mode(WIFI_STA);  
  WiFi.begin(WIFI_NETWORK, WIFI_PASSWORD); 

  unsigned long startAttempTime = millis();

  while(WiFi.status() != WL_CONNECTED && millis() - startAttempTime < WIFI_TIMEOUT_MS)
  {
    Serial.print(".");
    delay(100);
  }

  if(WiFi.status() != WL_CONNECTED)
  {
    Serial.println("Connection Failed");
  }
  else
  {
    Serial.println("Connection Successful");
    Serial.println(WiFi.localIP());
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  connectToWiFi();
}