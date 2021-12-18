#include <Arduino.h>

int green = 10;
int yellow = 9;
int red = 8;
float v_r;
float v1 = (1024. / 5.)*1.67;
float v2 = (1024. / 5.)*3.34;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); 
  pinMode(A0, INPUT);
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  v_r = analogRead(A0);

  if(v_r < v1)
  {
    digitalWrite(green, HIGH);
    digitalWrite(yellow, LOW);
    digitalWrite(red, LOW);
  }
  else if(v_r > v1 && v_r < v2)
  {
    digitalWrite(yellow, HIGH);
    digitalWrite(green, LOW);
    digitalWrite(red, LOW);
  }
  else if(v_r > v2)
  {
    digitalWrite(red, HIGH);
    digitalWrite(green, LOW);
    digitalWrite(yellow, LOW);
  }

}