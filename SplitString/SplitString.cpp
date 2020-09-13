#include "Arduino.h"
#include "SplitString.h"

SplitString::SplitString(){}

String SplitString::stringToBeSplit(String input_string, char delimeter, int pos){
  String show = "";

  int ind = 0;
  int count = 0;
  int new_ind;  
  while(ind<input_string.lastIndexOf(delimeter)){
    new_ind = input_string.indexOf(delimeter,ind);
    show = input_string.substring(ind,new_ind);
    ind = new_ind+1;    
    if(count==pos){
      return show;
      }
    count++;    
  }
  new_ind = input_string.indexOf(delimeter,ind);
  if(new_ind == -1){    
    return input_string.substring(ind,new_ind);
  }
}

int SplitString::totalInstances(String input_string, char delimeter){
  int ind = 0;
  int count = 0;
  int new_ind;
  while(ind<input_string.lastIndexOf(delimeter)){
    new_ind = input_string.indexOf(delimeter,ind+1);    
    ind = new_ind+1;    
    count++;
  }
  new_ind = input_string.indexOf(delimeter,ind);
  if(new_ind == -1){    
    count++;
    }  
  return count;
}

void SplitString::makeStringArray(String input_string, String toArray[],char delimeter){
  int ind = 0;
  int count = 0;
  int new_ind;
  while(ind<input_string.lastIndexOf(delimeter)){
    new_ind = input_string.indexOf(delimeter,ind);
    toArray[count] = input_string.substring(ind,new_ind);
    ind = new_ind+1;
    count++;
  }
  new_ind = input_string.indexOf(delimeter,ind);
  if(new_ind == -1){    
    toArray[count] = input_string.substring(ind,new_ind);
    }  
}
