#include <NewPing.h>

#define TRIGGER_PIN  12
#define ECHO_PIN 11
#define MAX_DISTANCE 200

#define MAX_SPEED 200

const int ENa = 5;
const int ENb = 3;
const int LF = 2;
const int LB = 4;
const int RF = 7;
const int RB = 6;

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

boolean forward_movement = false;

void setup() {
  Serial.begin(9600);
  pinMode(LF, OUTPUT);
  pinMode(LB, OUTPUT);
  pinMode(RF, OUTPUT);
  pinMode(RB, OUTPUT);
  pinMode(ENa, OUTPUT);
  pinMode(ENb, OUTPUT);

}

void loop() {

  
  move_forward();
  
}

void move_forward(){
  if(!forward_movement){
    
    forward_movement = true;
    analogWrite(ENa, 200);
    analogWrite(ENb, 200);
    digitalWrite(LF, HIGH);
    digitalWrite(LB, LOW);
    digitalWrite(RF, HIGH);
    digitalWrite(RB, LOW);
  }
}

void move_backward(){
  forward_movement = false;

  digitalWrite(LF, LOW);
  digitalWrite(LB, HIGH);
  digitalWrite(RF, LOW);
  digitalWrite(RB, HIGH);
  
}


void halt(){

  forward_movement = false;
  analogWrite(ENa, 0);
  analogWrite(ENb, 0);
  digitalWrite(LF, LOW);
  digitalWrite(LB, LOW);
  digitalWrite(RF, LOW);
  digitalWrite(RB, LOW);
}


void turn_left(){
  digitalWrite(LF, HIGH);
  digitalWrite(LB, LOW);
  digitalWrite(RF, LOW);
  digitalWrite(RB, HIGH);

  delay(500);

  digitalWrite(LF, HIGH);
  digitalWrite(LB, LOW);
  digitalWrite(RF, LOW);
  digitalWrite(RB, HIGH);
}

void turn_right(){
  digitalWrite(LF, LOW);
  digitalWrite(LB, HIGH);
  digitalWrite(RF, HIGH);
  digitalWrite(RB, LOW);

  delay(500);

  digitalWrite(LF, LOW);
  digitalWrite(LB, HIGH);
  digitalWrite(RF, HIGH);
  digitalWrite(RB, LOW);
}
