/*
SplitString.h - Library for String Manipulation.
Created by Shaswat Dharaiya, 2 Aug 2020.
*/
#ifndef SplitString_h
#define SplitString_h

#include "Arduino.h"

class SplitString
{
  public:
    SplitString();
    String stringToBeSplit(String input_string, char delimeter, int pos);
    int totalInstances(String input_string, char delimeter);
    void makeStringArray(String input_string, String toArray[],char delimeter);
};
#endif
