#ifndef _ULTRARED_
#define _ULTRARED_

#include "mymotor.h"
#define NOT_EXIST 1
#include "mydotmatrix.h"

class infraRed
{
public:
    int get_object();
    int get_sensor();
    infraRed();
    infraRed(int pin);
    bool readUR(MyDotmatrixControl& dc, DCMotor& L, DCMotor &R);
private:
  int sensor;
  int object;
  void waiting(MyDotmatrixControl& dc);
};

#endif