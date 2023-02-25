#include <Arduino.h>
#include <AFMotor.h>
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

void infraRed::waiting(AF_DCMotor& motor_L, AF_DCMotor& motor_R)
{
	motor_L.run(RELEASE); 
    motor_R.run(RELEASE);
	while(true)
	{
		object = digitalRead(Sensor);
		if (object == HIGH) { // 장애물 감지가 안되면
			Serial.println("a Object is Removed");
			motor_L.run(FORWARD); 
    		motor_R.run(FORWARD);
			break;
		} else {
			Serial.println("a Object is Detect");
		}
	}
}

bool infraRed::readUR()
{
	object = digitalRead(Sensor);  // 센서값 읽어옴
	if (object == NOT_EXIST) { // 장애물 감지가 안되면
    	Serial.println("Not detected");

  	} else {
		Serial.println("Detected");                 // 장애물이 감지되면
		waiting(motor_L, motor_R);
  	}
	return true;
}
