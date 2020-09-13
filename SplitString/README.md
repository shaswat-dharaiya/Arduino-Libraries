# SplitString

## Table of contents
* [General info](#general-info)
* [Technology](#technology)
* [Features](#features)
* [Initialization](#initialization)
* [To-Do](#to-Do)
* [Functions](#functions)

## General info
This library provides additional functionality for String manipulation for Arduino programs.

## Technology
Project is created with:
* Arduino

## Features
* Count the instances of a character/delimiter.
* String split based on <ins>single</ins> or <ins>multiple</ins> character/delimiter(s).
* Create a String array based on character/delimiter.

## To-Do
* Total instances of a character in a String.
* String split containing single character delimiter.
 * Ex : "A1:B1"
* String split containing multiple characters delimiter.
  * Ex : "A1:B1;C1:D1;A2:B2;C2:D2;"
* 1D String Array:
 * single character delimiter
 * multiple character delimiter
* n-D (Multi Dimensional) String Array:
  * multiple character delimiter

## Initialization
* Include the library at beginning of the code.
```
#include "SplitString.h";
```
* Create an object of the SplitString.
```
SplitString splitString;    //Rename the object as you wish.
```

## Functions
* totalInstances: <b>Count total instances of a character in a String.</b>
```
int len = splitString.totalInstances(delimiter_string,delimiter2);
```
* stringToBeSplit: <b>single character</b>
```
String str = splitString.stringToBeSplit(delimiter_string,delimiter,index);
```
* stringToBeSplit: <b>multiple characters</b>
```
for(int i=0; i<splitString.totalInstances(delimiter_string,delimiter1); i++)
{
    String new_string = splitString.stringToBeSplit(data_multi_deli,delimiter2,i);

    for(int j=0; j<splitString.totalInstances(new_string,delimiter1); j++)
    {
      Serial.println(splitString.stringToBeSplit(new_string,delimiter1,j));
    }
  }
```
* makeStringArray: <b>1D String Array with single character</b>
```
String str_array[splitString.totalInstances(delimiter_string,delimiter)];  
splitString.makeStringArray(delimiter_string,str_array,delimiter);  
```
* stringToBeSplit: <b>1D String Array with multiple characters</b>
```
int len1 = splitString.totalInstances(delimiter_string,delimiter2);
int len2 = (splitString.totalInstances(splitString.stringToBeSplit(delimiter_string,delimiter2,0),delimiter1));
int len = len1*len2;
String str_array[len];
```
```
for(int i=0; i<splitString.totalInstances(delimiter_string,delimiter2); i++)
{
  String new_string = splitString.stringToBeSplit(delimiter_string,delimiter2,i);
  for(int j=0; j<splitString.totalInstances(new_string,delimiter1); j++)
  {
    str_array[2*i+j] = splitString.stringToBeSplit(new_string,delimiter1,j);
  }
}
```
