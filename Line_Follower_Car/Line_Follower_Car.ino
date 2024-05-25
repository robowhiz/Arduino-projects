#include <Arduino.h>

//defining pins and variables
#define left 4
#define right 5

#define motor_left 6
#define motor_right 7

void setup() {
  //declaring pin types
  pinMode(left,INPUT);
  pinMode(right,INPUT);
  //begin serial communication
  Serial.begin(9600);
}

void loop(){
  //printing values of the sensors to the serial monitor
  Serial.println(digitalRead(left));
  
  Serial.println(digitalRead(right));

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
  }  
}
