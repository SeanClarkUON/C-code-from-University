/*PROGRAM NAME: LinkedList.cpp                                                 */
/*PROGRAMMER: Sean Clark c3269995                                              */
/*COURSE: SENG1120 - Data Structures                                           */
/*USE: ASSIGNMMENT 1                                                           */

#include <iostream>
#include <cstdlib>
#include <string>
#include "LinkedList.h"
using namespace std;


/*Construtors*/
/*Constructs: head, tail, current, listLength*/
LinkedList::LinkedList(){
  head = NULL;
  tail = NULL;
  current = NULL;
  listLength = 0 ;
}/*END: LinkedList()*/

/*Sets up Node*/
/*Creates tail and current for linked lists*/
LinkedList::LinkedList(dataType& data){
  head = new Node(data, NULL, NULL);
  tail = head;
  current = tail;
  listLength = 1;
}/*END: LinkedList()*/

/*Destructor*/
LinkedList::~LinkedList(){
  while (head != NULL){
    removeFromHead();
  }
  current = NULL;
  tail = NULL;
}/*END: ~LinkedList()*/

/*Add to Tail Function*/
void LinkedList::addToTail(dataType& data){

  /*If tail and head are both empty, it will create a new Node*/
  /*Will assign this new Node to both head and tail*/
  if (listLength == 0){
    head = new Node(data, NULL, NULL);
    tail = head;
    current = tail;
    listLength = 1;
  }

  /*Insert new Node to tail*/
  /*Will also initialize the first list made*/
  else{

    /*Creates temp Node on heap to store new data*/
    Node* tailIn = new Node(data, NULL, NULL);
    /*Set the tail to previous*/
    tail -> setNext(tailIn);
    tailIn -> setPrevious(tail);
    /*Sets tail to the new Node*/
    tail = tailIn;
    /*Incease list length reference*/
    listLength++;
    /*Sets the temp Node tailIn to null*/
    tailIn = NULL;
    /*Destructor might go here FIXIN*/
  }
}/*END: addToTail()*/

/*Function to remove node from current location*/
/*Creates temp node to move data around then deletes current after it is left unused*/
void LinkedList::removeFromCurrent(){
    Node* temp;
    temp = current -> getPrevious();
    temp -> setNext(current -> getNext());
    temp = current -> getNext();
    temp -> setPrevious(current -> getPrevious());
    listLength--;
    delete current;
    current = temp;
}

/*Remove from head function*/
void LinkedList::removeFromHead(){

  /*If list is empty do nothing and display error messge*/
  if (listLength == 0){
    // cout << "Linked list is currently empty" << endl;
    return;
  }

  /*If head is last item in the linked list it will delete the linked list*/
  /*Will display message that it has been deleted*/
  else if(listLength == 1){

    delete head;
    head = NULL;
    tail = NULL;
    listLength--;
    // cout << "As this was the last item in the list." << endl;
    // cout << "The list has been deleted and head & tail set to null" << endl;
    return;
  }

  /*Creates temp head. Assigns temp to next, then head to temp*/
  /*Calls destractor on temp, then Nulls to stop memory leak*/
  /*Calls getNext() function from Node.cpp/Node.h*/
  else{
    Node* temp = head;
    head = temp -> getNext();
    delete temp;
    listLength--;
    temp = NULL;
  }
}/*END: removeFromHead()*/

/*Function to remove from tail of Linked List*/
void LinkedList::removeFromTail(){

  /*If list is current empty will do nothing*/
  /*Could also display error messge*/
  if (listLength == 0){
    return;
  }

  /*Small function to remove, delete and null head Node if only one left in list*/
  /*Could display message that last Node was deleted*/
  else if (listLength == 1){
    delete head;
    head = NULL;
    tail = NULL;
    listLength--;
    return;
  }

  /*Creates temp Node to store data then removes tail Node and assigns tail to the previous Node*/
  /*Deletes temp when it is done to stop memory leaks*/
  else{
    Node* temp = tail;
    tail = temp -> getPrevious();
    delete temp;
    listLength--;
    temp = NULL;
  }
}/*END: removeFromTail()*/

