#ifndef _MYMOTOR_
#define _MYMOTOR_


//  Bit positions in the 74HCT595 shift register output
                      //  pin in 74HCT595         <-->  pin in L293D
#define MOTOR1_A 2    //  2 Q2 Parallel data out  <-->  2  input 1_A      
#define MOTOR1_B 3    //  3 Q3 Parallel data out  <-->  7  input 1_B 
#define MOTOR2_A 1    //  1 Q1 Parallel data out  <-->  15 input 2_A 
#define MOTOR2_B 4    //  4 Q4 Parallel data out  <-->  10 input 2_B


//  Arduino pin names for interface to 74HCT595 latch
                        //  pin in 74HCT595
#define MOTORLATCH 12   //  12 storage register clock input
#define MOTORCLK 4      //  11 shift register clock input
#define MOTORENABLE 7   //  13 output enable (active LOW)
#define MOTORDATA 8     //  14 serial data input


//  Constants that the user passes in to the motor calls
#define FORWARD 1
#define BACKWARD 2
#define BRAKE 3
#define RELEASE 4


//  access ATmega register 
#define TCCR2A (*(volatile uint8_t *)(0xB0))
#define TCCR2B (*(volatile uint8_t *)(0xB1))
#define OCR2A  (*(volatile uint8_t *)(0xB3))
#define OCR2B  (*(volatile uint8_t *)(0xB4))


//  8비트 unsigned int
typedef unsigned int uint8_t __attribute__((__mode__(__QI__)));

//  control 74HCT595
class MotorController
{
  void enable();
  void input_Serial();
public:
  friend class DCMotor;
};


//  모터 제어
class DCMotor
{
  uint8_t motornum;
public:
  DCMotor(uint8_t motornum);
  void run(uint8_t);
  void setSpeed(uint8_t);
};

#endif