#include "Arduino.h"
#include "infraRed.h"

infraRed::infraRed()
{
	Sensor = 18;
  pinMode(Sensor, INPUT);
}
infraRed::infraRed(int pin)
{
	Sensor = pin;
  pinMode(Sensor, INPUT);
}

void infraRed::waiting()
{
	while(true)
	{
			object = digitalRead(Sensor);
			if (object == HIGH) { // 장애물 감지가 안되면
			Serial.println("No detect");
			break;
			} else {
			Serial.println("Detect");
		}
	}
}

bool infraRed::readUR()
{
	object = digitalRead(Sensor);  // 센서값 읽어옴
	if (object == NOT_EXIST) { // 장애물 감지가 안되면
    	    Serial.println("No detect");
  	} else {
    	    Serial.println("Detect");                 // 장애물이 감지되면
    	    waiting();
    	    Serial.println("Object Removed");
  	}
	return true;
}
