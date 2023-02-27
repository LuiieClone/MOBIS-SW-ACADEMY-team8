#include "mydotmatrix.h"

byte heart[8] =
{
  B01100110,
  B11111111,
  B11111111,
  B11111111,
  B01111110,
  B00111100,
  B00011000,
  B00000000
};

byte straight[8] =
{
  B00011000,
  B00111100,
  B01111110,
  B11111111,
  B00011000,
  B00011000,
  B00011000,
  B00011000
};

byte right_turn[8] =
{
  B00001000,
  B00001100,
  B00001110,
  B01111111,
  B11111111,
  B11001110,
  B11001100,
  B11001000
};

byte left_turn[8] =
{
  B00010000,
  B00110000,
  B01110000,
  B11111110,
  B11111111,
  B01110011,
  B00110011,
  B00010011
};

byte stop[8] =
{
  B10000001,
  B01000010,
  B00100100,
  B00011000,
  B00011000,
  B00100100,
  B01000010,
  B10000001
};

byte alph_D[8] =
{
  B00000000,
  B01111000,
  B01000100,
  B01000010,
  B01000010,
  B01000100,
  B01111000,
  B00000000
};

byte alph_A[8] =
{
  B00000000,
  B00011000,
  B00011000,
  B00100100,
  B00111100,
  B01100110,
  B01000010,
  B00000000
};

byte alph_N[8] =
{
  B00000000,
  B01000010,
  B01100010,
  B01010010,
  B01001010,
  B01000110,
  B01000010,
  B00000000
};

byte alph_G[8] =
{
  B00000000,
  B00111100,
  B01100110,
  B01000000,
  B01001110,
  B01100100,
  B00111100,
  B00000000
};

byte alph_E[8] =
{
  B00000000,
  B01111110,
  B01000000,
  B01111110,
  B01000000,
  B01000000,
  B01111110,
  B00000000,
};

byte alph_R[8] =
{
  B00000000,
  B01111000,
  B01000100,
  B01000100,
  B01111000,
  B01000100,
  B01000010,
  B00000000
};

byte stop_mark[8] =
{
  B00111000,
  B01000010,
  B10100001,
  B10010001,
  B10001001,
  B10000101,
  B01000010,
  B00000000
};

byte ex_mark[8] =
{
  B00000000,
  B00100000,
  B00100000,
  B00100000,
  B00100000,
  B00000000,
  B00100000,
  B00000000
};

MyDotmatrixControl::MyDotmatrixControl(int dataPin, int clkPin, int csPin, int numDevices) {
    SPI_MOSI=dataPin;
    SPI_CLK=clkPin;
    SPI_CS=csPin;
    if(numDevices<=0 || numDevices>8 )
        numDevices=8;
    pinMode(SPI_MOSI,OUTPUT);
    pinMode(SPI_CLK,OUTPUT);
    pinMode(SPI_CS,OUTPUT);
    digitalWrite(SPI_CS,HIGH);
    SPI_MOSI=dataPin;
    for(int i=0;i<64;i++) {
      status[i]=0x00;
    }
    spiTransfer(15,0);
    spiTransfer(9,0);
    clearDisplay();
    shutdown(true);
}

void MyDotmatrixControl::shutdown(bool b) {
    if(b)
        spiTransfer(12,0);
    else
        spiTransfer(12,1);
}

void MyDotmatrixControl::setIntensity(int intensity) {
    if(intensity>=0 && intensity<16)	
        spiTransfer(10,intensity);
}

void MyDotmatrixControl::setRow(int row, byte value) {
    if(row<0 || row>7)
        return;
    status[row]=value;
    spiTransfer(row+1,status[row]);
}

void MyDotmatrixControl::clearDisplay() {
    for(int i=0;i<8;i++) {
        status[i]=0;
        spiTransfer(i+1,status[i]);
    }
}

void MyDotmatrixControl::spiTransfer(volatile byte opcode, volatile byte data) {
    spidata[1]=opcode;
    spidata[0]=data;
    digitalWrite(SPI_CS,LOW);
    for(int i=2;i>0;i--) {
        shiftOut(SPI_MOSI,SPI_CLK,MSBFIRST,spidata[i-1]);
    }
    digitalWrite(SPI_CS,HIGH);
}


//dotmatrix

void MyDotmatrixControl::dotmatrix_init() {
  shutdown(false);
  setIntensity(5);
  clearDisplay();
}
bool MyDotmatrixControl::danger_flow(int sensor, int mode, byte* arr1, byte* arr2 = NULL) {
  if(mode == 0) {
    for(int d = 0; d < 8; d++) {    
      for (int i = 0; i < 8; i++) {
        setRow(i, arr1[i]>>(8-d));
      }
      delay(DELAY_TIME);
      if(digitalRead(sensor) == 1) {
        return false;
      }
    }
  }
  else if (mode == 1){
    for(int d = 0; d<8; d++) {    
      for (int i = 0; i < 8; i++) {
        setRow(i, arr1[i]<<d | arr2[i]>>(8-d));
      }
      delay(DELAY_TIME);
      if(digitalRead(sensor) == 1) {
        return false;
      }
    }
  }
  else {
    for(int d = 0; d<8; d++) {    
      for (int i = 0; i < 8; i++) {
        setRow(i, arr1[i]<<d);
      }
      delay(DELAY_TIME);
      if(digitalRead(sensor) == 1) {
        return false;
      }
    }
  }
}

bool MyDotmatrixControl::display_danger(int sensor) {
  if(danger_flow(sensor, 0, alph_D)==false) return false;
  if(danger_flow(sensor, 1, alph_D, alph_A)==false) return false;
  if(danger_flow(sensor, 1, alph_A, alph_N)==false) return false;
  if(danger_flow(sensor, 1, alph_N, alph_G)==false) return false;
  if(danger_flow(sensor, 1, alph_G, alph_E)==false) return false;
  if(danger_flow(sensor, 1, alph_E, alph_R)==false) return false;
  if(danger_flow(sensor, 1, alph_R, ex_mark)==false) return false;
  if(danger_flow(sensor, 2, ex_mark)==false) return false;
  return true;
}

void MyDotmatrixControl::display_direction(int dir) {
  if(dir == 0) {
    for (int i = 0; i < 8; i++) {
      setRow(i, straight[i]);
    }
  }
  else if(dir == 1) {
    for (int i = 0; i < 8; i++) {
      setRow(i, right_turn[i]);
    }
  }
  else if(dir == 2) {
    for (int i = 0; i < 8; i++) {
      setRow(i, left_turn[i]);
    }
  }
}

void MyDotmatrixControl::display_stop() {
  for (int i = 0; i < 8; i++) {
    setRow(i, stop[i]);
  }  
}