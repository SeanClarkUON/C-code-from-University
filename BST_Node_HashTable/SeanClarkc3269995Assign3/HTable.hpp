/*PROGRAM NAME: HTable.hpp                                                       */
/*PROGRAMMER: Sean Clark c3269995                                              */
/*COURSE: SENG1120 - Data Structures                                           */
/*Includes                                                                     */

#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
using namespace std;

/*Constructor*/
template <typename valueType>
HTable<valueType>::HTable(){
  for (int i = 0; i < 150; i++){
    hashArray[i] = -1;
  }
}/*END: HTable()*/

/*Destruction*/
template <typename valueType>
HTable<valueType>::~HTable(){
  /*Setting all array values to default*/
  for (int i = 0; i < 150; i++){
    hashArray[i] = 0;
  }		
}/*END: ~HTable*/

/*Hash Function*/
template <typename valueType>
valueType HTable<valueType>::hashFunction(valueType value){
  return value%150;
}/*END: hashFunction()*/

/*Add Function*/
template <typename valueType>
void HTable<valueType>::add(const valueType& data){
  valueType value = hashFunction(data);
  hashArray[value] = data;
}/*END: add()*/

/*Remove function*/
template <typename valueType>
void HTable<valueType>::remove(const valueType& data){
  valueType value = hashFunction(data);
  hashArray[value] = -1;
}/*END: remove()*/

/*Search tree function*/
template <typename valueType>
bool HTable<valueType>::search(const valueType& data){
  valueType value = hashFunction(data);
  if (hashArray[value] = data){
    return true;
  }
  else{
    return false;
  }
}/*END: search()*/

/*Function to print tree*/
template <typename valueType>
void HTable<valueType>::printFunction(){
  for (int i = 0; i < 150; i++){
    if (hashArray[i] > 0){
      cout << hashArray[i] << " ";
    }
  }
}/*END: printFunction()*/

/*Overloaded cout overload*/
template <typename valueType>
ostream& operator <<(ostream& out, HTable<valueType>& list){
  list.printFunction();
  return out;
}/*END: cout overload*/
