#include <Arduino.h>

int bp = 8;
int dt1 = 1;
int dt2 = 10;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(bp, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(bp, HIGH);
  delayMicroseconds(dt2);
  digitalWrite(bp, LOW);
  delayMicroseconds(dt2);
}