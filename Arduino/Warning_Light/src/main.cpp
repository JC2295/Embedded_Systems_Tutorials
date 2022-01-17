#include <Arduino.h>
int red = 7;
int green = 8;
int voltagePin = A0;
int voltage;
float convertedVoltage;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(voltagePin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  voltage = analogRead(voltagePin);

  convertedVoltage = (5./1023.)*voltage;

  if(convertedVoltage > 0.4)
  {
    digitalWrite(green, HIGH);
    digitalWrite(red, LOW);
  }
  else
  {
    digitalWrite(green, LOW);
    digitalWrite(red, HIGH);
  }

  Serial.println(convertedVoltage);

  delay(500);
}