#include <Arduino.h>

#define LEFT_FORWARD   2
#define LEFT_PWM       3
#define LEFT_BACKWARD  4
#define RIGHT_FORWARD  5
#define RIGHT_PWM      6
#define RIGHT_BACKWARD 7

#define LEFT_SPEED 150
#define RIGHT_SPEED 150

#define CRUSING_INTERVAL 4000
#define TURNING_INTERVAL 2000

void forward();
void backward();
void left();
void right();

void setup(){
  Serial.begin(115200);
  pinMode(LEFT_FORWARD, OUTPUT);
  pinMode(RIGHT_FORWARD, OUTPUT);
  pinMode(LEFT_BACKWARD, OUTPUT);
  pinMode(RIGHT_BACKWARD, OUTPUT);
  pinMode(LEFT_SPEED, OUTPUT);
  pinMode(RIGHT_SPEED, OUTPUT);

  analogWrite(LEFT_PWM, LEFT_SPEED);
  analogWrite(RIGHT_PWM, RIGHT_SPEED);
}

void loop(){
  forward();
  delay(CRUSING_INTERVAL);
  right();
  delay(TURNING_INTERVAL);
}

void forward(){
  digitalWrite(LEFT_FORWARD, HIGH);
  digitalWrite(LEFT_BACKWARD, LOW);
  digitalWrite(RIGHT_FORWARD, HIGH);
  digitalWrite(RIGHT_BACKWARD, LOW);
}

void backward(){
  digitalWrite(LEFT_FORWARD, LOW);
  digitalWrite(LEFT_BACKWARD, HIGH);
  digitalWrite(RIGHT_FORWARD, LOW);
  digitalWrite(RIGHT_BACKWARD, HIGH);
}

void left(){
  digitalWrite(LEFT_FORWARD, HIGH);
  digitalWrite(LEFT_BACKWARD, LOW);
  digitalWrite(RIGHT_FORWARD, LOW);
  digitalWrite(RIGHT_BACKWARD, HIGH);
}

void right(){
  digitalWrite(LEFT_FORWARD, LOW);
  digitalWrite(LEFT_BACKWARD, HIGH);
  digitalWrite(RIGHT_FORWARD, HIGH);
  digitalWrite(RIGHT_BACKWARD, LOW);
}