#include "ultraRed.h"
ultraRed::ultraRed()
{
	Sensor = A4;
	pinMode(Sensor, INPUT); 
}
ultraRed::ultraRed(int pin)
{
	Sensor = pin;
	pinMode(Sensor, INPUT); 
}

void ultraRed::waiting(void)
{
	///dot matrix print here

	while(True)
	{
			object = digitalRead(Sensor);
			if (object == NOT_EXIST) { // 장애물 감지가 안되면
			Serial.println("No detect");
			break;
			} else {
			Serial.println("Detect");
		}
	}
}

bool ultraRed::readUR()
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
