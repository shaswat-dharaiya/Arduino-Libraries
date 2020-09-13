/*
MPU.h - Library for 2D Motion in a motor module.
Created by Shaswat Dharaiya, 5 June 2017.
*/
#ifndef Motion_h
#define Motion_h

#include "Arduino.h"

class Motion
{
  public:
    Motion(int x, int y, int xf, int xr, int yf, int yr);
    void setupMotion();
    void stay(boolean prt);
    void forward(boolean prt);
    void reverse(boolean prt);
    void right(boolean prt);
    void left(boolean prt);
  private:
    int x1, y1, xf1, xr1, yf1, yr1;
};
#endif