/*Function to remove from head, tail or current*/
/*If statements to find where the selected Node is located*/
/*Once located it will remove from current position*/
void LinkedList::remove(string const name){
  current = head;
  while (current != NULL){
    /*If name == head will call removeFromHead() function*/
    if (head -> getData().get_name() == name){
      removeFromHead();
      /*Function would stop here unless I added reassigned head to the new head*/
      current = head;
    }
    /*If name == tail will call removeFromTail() function*/
    /*!!!Should remain unused in assignment 1*/
    else if (tail -> getData().get_name() == name){
      removeFromTail();
    }
    /*If name == current will call removeFromCurrent() function*/
    else if (current -> getData().get_name() == name){
      removeFromCurrent();
    }
    /*moves to next for while loop*/
    current = current -> getNext();
  }
}/*END: remove() function*/

/*Function to calculate the average of each linked list*/
double LinkedList::calcAverage(){
  double average;
  current = head;
  while (current != NULL){
    average = average + (current -> getData().get_score());
    current = current -> getNext();
  }
  average = average/listLength;
  return average;
}/*END: calcAverage() function*/

/*Function to count how many of a name are in each linked list*/
int LinkedList::count(string const name){
  int count = 0;
  current = head;
  while (current != NULL){
    if (current -> getData().get_name() == name){
      count++;
    }
    current = current -> getNext();
  }
  return count;
}/*END: count() function*/


/*Overload += with code clean up. Hope to get working before submission*/
/*If it does not work function below will do the same thing just with more code*/
// /*Function to overload += operator*/
// void LinkedList::operator += (LinkedList& secondList){
//   for(Node* current = secondList.current ; current != NULL; current = current->getNext()){
        /*Works if ++ is overloaded*/
        /*Needs and overloaded ++ to work. Currently not enough time to implement*/
//     addToTail(current -> getData())//secondList.getCurrentData());
//   }
// }/*END: += overload*/

/*Overloader for +=*/
void LinkedList::operator += (LinkedList& secondList){

  if (secondList.getLength() > 0){
    secondList.moveToHead();
    for(std::size_t i = 0; i < secondList.getLength(); i++){
      addToTail(secondList.current -> getData());
      secondList.foward();
    }
  }
  else{
    return;
  }
}

// void LinkedList::addToCurrent(dataType& newData){ //WORKS UNUSED
//
//   /*Should have functions here for if list is empty*/
//   // if (current == tail){
//   //   addToTail(newData);
//   // }
//   // else if (current == NULL){
//   //   addToHead(newData);
//   // }
//   // else{
//   //   start -> setNext(current -> getNext());
//   //   entry -> setPrevious(current);
//   //
//   // }
//
//   Node* add = new Node(newData, NULL, NULL);
//   add -> setData(newData);
//   add -> setNext(current -> getNext());
//   current -> setNext(add);
//   if (current == tail){
//     tail = current -> getNext();
//   }
//   current = current -> getNext();
// }

/*Function to add node to head if linked list*/ ///UNUSED
// void LinkedList::addToHead(dataType& data){
//
//   //add Node for empty list
//   if (listLength == 0){
//     head = new Node(data, NULL, NULL);
//     tail = head;
//     current = tail;
//     listLength = 1;
//   }
//
//   else{
//
//     Node* headInsert = new Node(data, NULL, NULL);
//     head -> setPrevious(headInsert);
//     headInsert -> setNext(head);
//     head = headInsert;
//     listLength++;
//     headInsert = NULL;
//   }
// }/*END: addToHead()*/

/*Function to overload ostream <<*/
/*Used to display linked list*/
std::ostream& operator <<(std::ostream& out, LinkedList& list){

  list.moveToHead();
  for (std::size_t i = 0; i < list.getLength(); i++){
    out << "(" << list.getCurrentData().get_name() << "," << list.getCurrentData().get_score() << ")  ";
    list.foward();
  }
  return out;
}/*END: ostream << overload*/

/*Function to return listLength*/
std::size_t LinkedList::getLength(){
  return listLength;
}/*END: listLength() function*/


/*Function to move foward within the linked list*/
void LinkedList::foward(){
  current = current -> getNext();
}/*END: foward()*/

/*Function to move backwards within the linked list*/
void LinkedList::back(){
  current = current -> getPrevious();
}/*END: back() */

/*Function to move to head of Linked List*/
void LinkedList::moveToHead(){
  current = head;
}/*END: moveToHead()*/

/*Function to move to tail of linked list*/
void LinkedList::moveToTail(){
  current = tail;
}/*END: moveToTail() */

/*Function to get current Nodes data*/
LinkedList::dataType& LinkedList::getCurrentData(){
  return current -> getData();
}/*END: getCurrentData() */
