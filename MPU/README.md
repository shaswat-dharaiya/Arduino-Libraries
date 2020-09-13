# MPU

## Table of contents
* [General info](#general-info)
* [Technology](#technology)
* [Features](#features)
* [Initialization](#initialization)
* [To-Do](#to-Do)
* [Functions](#functions)

## General info
This Library provides additional functionality for MPU6050 IMU for Arduino programs.

## Technology
Project is created with:
* Arduino
* MPU6050

## Features
* Communicate with Accelerometer & Gyroscope on MPU6050.

## To-Do
* Read from Accelerometer.
* Read from Gyroscope.

## Initialization
* Include the library at beginning of the code.
```
#include "Wire.h";    //Communicates with MPU6050 over I2C.
#include "MPU.h";
```
```
//Before setup()
//Create two float arrays in order to store data
float accel[3];
float gyro[3];
```
* Create an object of the MPU.
```
MPU mpuAccel(true);   //true wil activate Accelerometer.
MPU mpuGyro(false);   //false will activate Gyroscope.
```

## Functions
* Inside setup()<br>
1. startMPU: <b>Setup for MPU6050.</b>
```
Wire.begin();
mpuAccel.startMPU();
mpuGyro.startMPU();  
```
* Inside loop()  
1. startReadMPU: <b>Starts to read from the MPU6050.</b>
```
mpuAccel.startReadMPU();
mpuGyro.startReadMPU();
```
2. readMPU: <b>Reads the values from MPU6050 and stores it in float array.</b>
```
mpuAccel.readMPU(accel);
mpuGyro.readMPU(gyro);
  ```
