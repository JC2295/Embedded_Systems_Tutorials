#include <Arduino.h>

int red = 12;
int blue = 4;
int green = 8;

String colour;
String msg = "Enter Colour: ";

void setup() {
  // put your setup code here, to run once:
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(msg);
  
  while(Serial.available() == 0)
  {
  }

  colour = Serial.readString();

  if(colour == "red")
  {
    digitalWrite(red, HIGH);
    digitalWrite(green, LOW);
    digitalWrite(blue, LOW);
  }
  else if(colour == "green")
  {
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH);
    digitalWrite(blue, LOW);
  }
  else if(colour == "blue")
  {
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    digitalWrite(blue, HIGH);
  }
  else if(colour == "aqua")
  {
    digitalWrite(red, LOW);
    analogWrite(green, 255);
    analogWrite(blue, 255);
  }
  else if(colour == "o")
  {
    analogWrite(red, 255);
    analogWrite(green, 255);
    analogWrite(blue, 0);
  }
}