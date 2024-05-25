#include <Arduino.h>

const int trigPin = 12; // Trig pin
const int echoPin = 11; // Echo pin

//defining pins and variables
#define left 4
#define right 5

#define motor_left 6
#define motor_right 7

#define buzzer 8

void setup() {
  //declaring pin types
  pinMode(left,INPUT);
  pinMode(right,INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(motor_left, OUTPUT);
  pinMode(motor_right, OUTPUT);
  //begin serial communication
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT); // Set Trig pin as OUTPUT
  pinMode(echoPin, INPUT); // Set Echo pin as INPUT
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
}

void loop(){
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

  //printing values of the sensors to the serial monitor
  Serial.println(digitalRead(left));
  
  Serial.println(digitalRead(right));

  if (distance_cm > 10){
    digitalWrite(buzzer, LOW);
  //line detected by both
  if(digitalRead(left)==0 && digitalRead(right)==0){
    //Forward
    digitalWrite(motor_left, HIGH);
    digitalWrite(motor_right, HIGH);
  }
  //line detected by left sensor
  else if(digitalRead(left)==0 && !digitalRead(right)==0){
    //turn left
    digitalWrite(motor_left, HIGH);
    digitalWrite(motor_right, LOW);
  }
  //line detected by right sensor
  else if(!digitalRead(left)==0 && digitalRead(right)==0){
    //turn right
    digitalWrite(motor_left, LOW);
    digitalWrite(motor_right, HIGH);
  }
  //line detected by none
  else if(!digitalRead(left)==0 && !digitalRead(right)==0){
    //stop
    digitalWrite(motor_left, LOW);
    digitalWrite(motor_right, LOW);
    delay(20);
  }  
  }
  else{
    digitalWrite(buzzer, HIGH);
    digitalWrite(motor_left, LOW);
    digitalWrite(motor_right, LOW);
    delay(20);
    Serial.println("stop");
  }
}
