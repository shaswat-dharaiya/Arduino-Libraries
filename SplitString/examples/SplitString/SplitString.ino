/* This is Library file for spliting strings.
 * fun_stringToBeSplit takes arguments: 
 * String <that is to be split>,char <delimiter>, int <index at which must be spliting>
 * it returns a segmant of the String 
 * 
 * fun_totalInstances takes arguments: 
 * String <that is to be split>,char <delimiter>
 * it returns count of times the delimiter exists in the String.
 * 
 * fun_makeStringArray takes arguments: 
 * String <that is to be split>,String array <Array to your empty array>,char <delimiter>
 * it conventionally returns a void but converts String to String array.
 */
 
#include "SplitString.h"

SplitString splitString;

void setup() {
   
  Serial.begin(9600);
  String data_single_deli = "A1:B1";
  String data_multi_deli = "A1:B1;C1:D1;A2:B2;C2:D2;A3:B3;C3:D3;A4:B4;C4:D4";

  /*
   * This part of the code shows how to Split String 
   * if you are using single delimiter.
   */
  char deli = ':';
  String str_single = "";
  String str_single_array[splitString.totalInstances(data_single_deli,deli)];
  
  splitString.makeStringArray(data_single_deli,str_single_array,deli);  
  
    for(int j=0; j<splitString.totalInstances(data_single_deli,deli); j++){
      str_single += splitString.stringToBeSplit(data_single_deli,deli,j)+"\t";
    }
  
    for(int j=0; j<splitString.totalInstances(data_single_deli,deli); j++){
      str_single_array[j] = splitString.stringToBeSplit(data_single_deli,deli,j); 
  } 
  Serial.println("Single delimiter Array:");
  for(int i=0; i<sizeof(str_single_array) / sizeof(String); i++){
    Serial.println(str_single_array[i]);
  }
  Serial.println("\nSingle delimiter String: "+str_single);
  
  /*
   * This part of the code shows how to Split String 
   * if you are using multiple delimiters.
   */
   
  char deli1 = ':';
  char deli2 = ';';
  String str = "";
  String str_new[splitString.totalInstances(data_single_deli,deli1)];
  
  int len = splitString.totalInstances(data_multi_deli,deli2)*(splitString.totalInstances(splitString.stringToBeSplit(data_multi_deli,deli2,0),deli1));
  String str_new2[len];
  
  splitString.makeStringArray(data_single_deli,str_new,deli1);  
  
  for(int i=0; i<splitString.totalInstances(data_multi_deli,deli2); i++){
    String new_string = splitString.stringToBeSplit(data_multi_deli,deli2,i);
    for(int j=0; j<splitString.totalInstances(new_string,deli1); j++){
      str += splitString.stringToBeSplit(new_string,deli1,j)+"\t";
    }
    str += "\n";
  } 
  
  for(int i=0; i<splitString.totalInstances(data_multi_deli,deli2); i++){
    String new_string = splitString.stringToBeSplit(data_multi_deli,deli2,i);
    for(int j=0; j<splitString.totalInstances(new_string,deli1); j++){
      str_new2[2*i+j] = splitString.stringToBeSplit(new_string,deli1,j);
    }
  } 
  Serial.println("Multi delimiter Array: ");  
  for(int i=0; i<sizeof(str_new2) / sizeof(String); i++){
    Serial.println(str_new2[i]);
  }
  Serial.println("\nMulti delimiter String: \n"+str);
}

void loop() {
  // put your main code here, to run repeatedly:

}
