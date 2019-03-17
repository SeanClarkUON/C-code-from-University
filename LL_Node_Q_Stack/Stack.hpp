/*PROGRAM NAME: Stack.hpp                                                      */
/*PROGRAMMER: Sean Clark c3269995                                              */
/*COURSE: SENG1120 - Data Structures                                           */
/*USE: ASSIGNMMENT 2                                                           */

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

/*Constructor for Stack.hpp/h                                                  */
template <typename valueType>
Stack<valueType>::Stack(){
  /* - Currently not required as Stack does not create anything new only reuses*/
  /*   what has been created in LinkedList.h and Node.h.                       */
  /*                                                                           */
  /* - It is here to show that I do know it would need one if Stack did create */
  /*   new objects                                                             */
}/*END: Stack()                                                                */

/*Destructor for Stack.hpp/h                                                   */
template <typename valueType>
Stack<valueType>::~Stack(){
  data.~LinkedList();
}/*END: ~Stack()                                                               */

/*Function to addToHead of stack                                               */
template <typename valueType>
void Stack<valueType>::push(valueType& entry){
  data.addToHead(entry);
}/*END: push()                                                                 */

/*Function to removeFromHead of stack                                          */
template <typename valueType>
valueType Stack<valueType>::pop(){
  return data.removeFromHead();
}/*END: pop()                                                                  */

/*Function to get size of stack                                                */
template <typename valueType>
int Stack<valueType>::size() const{
  return data.getLength();
}/*END: size()                                                                 */

/*Function to check if currrent stack is empty                                 */
template <typename valueType>
bool Stack<valueType>::isEmpty() const{
  bool stackEmpty = false;
  if (data.getLength() > 0){
    stackEmpty = true;
  }
  return stackEmpty;
}/*END: isEmpty()                                                              */

/*Top Function ***********UNUSED IN ASSIGNMENT*******************              */
template <typename valueType>
valueType& Stack<valueType>::top(){
 /*Not used within assignment*/
 /*Not used within assignment*/
 /*Not used within assignment*/
}/*END: Top()                                                                  */

/*Function to move to head of stack*/
template <typename valueType>
void Stack<valueType>::getStackHead(){
  return data.moveToHead();
}/*END: getStackHead()                                                         */

/*Function to move foward within stack                                         */
template <typename valueType>
void Stack<valueType>::stackFoward(){
  return data.foward();
}/*END: stackFoward()                                                          */

template <typename valueType>
valueType& Stack<valueType>::getStackData(){
  return data.getCurrentData();
}/*END: getStackData()                                                         */

/*Overloaded cout for stack                                                    */
template<typename valueType>
ostream& operator <<(ostream& out, Stack<valueType>& data){
  if (data.size() == 0){
    return;
  }
  data.getStackHead();
  out << "( ";
  for (int i = 0; i < data.size(); i++){
    out << data.getStackData() << " ";
    data.stackFoward();
  }
  out << ")";
  return out;
}/*END: cout << overload                                                       */
