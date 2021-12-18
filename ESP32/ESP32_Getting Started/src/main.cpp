#include <Arduino.h>
#include <WiFi.h>
#include <esp_pm.h>
#include <esp_wifi.h>
#include <esp_wifi_types.h>

void setup() {
  // put your setup code here, to run once
  
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);
  esp_wifi_set_ps( WIFI_PS_NONE );
  WiFi.disconnect();
  delay(100);

  Serial.println("Setup Done");
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Scan Start");
  
  int n = WiFi.scanNetworks();

  Serial.println(n);

  Serial.println("Scan Done");

  if (n == 0)
  {
    Serial.println("no networks found");
  }
  else
  {
    Serial.print(n);
    Serial.println(" Networks Found");

    for(int i = 0; i < n; i++)
    {
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.print(WiFi.SSID(i));
      Serial.print(" (");
      Serial.print(WiFi.RSSI(i));
      Serial.print(")");
      Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN)?" ":"*");
      delay(10);
    }
  }
  Serial.println("");

  delay(5000);
}