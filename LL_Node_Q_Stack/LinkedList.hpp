/*PROGRAM NAME: LinkedList.hpp                                                */
/*PROGRAMMER: Sean Clark c3269995                                              */
/*COURSE: SENG1120 - Data Structures                                           */
/*USE: ASSIGNMMENT 2                                                           */

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

/*Construtors*/
/*Constructs: head, tail, current, listLength*/
template <typename valueType>
LinkedList<valueType>::LinkedList(){
  head = NULL;
  tail = NULL;
  current = NULL;
  listLength = 0 ;
}/*END: LinkedList()*/

/*Sets up Node*/
/*Creates tail and current for linked lists*/
template <typename valueType>
LinkedList<valueType>::LinkedList(valueType& data){
  head = new Node<valueType>(data, NULL, NULL);
  tail = head;
  current = tail;
  listLength = 1;
}/*END: LinkedList()*/

/*Destructor*/
template <typename valueType>
LinkedList<valueType>::~LinkedList(){
  while (head != NULL){
    removeFromHead();
  }
  current = NULL;
  tail = NULL;
}/*END: ~LinkedList()*/

/*Add to Tail Function*/
template <typename valueType>
void LinkedList<valueType>::addToTail(valueType& data){

  /*If tail and head are both empty, it will create a new Node*/
  /*Will assign this new Node to both head and tail*/
  if (listLength == 0){
    head = new Node<valueType>(data, NULL, NULL);
    tail = head;
    current = tail;
    listLength = 1;
  }

  /*Insert new Node to tail*/
  /*Will also initialize the first list made*/
  else{

    /*Creates temp Node on heap to store new data*/
    Node<valueType>* tailIn = new Node<valueType>(data, NULL, NULL);
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

/*Remove from head function*/
template <typename valueType>
void LinkedList<valueType>::removeFromHead(){

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
    Node<valueType>* temp = head;
    head = temp -> getNext();
    delete temp;
    listLength--;
    temp = NULL;
  }
}/*END: removeFromHead()*/

/*Function to remove from tail of Linked List*/
template <typename valueType>
void LinkedList<valueType>::removeFromTail(){

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
    Node<valueType>* temp = tail;
    tail = temp -> getPrevious();
    delete temp;
    listLength--;
    temp = NULL;
  }
}/*END: removeFromTail()*/

/*Function to add node to head if linked list*/ ///UNUSED
template <typename valueType>
void LinkedList<valueType>::addToHead(valueType& data){

  //add Node for empty list
  if (listLength == 0){
    head = new Node<valueType>(data, NULL, NULL);
    tail = head;
    current = tail;
    listLength = 1;
  }

  else{

    Node<valueType>* headInsert = new Node<valueType>(data, NULL, NULL);
    head -> setPrevious(headInsert);
    headInsert -> setNext(head);
    head = headInsert;
    listLength++;
    headInsert = NULL;
  }
}/*END: addToHead()*/

/*Function to return listLength*/
template <typename valueType>
std::size_t LinkedList<valueType>::getLength(){
  return listLength;
}/*END: listLength() function*/


/*Function to move foward within the linked list*/
template <typename valueType>
void LinkedList<valueType>::foward(){
  current = current -> getNext();
}/*END: foward()*/

/*Function to move backwards within the linked list*/
template <typename valueType>
void LinkedList<valueType>::back(){
  current = current -> getPrevious();
}/*END: back() */

/*Function to move to head of Linked List*/
template <typename valueType>
void LinkedList<valueType>::moveToHead(){
  current = head;
}/*END: moveToHead()*/

/*Function to move to tail of linked list*/
template <typename valueType>
void LinkedList<valueType>::moveToTail(){
  current = tail;
}/*END: moveToTail() */

/*Function to get current Nodes data*/
template <typename valueType>
valueType& LinkedList<valueType>::getCurrentData(){
  return current -> getData();
}/*END: getCurrentData() */
