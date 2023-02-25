#ifndef _ULTRARED_
#define _ULTRARED_

#define NOT_EXIST 1

class infraRed
{
public:
    int object;
    infraRed();
    infraRed(int pin);
private:
    int Sensor;
    
    void waiting(AF_DCMotor& motor_L, AF_DCMotor& motor_R);
    bool readUR();
};

#endif
