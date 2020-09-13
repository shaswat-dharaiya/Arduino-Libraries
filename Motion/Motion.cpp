#include "Arduino.h"
#include "Motion.h"

Motion::Motion(int x, int y, int xf, int yf, int xr, int yr)
{
  x1 = x;
  y1 = y;
  xf1 = xf;
  xr1 = xr;
  yf1 = yf;
  yr1 = yr;
}

void Motion::setupMotion()
{
  pinMode(x, OUTPUT);
  pinMode(y, OUTPUT);
  pinMode(xf1, OUTPUT);
  pinMode(yf1, OUTPUT);
  pinMode(xr1, OUTPUT);
  pinMode(yr1, OUTPUT);
}
void Motion::reverse(boolean prnt)
{
    digitalWrite(xf1, HIGH);
    digitalWrite(yf1, HIGH);
    analogWrite(x1, 1023);
    delay(2);
    analogWrite(y1, 1023);
    delay(2);
    digitalWrite(xr1, LOW);
    digitalWrite(yr1, LOW);
    if(prnt)
      Serial.println("Reverse");
}
void Motion::forward(boolean prnt)
{
    digitalWrite(xr1, HIGH);
    digitalWrite(yr1, HIGH);
    analogWrite(y1, 1023);
    delay(2);
    analogWrite(x1, 1023);
    delay(2);
    digitalWrite(xf1, LOW);
    digitalWrite(yf1, LOW);
    if(prnt)
      Serial.println("Reverse");
}
void Motion::right(boolean prnt)
{
    digitalWrite(xf1, LOW);
    digitalWrite(yf1, HIGH);
    analogWrite(x1, 1023);
    delay(2);
    analogWrite(y1, 1023);
    delay(2);
    digitalWrite(xr1, HIGH);
    digitalWrite(yr1, LOW);
    if(prnt)
      Serial.println("Reverse");
}
void Motion::left(boolean prnt)
{
    digitalWrite(xf1, HIGH);
    digitalWrite(yf1, LOW);
    analogWrite(x1, 1023);
    delay(2);
    analogWrite(y1, 1023);
    delay(2);
    digitalWrite(xr1, HIGH);
    digitalWrite(yr1, LOW);
    if(prnt)
      Serial.println("Reverse");
}
void Motion::stay(boolean prnt)
{
    digitalWrite(xf1, LOW);
    digitalWrite(yf1, LOW);
    delay(2);
    analogWrite(y1, 0);
    delay(2);
    digitalWrite(xr1, LOW);
    digitalWrite(yr1, LOW);
    analogWrite(x1, 0);
    if(prnt)
      Serial.println("Reverse");
}
