/*PROGRAM NAME: Stack.h                                                        */
/*PROGRAMMER: Sean Clark c3269995                                              */
/*COURSE: SENG1120 - Data Structures                                           */
/*USE: ASSIGNMMENT 2                                                           */

/*Macro Guard                                                                  */
#ifndef SEAN_S
#define SEAN_S

/*Includes                                                                     */
#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
#include "LinkedList.h"
#include "Node.h"
using namespace std;

template <typename valueType>
class Stack{

public:

  /*****************************************************************************/
  /*Description                                                                */
  /*Constructor for Stack.h                                                    */
  /*Precondition:                                                              */
  /*None                                                                       */
  /*Postcondition:                                                             */
  /*Items constructed                                                          */
  Stack();

  /*****************************************************************************/
  /*Description                                                                */
  /*Destructor for Stack.h                                                     */
  /*Precondition:                                                              */
  /*None                                                                       */
  /*Postcondition:                                                             */
  /*Nodes deleted                                                              */
  ~Stack();

  /*****************************************************************************/
  /*Description                                                                */
  /*Push function for Stack.h                                                  */
  /*Precondition:                                                              */
  /*None                                                                       */
  /*Postcondition:                                                             */
  /*Data is saved into queue                                                   */
  void push(valueType& entry);

  /*****************************************************************************/
  /*Description                                                                */
  /*pop function for Stack.h                                                   */
  /*Precondition:                                                              */
  /*Data exists to be removed                                                  */
  /*Postcondition:                                                             */
  /*Nodes deleted                                                              */
  valueType pop();

  /*****************************************************************************/
  /*Description                                                                */
  /*Function to get list length                                                */
  /*Calls listLength() from LinkedList.h                                       */
  /*Precondition:                                                              */
  /*None                                                                       */
  /*Postcondition:                                                             */
  /*Returns list length                                                        */
  bool isEmpty() const;

  /*****************************************************************************/
  /*Description                                                                */
  /*Return data from selected node                                             */
  /*Precondition:                                                              */
  /*Data exists to be collected                                                */
  /*Postcondition:                                                             */
  /*Returns reference to data within node                                      */
  valueType& getStackData();

  /*****************************************************************************/
  /*Description                                                                */
  /*Move to head node of linked list                                           */
  /*Precondition:                                                              */
  /*Head node exists to move to                                                */
  /*Postcondition:                                                             */
  /*Retreves data from head node                                               */
  void getStackHead();

  /*****************************************************************************/
  /*Description                                                                */
  /*Ability to move through linked list                                        */
  /*Precondition:                                                              */
  /*None                                                                       */
  /*Postcondition:                                                             */
  /*Moves to next node                                                         */
  void stackFoward();

  /*****************************************************************************/
  /*Description                                                                */
  /*Calls listLength() from LinkedList.h to get count of list                  */
  /*Precondition:                                                              */
  /*None                                                                       */
  /*Postcondition:                                                             */
  /*Return current Linked Lists length                                         */
  int size();
  valueType& top();
private:
  LinkedList<valueType> data;
};

template<typename valueType>
ostream& operator <<(ostream& out, Stack<valueType>& data);
#include "Stack.hpp"

#endif
