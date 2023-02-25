#include <SoftwareSerial.h>
#include <AFMotor.h>
#include <Arduino.h>
#include "PD_controle.h"

#define LEFT 1
#define RIGHT 2

#define BLACK 1
#define WHITE 0

#define MAX_SPEED 188
#define CORNER_SPEED 255
#define BACK_SPEED 130

// 모터드라이버
AF_DCMotor motor_L(LEFT);     //  LEFT  : M1에 연결
AF_DCMotor motor_R(RIGHT);    //  RIGHT : M2에 연결 
int speed_L = 0;
int speed_R = 0;

void setup() {
  Serial.begin(9600);         // PC와의 시리얼 통신속도

  // turn on motor
  motor_L.setSpeed(MAX_SPEED);    // 왼쪽 모터의 속도//강
  motor_L.run(RELEASE);
  motor_R.setSpeed(255);    // 오른쪽 모터의 속도//약
  motor_R.run(RELEASE);
  
}

void loop() {
  int LT_left = digitalRead(A0);      //   왼쪽 라인센서1
  int LT_right = digitalRead(A5);     // 오른쪽 라인센서2   
  
  /*  직진  */
  if (LT_left == WHITE && LT_right == WHITE) { 
    motor_L.setSpeed(MAX_SPEED);
    motor_L.run(FORWARD);
    speed_L = MAX_SPEED;

    motor_R.setSpeed(255);
    motor_R.run(FORWARD);
    speed_R = 255;
  }

  /*  우회전  */
  else if (LT_left == WHITE && LT_right == BLACK) {
    setSpeeds(LT_left, motor_L, motor_R, speed_L, speed_R);
    //속도 줄어든다
    motor_L.run(FORWARD);
    motor_R.run(BACKWARD);
  }

  /*  좌회전  */
  else if (LT_left == BLACK && LT_right == WHITE) {
    setSpeeds(LT_left, motor_L, motor_R, speed_L, speed_R);
    
    motor_L.run(BACKWARD);
    motor_R.run(FORWARD);   
  }

  /*  정지  */
  else if (LT_left == BLACK && LT_right == BLACK) {
    motor_L.run(RELEASE); 
    motor_R.run(RELEASE);
  }
}