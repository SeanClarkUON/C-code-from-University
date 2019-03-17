/*PROGRAM NAME: LinkedList.h                                                   */
/*PROGRAMMER: Sean Clark c3269995                                              */
/*COURSE: SENG1120 - Data Structures                                           */
/*USE: ASSIGNMMENT 2                                                           */

/*Macro Guard                                                                  */
#ifndef SEAN_LINKEDLIST
#define SEAN_LINKEDLIST

/*Includes                                                                     */
#include <iostream>
#include <cstdlib>
#include <string>
#include "Node.h"

using namespace std;

/*Linked List Class*/
template <typename valueType>
class LinkedList{

public:

  /*___________________________________________________________________________*/
  /*Consructors                                                                */
  /*___________________________________________________________________________*/

  /*****************************************************************************/
  /*Description                                                                */
  /*Constructors for LinkedList.h                                              */
  /*Precondition:                                                              */
  /*None                                                                       */
  /*Postcondition:                                                             */
  /*None                                                                       */
  LinkedList();

  /*****************************************************************************/
  /*Description                                                                */
  /*Constructors for LinkedList.h                                              */
  /*Precondition:                                                              */
  /*None                                                                       */
  /*Postcondition:                                                             */
  /*None                                                                       */
  LinkedList(valueType& data);\

  /*___________________________________________________________________________*/
  /*Destructor                                                                 */
  /*___________________________________________________________________________*/

  ~LinkedList();

  /*___________________________________________________________________________*/
  /*Functions                                                                  */
  /*___________________________________________________________________________*/

  /*****************************************************************************/
  /*Description                                                                */
  /*Function to add nodes to tail                                              */
  /*Precondition:                                                              */
  /*Data has been initilized with setters and retrived with getters            */
  /*Postcondition:                                                             */
  /*A new node is created, data is stored and added to end of Linked List      */
  void addToTail(valueType& data);

  /*****************************************************************************/
  /*Description                                                                */
  /*Removes current selected node from Linked List                             */
  /*Precondition:                                                              */
  /*None                                                                       */
  /*Postcondition:                                                             */
  /*Selected node is removed from Linked list and deleted                      */
  /*If it was the last node in the list, list is deleted                       */
  void removeFromCurrent();

  /*****************************************************************************/
  /*Description                                                                */
  /*Removes head node of linked list                                           */
  /*Precondition:                                                              */
  /*None                                                                       */
  /*Postcondition:                                                             */
  /*Selected node is removed from Linked list and deleted                      */
  /*If it was the last node in the list, list is deleted                       */
  void removeFromHead();

  /*****************************************************************************/
  /*Description                                                                */
  /*Removes tail from linked list                                              */
  /*Precondition:                                                              */
  /*None                                                                       */
  /*Postcondition:                                                             */
  /*Selected node is removed from Linked list and deleted                      */
  /*If it was the last node in the list, list is deleted                       */
  void removeFromTail();

  // void addToCurrent(valueType& newData);  ///likely not used remove before submit

  /*****************************************************************************/
  /*Description                                                                */
  /*Add to head node                                                           */
  /*Precondition:                                                              */
  /*None                                                                       */
  /*Postcondition:                                                             */
  /*Adds node to head of list                                                  */
  void addToHead(valueType& data);
  Node<valueType>* Current();

  /*___________________________________________________________________________*/
  /*Overloaded Operators                                                       */
  //void operator += (LinkedList& secondList);
  /*___________________________________________________________________________*/

  /*****************************************************************************/
  /*Description                                                                */
  /**/
  /*Precondition:                                                              */
  /**/
  /*Postcondition:                                                             */
  /**/
  void operator += (LinkedList& secondList);

  /*___________________________________________________________________________*/
  /*Function used to move around the linked lists and retrive data             */
  /*___________________________________________________________________________*/

  /*****************************************************************************/
  /*Description                                                                */
  /*Functions to navigate linked list                                          */
  /*Precondition:                                                              */
  /*Linked lists exist to navigate                                             */
  /*Postcondition:                                                             */
  /*None                                                                       */
  void foward();
  void back();
  void moveToHead();
  void moveToTail();
  valueType& getCurrentData();
  std::size_t getLength();

/*Private members*/
/*Used to obey encapsulation*/
private:
  /*Head node*/
  Node<valueType>* head;
  /*Tail node*/
  Node<valueType>* tail;
  /*Current node*/
  Node<valueType>* current;
  /*Used to keep track of list length*/
  std::size_t listLength;

};

#include "LinkedList.hpp"


#endif /*END: SEAN_LINKEDLIST*/
