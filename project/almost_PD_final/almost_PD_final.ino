#include <SoftwareSerial.h>
#include "mymotor.h"
#include "mydotmatrix.h"
#include "infraRed.h"
#include "PD_controle.h"

#define LEFT 1
#define RIGHT 2
#define BLACK 1
#define WHITE 0
#define MAX_SPEED 188
#define MIN_SPEED 1
#define CORNER_SPEED 255
#define BACK_SPEED 130

// 모터드라이버
DCMotor motor_L(LEFT);     //  LEFT  : M1에 연결
DCMotor motor_R(RIGHT);    //  RIGHT : M2에 연결 
infraRed ir(A4);
int speed_L = 0;
int speed_R = 0;

//DIN CLK CS
MyDotmatrixControl dc = MyDotmatrixControl(A1, A3, A2, 1);

void setup() {
  Serial.begin(9600);         // PC와의 시리얼 통신속도

  // turn on motor
  motor_L.setSpeed(MAX_SPEED);    // 왼쪽 모터의 속도   
  motor_L.run(RELEASE);
  motor_R.setSpeed(255);    // 오른쪽 모터의 속도   
  motor_R.run(RELEASE);
  dc.dotmatrix_init();
}

void loop() {
  int LT_left = digitalRead(A0);      //   왼쪽 라인센서1
  int LT_right = digitalRead(A5);     // 오른쪽 라인센서2   

  ir.readUR(dc, motor_L, motor_R);

  if (LT_left == WHITE && LT_right == WHITE) {
    dc.display_direction(0);
    
    motor_L.setSpeed(MAX_SPEED);
    motor_L.run(FORWARD);
    speed_L = MAX_SPEED;

    motor_R.setSpeed(255);
    motor_R.run(FORWARD);
    speed_R = 255;
  }
  else if (LT_left == WHITE && LT_right == BLACK) {
    dc.display_direction(1);

    setSpeeds(LT_left, motor_L, motor_R, speed_L, speed_R);
    motor_L.run(FORWARD);
    motor_R.run(BACKWARD);
  }
  else if (LT_left == BLACK && LT_right == WHITE) {
    dc.display_direction(2);
    setSpeeds(LT_left, motor_L, motor_R, speed_L, speed_R);
    motor_R.run(FORWARD);
    motor_L.run(BACKWARD);   
  }
  else if (LT_left == BLACK && LT_right == BLACK) {
    dc.display_stop();
    motor_L.run(RELEASE); 
    motor_R.run(RELEASE);
  }
}