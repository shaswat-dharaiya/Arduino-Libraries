#include "Arduino.h"
#include "Wire.h"
#include "MPU.h"

long X, Y, Z;
MPU::MPU(bool AorG)
{
  _AorG = AorG;
}

void MPU::startMPU(){
  Wire.beginTransmission(0b1101000);
  Wire.write(0x6B);
  Wire.write(0b00000000);
  Wire.endTransmission();
  Wire.beginTransmission(0b1101000);
  Wire.write(0x1B);
  Wire.write(0x0000000);
  Wire.endTransmission();
  Wire.write(0x1C);
  Wire.write(0b00000000);
  Wire.endTransmission();
}
void MPU::startReadMPU()
{
  Wire.beginTransmission(0b1101000);
  if(_AorG)
    Wire.write(0x3B);
  else
    Wire.write(0x43);
  Wire.endTransmission();
  Wire.requestFrom(0b1101000,6);
  while(Wire.available()<6);
  X = Wire.read()<<8|Wire.read();
  Y = Wire.read()<<8|Wire.read();
  Z = Wire.read()<<8|Wire.read();
}
void MPU::readMPU(float readings[])
{
  float precision;
  if(_AorG)
    precision = 16384.0;
  else
    precision = 131.0;

  readings[0] = X/precision;
  readings[1] = Y/precision;
  readings[2] = Z/precision;
}
