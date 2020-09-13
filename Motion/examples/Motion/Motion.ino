#include "Motion.h";

//Use Digital pins
int motxf = 22;
int motyf = 26;
int motxr = 24;
int motyr = 28;

//Use PWM pins only
int motx = 2;   
int moty = 3;

Motion motion(motx,moty,motxf,motyf,motxr,motyr);


void setup()
{
  Serial.begin(115200);
  motion.setupMotion();
}
void loop()
{
  motion.forward(true);
}
