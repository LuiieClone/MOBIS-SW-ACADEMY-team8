#include "Arduino.h"
#include "infraRed.h"

#include "mydotmatrix.h"

infraRed::infraRed()
{
	sensor = 18;
  pinMode(sensor, INPUT);
}
infraRed::infraRed(int pin)
{
	sensor = pin;
  pinMode(sensor, INPUT);
}

int infraRed::get_object() {
    return this->object;
}

int infraRed::get_sensor() {
    return this->sensor;
}

void infraRed::waiting(MyDotmatrixControl& dc)
{
	while (1) {
    if(dc.display_danger(this->get_sensor()) == false) {
      Serial.println("object removed");
      break;
    }
	}
}

bool infraRed::readUR(MyDotmatrixControl& dc, DCMotor& L, DCMotor &R)
{
	object = digitalRead(sensor);  // 센서값 읽어옴
	if (object == NOT_EXIST) { // 장애물 감지가 안되면
    Serial.println("No detect");
  }
  else {
    Serial.println("Detect");                 // 장애물이 감지되면
    L.run(RELEASE); 
    R.run(RELEASE);
    waiting(dc);
    Serial.println("Object Removed");
  }
	return 1;
}