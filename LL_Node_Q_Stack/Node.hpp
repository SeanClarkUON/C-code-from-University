/*PROGRAM NAME: Node.hpp                                                       */
/*PROGRAMMER: Sean Clark c3269995                                              */
/*COURSE: SENG1120 - Data Structures                                           */
/*USE: ASSIGNMMENT 2                                                           */

#include <cstdlib>
#include <string>

/*Constructors for Node<valueType>*/
template <typename valueType>
Node<valueType>::Node(){
  data = valueType();
  next = NULL;
  previous = NULL;
}
template <typename valueType>
Node<valueType>::Node(const valueType& initData, Node<valueType>* initNext, Node<valueType>* initPrevious){
  data = initData;
  next = initNext;
  previous = initPrevious;
}

/*Destructors for Node<valueType>*/
template <typename valueType>
Node<valueType>::~Node(){
  next = NULL;
  previous = NULL;
  data.~valueType();
}

/*Modification member functions*/
/*Function to set data*/
template <typename valueType>
void Node<valueType>::setData(const valueType& newData){
  data = newData;
}/*END: setData*/

/*Sets next Node<valueType>*/
template <typename valueType>
void Node<valueType>::setNext(Node<valueType>* nextLink){
  next = nextLink;
}/*END: setNext()*/

/*Function to get previous Node<valueType>*/
template <typename valueType>
void Node<valueType>::setPrevious(Node<valueType>* previousLink){
  previous = previousLink;
}/*END: setPrevious*/

/*Function to get student data*/
template <typename valueType>
valueType& Node<valueType>::getData(){
  return data;
}/*END: getData()*/

/*Functions to get previous node with both const and non cost versions*/
template <typename valueType>
const Node<valueType>* Node<valueType>::getPrevious() const{
  return previous;
}/*END: getNext() const*/
template <typename valueType>
Node<valueType>* Node<valueType>::getPrevious(){
  return previous;
}/*END: getPrevious()*/

/*Functions to get next node with both const and non const versions*/
template <typename valueType>
const Node<valueType>* Node<valueType>::getNext() const{
  return next;
}/*END: getNext() const*/
template <typename valueType>
Node<valueType>* Node<valueType>::getNext(){
  return next;
}/*END: getNext()*/

template <typename valueType>
Node<valueType>* Node<valueType>::getCurrent(){
  return current;
}/*END: getCurrent()*/
