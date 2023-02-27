#include "Arduino.h"
#include "mymotor.h"

static uint8_t Serial_data = 0x00;  //  use 7 ~ 0 bit for serial data input to 74HCT595

//  pin설정 및 초기화
void MotorController::enable() {

  pinMode(MOTORLATCH, OUTPUT);
  pinMode(MOTORENABLE, OUTPUT);
  pinMode(MOTORDATA, OUTPUT);
  pinMode(MOTORCLK, OUTPUT);

  Serial_data = 0x00;

  input_Serial();  // reset

  digitalWrite(MOTORENABLE, LOW); //  output enable
}


//  input_Serial을 L293D 입력핀에 전달
void MotorController::input_Serial() {

  digitalWrite(MOTORLATCH, LOW);
  digitalWrite(MOTORDATA, LOW);

  //  Store Serial_data in stroage register
  for (int i=0; i<8; i++) {
    
    digitalWrite(MOTORCLK, LOW);

    if (Serial_data & _BV(7-i))
      digitalWrite(MOTORDATA, HIGH);
    else
      digitalWrite(MOTORDATA, LOW);

    digitalWrite(MOTORCLK, HIGH); //  logic high level shifted into shift register stage 0
  }
  digitalWrite(MOTORLATCH, HIGH); //  shift register의 데이터를 storage register에 보내고 parallel output 출력

}

static MotorController MotorControl;


// TCCR : Timer/Counter Control Register
// 타이머 모드 설정, 출력 핀 동작 설정

/*
TCCR2A[7:0] = {COM2A1, COM2A0, COM2B1, COM2B0, -, -, WGM21, WGM20}
address : 0xB0

TCCR2B[7:0] = {FOC2A, FOC2B, -, -,  WGM22,  CS22, CS21, CS20}
address : 0xB1


CS22, CS21, CS20 :
- 타이머의 동작에 필요한 클럭 주파수를 결정
0 0 0 No clock source (Timer/Counter stopped).
0 0 1 clkT2S/         (No prescaling)
0 1 0 clkT2S/8        (From prescaler)
0 1 1 clkT2S/32       (From prescaler)
1 0 0 clkT2S/64       (From prescaler)
1 0 1 clkT2S/128      (From prescaler)
1 1 0 clkT2S/256      (From prescaler)
1 1 1 clkT2S/1024     (From prescaler)


WGM22, WGM21, WGM20
TOP(카운터의 최대값)으로 어떤 것을 사용할지 등에 관한 동작 모드를 설정

      Mode ofOperation    TOP  Update of OCRx at  TOV Flag Set on
0 0 0 Normal              0xFF Immediate          MAX
0 0 1 PWM, Phase Correct  0xFF TOP                BOTTOM
0 1 0 CTC                 OCRA Immediate          MAX
0 1 1 Fast PWM            0xFF BOTTOM             MAX
1 0 0 Reserved            –    –                  –
1 0 1 PWM, Phase Correct  OCRA TOP                BOTTOM
1 1 0 Reserved            –    –                  –
1 1 1 Fast PWM            OCRA BOTTOM             TOP
*/

inline void initPWM1() {
    // use PWM from timer2A on PB3 (Arduino pin #11)
    pinMode(11, OUTPUT);

    // fast PWM, turn on OCR2A, clk No prescaling
    TCCR2A |= _BV(COM2A1) | _BV(WGM21) | _BV(WGM20);
    TCCR2B  = _BV(CS20);
    OCR2A = 0;
    
}

//  frequency   = 16MHz / 256
//  Duty Cycle  = (s + 1) / 256
inline void setPWM1(uint8_t s) {
    // use PWM from timer2A on PB3 (Arduino pin #11)
    OCR2A = s;
}

inline void initPWM2() {
    // use PWM from timer2B (pin 3)
    pinMode(3, OUTPUT);

    // fast PWM, turn on OCR2B, No prescaling
    TCCR2A |= _BV(COM2B1) | _BV(WGM21) | _BV(WGM20);
    TCCR2B = _BV(CS20);
    OCR2B = 0;
    
}

inline void setPWM2(uint8_t s) {
    // use PWM from timer2B (pin 3)
    OCR2B = s;
}

//  set Motor driver input pin to 0
DCMotor::DCMotor(uint8_t num) {
  motornum = num;
  MotorControl.enable();

  switch (num) {
  case 1:
    Serial_data &= ~_BV(MOTOR1_A) & ~_BV(MOTOR1_B); // set both motor pins to 0
    MotorControl.input_Serial();
    initPWM1();
    break;
  case 2:
    Serial_data &= ~_BV(MOTOR2_A) & ~_BV(MOTOR2_B); // set both motor pins to 0
    MotorControl.input_Serial();
    initPWM2();
    break;
  }
}


//  모터 방향 설정
//  A가 HIGH B가 LOW인  경우 정방향
//  A가 LoW  B가 HIGH인 경우 역방향
//  모두 LOW인 경우 정지
void DCMotor::run(uint8_t cmd) {
  uint8_t a, b;
  switch (motornum) {
  case 1:
    a = MOTOR1_A; b = MOTOR1_B; break;
  case 2:
    a = MOTOR2_A; b = MOTOR2_B; break;
  }
  
  switch (cmd) {
  case FORWARD:
    Serial_data |= _BV(a);
    Serial_data &= ~_BV(b); 
    MotorControl.input_Serial();
    break;
  case BACKWARD:
    Serial_data &= ~_BV(a);
    Serial_data |= _BV(b); 
    MotorControl.input_Serial();
    break;
  case RELEASE:
    Serial_data &= ~_BV(a);
    Serial_data &= ~_BV(b); 
    MotorControl.input_Serial();
    break;
  }
}

// motor 속도 조절
void DCMotor::setSpeed(uint8_t speed) {
  switch (motornum) {
  case 1:
    setPWM1(speed); break;
  case 2:
    setPWM2(speed); break;
  }
}
