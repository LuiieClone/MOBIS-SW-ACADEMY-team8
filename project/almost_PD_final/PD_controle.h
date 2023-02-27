#ifndef _PDCONTROLE_
#define _PDCONTROLE_

#define BLACK 1
#define WHITE 0

#define CORNER_SPEED 255
#define BACK_SPEED 130

#define KP 0.5
#define KD 0.2
#define CORRECTION_INTERVAL 10

int pdControl();
void setSpeeds(int LT_left, DCMotor& motor_L, DCMotor& motor_R, int speed_L, int speed_R);

#endif
