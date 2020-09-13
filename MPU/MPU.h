/*
MPU.h - Library for Reading Accelorometer & Gyroscope readings.
Created by Shaswat Dharaiya, 9 Sept 2018.
*/
#ifndef MPU_h
#define MPU_h

#include "Arduino.h"

class MPU
{
  public:
    MPU(boolean AorG);
    void startMPU();
    void readMPU(float radings[]);
    void startReadMPU();
  private:    
    long X, Y, Z;
    boolean _AorG;
};
#endif
