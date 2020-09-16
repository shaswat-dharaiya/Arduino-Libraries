# Motion

## Table of contents
* [General info](#general-info)
* [Technology](#technology)
* [Features](#features)
* [To-Do](#to-Do)
* [Initialization](#initialization)
* [Functions](#functions)

## General info
This Library provides additional functionality for 2D Motion with motor module for Arduino programs.

## Technology
Librariess are created with:
* C/C++

## Features
* This library allows you to directly give directional commands to your motor module on your Arduino.

## To-Do
* Move forward
* Move reverse
* Move left
* Move right
* Stay/Stop Motion.

## Initialization
* Include the library at beginning of the code.
```
#include "Motion.h";
```
* Declare the digital pins & pwm pins.
```
//Before setup()
//Change the pin number as per your use.
//Use Digital pins
int motxf = 22;
int motyf = 26;
int motxr = 24;
int motyr = 28;
//Use PWM pins only
int motx = 2;   
int moty = 3;
```
* Create an object of the Motion.
```
Motion motion(motx,moty,motxf,motyf,motxr,motyr);
```

## Functions
* Inside setup()<br>
1. setupMotion: <b>Setup for Motion.</b>
```
motion.setupMotion();
```
* Inside loop()<br>
Each directional function takes a Boolean value as argument, which allows printing current motion.<br>
1. forward(boolean prnt): <b>Moves forward. </b>
```
motion.forward(true);
```
2. reverse(boolean prnt): <b>Moves reverse. </b>
```
motion.reverse(false);
```
3. forward(boolean prnt): <b>Moves forward. </b>
```
motion.right(true);
```
4. left(boolean prnt): <b>Moves left. </b>
```
motion.left(false);
```
5. stay(boolean prnt): <b>Stay/Stops motion. </b>
```
motion.stay(true);
```
