#include <Arduino.h>
int voltagePin = A2;
int readVal;
float V2;
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  readVal = analogRead(voltagePin);
  V2 = (5. / 1023.)*readVal;
  Serial.println(V2);
  delay(500);
}