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
    
    void waiting();
    bool readUR();
};

#endif
