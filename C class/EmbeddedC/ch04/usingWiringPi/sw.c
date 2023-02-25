#include <stdio.h>
#include <wiringPi.h>

#define SW 23

int main()
{
    wiringPiSetupGpio();        //BCM Pin no 이용
    pinMode(SW, INPUT);

    while(1)
    {
        if(digitalRead(SW)==1)
            printf("Sw Pressed\n");
        delay(200);
    }

    return 0;
}
