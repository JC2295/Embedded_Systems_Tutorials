#include <Arduino.h>
int voltageReadingPin = A0;
int voltageReading;
float voltageConverted;
int buzzerPin = 8;
float fDelay;
int iDelay;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(voltageReadingPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  voltageReading = analogRead(voltageReadingPin);

  voltageConverted = (5. / 1023.)*voltageReading;

  fDelay = voltageConverted*1988 + 60;

  iDelay = (int) roundf(fDelay);
  
  digitalWrite(buzzerPin, HIGH);

  delayMicroseconds(iDelay);

  digitalWrite(buzzerPin, LOW);

  Serial.println(iDelay);
}