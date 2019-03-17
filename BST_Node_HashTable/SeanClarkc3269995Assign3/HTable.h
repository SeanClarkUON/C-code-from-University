/*PROGRAM NAME: HTable.h                                                       */
/*PROGRAMMER: Sean Clark c3269995                                              */
/*COURSE: SENG1120 - Data Structures                                           */

/*Macro Guard                                                                  */
#ifndef SEAN_HTable
#define SEAN_HTable

/*Includes                                                                     */
#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
#include "BTNode.h"
using namespace std;

/*Class Template                                                               */
template <typename valueType>
class HTable{

/*Public Functions                                                             */
public:

  /*Preconditions*/
  /*Array exists to delete*/
  /*Post Conditions*/
  /*Array is set to default value*/
  ~HTable();

  /*Preconditions*/
  /*None*/
  /*Post Conditions*/
  /*Array is set to default values*/
  HTable();

  /*Preconditions*/
  /*Data exists to be added*/
  /*Post Conditions*/
  /*Data is added to array slot*/
  void add(const valueType& data);

  /*Preconditions*/
  /*Data exists to be removed*/
  /*Post Conditions*/
  /*Data is removed from array slot and set to default value*/
  void remove(const valueType& data);

  /*Preconditions*/
  /*Data exists to be searched*/
  /*Post Conditions*/
  /*Returns true is data is there. False if not.*/
  bool search(const valueType& data);

  /*Preconditions*/
  /*None*/
  /*Post Conditions*/
  /*Cout tree in inorder*/
  void printFunction();

/*Private Functions                                                            */
private:

  /*Preconditions*/
  /*None*/
  /*Post Conditions*/
  /*Returns hash value to be added to array*/
  valueType hashFunction(valueType value);

  /*Preconditions*/
  /*None*/
  /*Post Conditions*/
  /*Array created with 150 locations*/
  valueType hashArray[150];

};
/*<< cout overload*/
template<typename valueType>
ostream& operator <<(ostream& out, HTable<valueType>& list);

/*Template Include                                                             */
#include "HTable.hpp"

#endif
/*End Class: */
