#include <Arduino.h>

void setup(){
  pinMode(A0, INPUT);
  pinMode(13 , OUTPUT);
  Serial.begin(9600);
}

void loop(){
  if(analogRead(A0) > 800)digitalWrite(13, LOW);
  else digitalWrite(13, HIGH);
  delay(1000);
}