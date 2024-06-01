#include <Arduino.h>
#include <Servo.h>

#define TRIGGER_PIN 2
#define ECHO_PIN    3

float StraightDistance;

float getStraightDistance()
{
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  return pulseIn(ECHO_PIN, HIGH) / 5.8;
}

const int thresholdDistance = 15;

float LeftDistance;
float RightDistance;

Servo scan_Servo;
void Scan()
{
  scan_Servo.write(0);
  delay(50);
  RightDistance = getStraightDistance();

  scan_Servo.write(180);
  delay(50);
  LeftDistance = getStraightDistance();
  scan_Servo.write(90);
}

#define LEFT_FORWARD   4
#define LEFT_BACKWARD  5
#define RIGHT_FORWARD  6
#define RIGHT_BACKWARD 7

void Forward()
{
  digitalWrite(LEFT_FORWARD, HIGH);
  digitalWrite(LEFT_BACKWARD, LOW);
  digitalWrite(RIGHT_FORWARD, HIGH);
  digitalWrite(RIGHT_BACKWARD, LOW);
}

void Backward()
{
  digitalWrite(LEFT_FORWARD, LOW);
  digitalWrite(LEFT_BACKWARD, HIGH);
  digitalWrite(RIGHT_FORWARD, LOW);
  digitalWrite(RIGHT_BACKWARD, HIGH);
}

void Left()
{
  digitalWrite(LEFT_FORWARD, HIGH);
  digitalWrite(LEFT_BACKWARD, LOW);
  digitalWrite(RIGHT_FORWARD, LOW);
  digitalWrite(RIGHT_BACKWARD, HIGH);
}

void Right()
{
  digitalWrite(LEFT_FORWARD, LOW);
  digitalWrite(LEFT_BACKWARD, HIGH);
  digitalWrite(RIGHT_FORWARD, HIGH);
  digitalWrite(RIGHT_BACKWARD, LOW);
}

void Stop()
{
  digitalWrite(LEFT_FORWARD, LOW);
  digitalWrite(LEFT_BACKWARD, LOW);
  digitalWrite(RIGHT_FORWARD, LOW);
  digitalWrite(RIGHT_BACKWARD, LOW);
}

void setup()
{
  Serial.begin(9600);

  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  scan_Servo.attach(9);

  pinMode(LEFT_FORWARD, OUTPUT);
  pinMode(RIGHT_FORWARD, OUTPUT);
  pinMode(LEFT_BACKWARD, OUTPUT);
  pinMode(RIGHT_BACKWARD, OUTPUT);

  scan_Servo.write(90);
  StraightDistance = 0;
  LeftDistance = 0;
  RightDistance = 0;
}

void loop()
{
  StraightDistance = getStraightDistance();
  Serial.print(StraightDistance);
  Serial.println(" cm");

  if(StraightDistance < thresholdDistance){
    Stop();
    Scan();
    if(LeftDistance > RightDistance){
      Left();
      delay(2000);
      Forward();
    }
    else{
      Right();
      delay(2000);
      Forward();
    }
  }
  else{
    Forward();
  }
}