#include <Arduino.h>
int red = 5;

int green = 9;

int blue = 12;

String Colour;

String msg = "Enter LED Colour ";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(red, OUTPUT);

  pinMode(green, OUTPUT);

  pinMode(blue, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(msg);
  
  while(Serial.available() == 0)
  {  
  }

  Colour = Serial.readString();
  
  if(Colour == "red")
  {
    digitalWrite(red, HIGH);
    digitalWrite(green, LOW);
    digitalWrite(blue, LOW);
  }
  else if(Colour == "green")
  {
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH);
    digitalWrite(blue, LOW);
  }
  else if(Colour == "blue")
  {
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    digitalWrite(blue, HIGH);
  }
  
}