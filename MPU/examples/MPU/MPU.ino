#include "Wire.h"
#include "MPU.h"

MPU mpuAccel(true);   //true will activate Accelerometer.
MPU mpuGyro(false);   //false will activate Gyroscope.

char axis[] = {'X','Y','Z'};
float accel[3];
float gyro[3];

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpuAccel.startMPU();
  mpuGyro.startMPU();  
}

void loop() {
  mpuAccel.startReadMPU();
  mpuGyro.startReadMPU();
  
  mpuAccel.readMPU(accel);
  mpuGyro.readMPU(gyro);

  Serial.print("Accel: ");
  for(int i=0; i<3; i++){
    Serial.print(axis[i]);
    Serial.print(":");
    Serial.print(accel[i]);
    Serial.print(" ");
  }
  Serial.print("Gyro: ");
  for(int i=0; i<3; i++){
    Serial.print(axis[i]);
    Serial.print(":");
    Serial.print(gyro[i]);
    Serial.print(" ");
  }
  Serial.println();
  delay(10);

}
