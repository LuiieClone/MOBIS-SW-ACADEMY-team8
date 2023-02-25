#include <stdio.h>
#include <wiringPi.h>

#define LED 18

int main()
{
    wiringPiSetupGpio();        //BCM Pin no 이용
    pinMode(LED, OUTPUT);
    for(;;)
    {
        digitalWrite(LED, 1);
        delay(200);
        digitalWrite(LED, 0);
        delay(200);
    }
    return 0;
}