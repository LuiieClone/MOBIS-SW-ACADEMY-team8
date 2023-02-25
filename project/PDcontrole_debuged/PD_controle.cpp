#include <Arduino.h>
#include <AFMotor.h>
#include "PD_controle.h"

// PD 제어
int pdControl(int speed_L, int speed_R){ //error:
  static float prevError = 0;
  float error = speed_R-speed_L;
  float correction = KD * (error - prevError);
  prevError = error;
  
  return (int)(KP*error - correction);
};

void setSpeeds(int LT_left, AF_DCMotor& motor_L, AF_DCMotor& motor_R, int speed_L, int speed_R){
  //속도 줄어든다
  int pd = pdControl(speed_L, speed_R);
  /*  우회전  */
  if (LT_left == WHITE)
  {
    motor_L.setSpeed(CORNER_SPEED - pd);
    motor_R.setSpeed(BACK_SPEED + pd);
  }
  /*  좌회전  */
  else if (LT_left == BLACK)
  {
    motor_L.setSpeed(BACK_SPEED + pd);
    motor_R.setSpeed(CORNER_SPEED - pd);
  }
  
  delay(CORRECTION_INTERVAL);
};