#include <SoftwareSerial.h>
#include <AFMotor.h>
#include "Arduino.h"
#include "infraRed.h"

#define LEFT 1
#define RIGHT 2
#define BLACK 1
#define WHITE 0
#define MAX_SPEED 188
#define MIN_SPEED 1
#define CORNER_SPEED 255
#define BACK_SPEED 130

// 모터드라이버
AF_DCMotor motor_L(LEFT);     //  LEFT  : M1에 연결
AF_DCMotor motor_R(RIGHT);    //  RIGHT : M2에 연결 

void setup() {
  Serial.begin(9600);         // PC와의 시리얼 통신속도

  // turn on motor
  motor_L.setSpeed(MAX_SPEED);    // 왼쪽 모터의 속도   
  motor_L.run(RELEASE);
  motor_R.setSpeed(255);    // 오른쪽 모터의 속도   
  motor_R.run(RELEASE);

  ////infraRed
  infraRed ir(A4);
}

void loop() {
  int LT_left = digitalRead(A0);      //   왼쪽 라인센서1
  int LT_right = digitalRead(A5);     // 오른쪽 라인센서2   
  
  /*  직진  */
  if (LT_left == WHITE && LT_right == WHITE) { 
    motor_L.setSpeed(MAX_SPEED);
    motor_L.run(FORWARD); 

    motor_R.setSpeed(255);
    motor_R.run(FORWARD);
  }

  /*  우회전  */
  else if (LT_left == WHITE && LT_right == BLACK) { 
    motor_L.setSpeed(CORNER_SPEED); 
    motor_L.run(FORWARD);

    motor_R.setSpeed(BACK_SPEED);
    motor_R.run(BACKWARD);
  }

  /*  좌회전  */
  else if (LT_left == BLACK && LT_right == WHITE) {
    motor_R.setSpeed(CORNER_SPEED);
    motor_R.run(FORWARD);

    motor_L.setSpeed(BACK_SPEED); 
    motor_L.run(BACKWARD);   
  }

  /*  정지  */
  else if (LT_left == BLACK && LT_right == BLACK) {
    motor_L.run(RELEASE); 
    motor_R.run(RELEASE);
  }
}
