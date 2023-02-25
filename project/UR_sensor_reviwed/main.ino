int Sensor = A4;    // 센서핀은 A4번에 연결
int object;
#define NOT_EXIST HIGH
void setup () {
  pinMode(Sensor, INPUT);    // 센서값을 입력으로 설정
}

void loop () {
  object = digitalRead(Sensor);  // 센서값 읽어옴
  if (object == NOT_EXIST) { // 장애물 감지가 안되면
    Serial.println("No detect");
  } else {
    Serial.println("Detect");                 // 장애물이 감지되면
    waiting();
    Serial.println("Object Removed");
  }
}

void waiting(void)
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
