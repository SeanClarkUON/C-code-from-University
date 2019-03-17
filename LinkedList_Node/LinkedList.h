/*PROGRAM NAME: LinkedList.h                                                   */
/*PROGRAMMER: Sean Clark c3269995                                              */
/*COURSE: SENG1120 - Data Structures                                           */
/*USE: ASSIGNMMENT 1                                                           */

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
class LinkedList{

public:

  /*___________________________________________________________________________*/
  /*Type Def                                                                   */
  /*___________________________________________________________________________*/

  /*****************************************************************************/
  /*Description                                                                */
  /*Type def of used cpp file                                                  */
  /*Precondition:                                                              */
  /*.cpp exists to be used                                                     */
  /*Postcondition:                                                             */
  /*None                                                                       */
  typedef Student dataType;

  /*___________________________________________________________________________*/
  /*Consructors                                                                */
  /*___________________________________________________________________________*/

  /*****************************************************************************/
  /*Description                                                                */
  /*Constructors for Linked list                                               */
  /*Precondition:                                                              */
  /*None                                                                       */
  /*Postcondition:                                                             */
  /*None                                                                       */
  LinkedList();

  /*****************************************************************************/
  /*Description                                                                */
  /*Constructors for Linked list                                               */
  /*Precondition:                                                              */
  /*None                                                                       */
  /*Postcondition:                                                             */
  /*None                                                                       */
  LinkedList(dataType& data);\

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
  void addToTail(dataType& data);

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

  /*****************************************************************************/
  /*Description                                                                */
  /*Function that removes nodes from Linked list                               */
  /*If statements to find where the selected node is located                   */
  /*Once located it will remove from current position                          */
  /*Precondition:                                                              */
  /*Nodes exist to remove                                                      */
  /*string is used for argument                                                */
  /*Postcondition:                                                             */
  /*Nodes location is found and node is removed and deleted                    */
  void remove(string const name);
  /*****************************************************************************/

  /*****************************************************************************/
  /*Description                                                                */
  /*Calculate the average of a linked list                                     */
  /*Precondition:                                                              */
  /*Data exists to calculate                                                   */
  /*Postcondition:                                                             */
  /*Returns average                                                            */
  double calcAverage();

  /*****************************************************************************/
  /*Description                                                                */
  /*Counts the number of string arugment in linked list                        */
  /*Precondition:                                                              */
  /*Data exists to count                                                       */
  /*Postcondition:                                                             */
  /*Returns count of the string used                                           */
  int count(string const name);


  // void addToCurrent(dataType& newData);  ///likely not used remove before submit
  // void addToHead(dataType& data); ///likely not used remove before submit
  Node* Current();

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
  dataType& getCurrentData();
  std::size_t getLength();

/*Private members*/
/*Used to obey encapsulation*/
private:
  /*Head node*/
  Node* head;
  /*Tail node*/
  Node* tail;
  /*Current node*/
  Node* current;
  /*Store average of each linked list*/
  // double average;
  // Node* add;
  // node* tempPTR;
  /*Used to keep track of list length*/
  std::size_t listLength;

};

/*Overloaded ostream <<*/
std::ostream& operator <<(std::ostream& out, LinkedList& list);


#endif /*END: SEAN_LINKEDLIST*/
