#include <Arduino.h>

const int trigPin = 12; // Trig pin
const int echoPin = 11; // Echo pin

void setup() {
  Serial.begin(9600); // Start serial communication
  pinMode(trigPin, OUTPUT); // Set Trig pin as OUTPUT
  pinMode(echoPin, INPUT); // Set Echo pin as INPUT
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
}

void loop() {
  // Trigger the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the duration of the pulse from the echo pin
  long duration = pulseIn(echoPin, HIGH);

  // Calculate distance in centimeters
  float distance_cm = duration * 0.0343 / 2;

  // Print the distance to the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");

  delay(500); // Delay for a second before the next measurement
}