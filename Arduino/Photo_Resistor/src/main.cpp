#include <Arduino.h>
int voltageReadingPin = A0;
int voltageReading;
float convertedVoltageReading;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(voltageReadingPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  voltageReading = analogRead(voltageReadingPin);

  convertedVoltageReading = (5. / 1023.)*voltageReading;

  Serial.println(convertedVoltageReading);

  delay(500);
}