/*PROGRAM NAME: Queue.h                                                        */
/*PROGRAMMER: Sean Clark c3269995                                              */
/*COURSE: SENG1120 - Data Structures                                           */
/*USE: ASSIGNMMENT 2                                                           */

/*Macro Guard                                                                  */
#ifndef SEAN_Q
#define SEAN_Q

/*Includes                                                                     */
#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
#include "LinkedList.h"
#include "Node.h"
using namespace std;

template <typename valueType>
class Queue{

public:

  /*___________________________________________________________________________*/
  /*Constructor                                                                */
  /*___________________________________________________________________________*/

  /*****************************************************************************/
  /*Description                                                                */
  /*Constructors for Queue.h                                                   */
  /*Precondition:                                                              */
  /*None                                                                       */
  /*Postcondition:                                                             */
  /*None                                                                       */
  Queue();

  /*****************************************************************************/
  /*Description                                                                */
  /*Destructor for Queue.h                                                     */
  /*Precondition:                                                              */
  /*None                                                                       */
  /*Postcondition:                                                             */
  /*None                                                                       */
  ~Queue();

  /*****************************************************************************/
  /*Description                                                                */
  /*Enqueue for Queue.h                                                        */
  /*Precondition:                                                              */
  /*Must have data to be entered                                               */
  /*Postcondition:                                                             */
  /*Data added to queue                                                        */
  void enqueue(valueType& entry);

  /*****************************************************************************/
  /*Description                                                                */
  /*Dequeue for Queue.h                                                        */
  /*Precondition:                                                              */
  /*Data must exist for removal                                                */
  /*Postcondition:                                                             */
  /*Data is removed and deleted from node                                      */
  valueType dequeue();

  /*****************************************************************************/
  /*Description                                                                */
  /*Function to test if queue is empty                                         */
  /*Returns true/false                                                         */
  /*Precondition:                                                              */
  /*None                                                                       */
  /*Postcondition:                                                             */
  /*Returns if list is empty or contains atleast one node                      */
  bool isEmpty() const;

  /*****************************************************************************/
  /*Description                                                                */
  /*Returns listLength() function from LinkedList.h                            */
  /*Precondition:                                                              */
  /*None                                                                       */
  /*Postcondition:                                                             */
  /*Return int containing current list length                                  */
  int size() const;

  /*****************************************************************************/
  /*Description                                                                */
  /*Gets data from head node of list                                           */
  /*Precondition:                                                              */
  /*Data must exist to be retrived                                             */
  /*Postcondition:                                                             */
  /*Returns a reference to data contained within node.                         */
  valueType& front();

  /*Functions for Assignment*/

  /*****************************************************************************/
  /*Description                                                                */
  /*Function to get the average of all the scores                              */
  /*Precondition:                                                              */
  /*Data must exist to be retrived                                             */
  /*Postcondition:                                                             */
  /*Returns average of scores                                                  */
  double average();

  /*****************************************************************************/
  /*Description                                                                */
  /*Functions that retrieves minimum score                                     */
  /*Precondition:                                                              */
  /*Data must exist to be retrived                                             */
  /*Postcondition:                                                             */
  /*Returns minimum score                                                      */
  valueType minimum();

  /*****************************************************************************/
  /*Description                                                                */
  /*Functions that retrieves maximum score                                     */
  /*Precondition:                                                              */
  /*Data must exist to be retrived                                             */
  /*Postcondition:                                                             */
  /*Returns maximum score                                                      */
  valueType maximum();

  /*****************************************************************************/
  /*Description                                                                */
  /*Functions that retrieves standard diviation of the scores                  */
  /*Precondition:                                                              */
  /*Data must exist to be retrived                                             */
  /*Postcondition:                                                             */
  /*Returns double containing standard diviation of scores                     */
  double stdeviation();

private:
  LinkedList<valueType> data;
};

#include "Queue.hpp"

#endif
