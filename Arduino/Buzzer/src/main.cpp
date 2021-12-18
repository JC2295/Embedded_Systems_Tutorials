#include <Arduino.h>
int voltage;
int buzzPin = 8;
//int readPin = A0;
String msg = "Input Number: ";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buzzPin, OUTPUT);
  pinMode(A0, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  voltage = analogRead(A0); 

  Serial.println(voltage);

  delay(500);

  if(voltage > 500)
  {
    digitalWrite(buzzPin, HIGH);
  }
  else
  {
    digitalWrite(buzzPin, LOW);
  }
}