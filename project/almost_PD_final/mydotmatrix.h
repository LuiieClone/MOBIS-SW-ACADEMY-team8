#ifndef _MYDOTMATRIX_H_
#define _MYDOTMATRIX_H_

#include <Arduino.h>
#define DELAY_TIME 65

//#include <avr/pgmspace.h>

extern byte heart[8];
extern byte straight[8];
extern byte right_turn[8];
extern byte left_turn[8];
extern byte stop[8];
extern byte alph_D[8];
extern byte alph_A[8];
extern byte alph_N[8];
extern byte alph_G[8];
extern byte alph_E[8];
extern byte alph_R[8];
extern byte stop_mark[8];
extern byte ex_mark[8];

class MyDotmatrixControl {
  private :
    byte spidata[16];
    void spiTransfer(volatile byte opcode, volatile byte data);
    void shiftOut(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder, uint8_t val) {
      uint8_t i;

      for (i = 0; i < 8; i++) {
        if (bitOrder == LSBFIRST) {
          digitalWrite(dataPin, val & 1);
          val >>= 1;
        }
        else {
          digitalWrite(dataPin, (val & 128) != 0);
          val <<= 1;
          }
        digitalWrite(clockPin, HIGH);
        digitalWrite(clockPin, LOW);
      }
    }
    byte status[64];
    int SPI_MOSI;
    int SPI_CLK;
    int SPI_CS;
  public:
    MyDotmatrixControl(int dataPin, int clkPin, int csPin, int numDevices=1);
    void shutdown(bool status);
    void setIntensity(int intensity);
    void setRow(int row, byte value);
    void clearDisplay();

    void dotmatrix_init();
    bool danger_flow(int sensor, int mode, byte* arr1, byte* arr2 = NULL);
    bool display_danger(int sensor);
    void display_direction(int dir);
    void display_stop();
};

#endif	//mydotmatrix.h