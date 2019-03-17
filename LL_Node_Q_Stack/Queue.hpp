/*PROGRAM NAME: Queue.hpp                                                      */
/*PROGRAMMER: Sean Clark c3269995                                              */
/*COURSE: SENG1120 - Data Structures                                           */
/*USE: ASSIGNMMENT 2                                                           */

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

/*Constructor*/
template <typename valueType>
Queue<valueType>::Queue(){
  /* - Currently not required as Queue does not create anything new only reuses*/
  /*   what has been created in LinkedList.h and Node.h.                       */
  /*                                                                           */
  /* - It is here to show that I do know it would need one if Queue did create */
  /*   new objects                                                             */
}/*END: Queue()*/

/*Destructor*/
template <typename valueType>
Queue<valueType>::~Queue(){
  data.~LinkedList();
}/*END: ~Queue()*/


/*Function for enqueue                                                         */
/*Calls addToTail() from LinkedList.h*/
template <typename valueType>
void Queue<valueType>::enqueue(valueType& entry){
  data.addToTail(entry);
}/*END: enqueue()*/

/*Function to dequeue                                                          */
/*Calls removeFromHead() from LinkedList.h*/
template <typename valueType>
valueType Queue<valueType>::dequeue(){
  data.removeFromHead();
  return 0;
}/*END: dequeue()*/

/*Function to get data from first node in linked list                          */
/*Calls getCurrentData() from LinkedList.h                                     */
template <typename valueType>
valueType& Queue<valueType>::front(){
  data.moveToHead();
  return data.getCurrentData();
}/*END: front()*/


/*Function to find length of current list                                      */
/*Calls getLength() from LinkedList.h                                          */
template <typename valueType>
int Queue<valueType>::size() const{
  return data.getLength();
}/*END: size()*/

/*Function to check if list is empty                                           */
template <typename valueType>
bool Queue<valueType>::isEmpty() const{
  bool temp = false;
  if (data.getLength() == 0){
    temp = true;
  }
  return temp;
}/*END: isEmpty()                                                              */

/*Function that finds the average score                                        */
/*Reused in stdeviation()                                                      */
template <typename valueType>
double Queue<valueType>::average(){
  double average = 0;
  data.moveToHead();
  for (size_t i = 0; i < data.getLength(); i++){//(data.getCurrent() != NULL){
    average = average + (data.getCurrentData());
    data.foward();
  }
  average = average/data.getLength();
  return average;
}/*END: average()                                                              */

/*Function to find the minimum score, then return it                           */
/*Tested by placing minimum score in middle of list and returning it           */
template <typename valueType>
valueType Queue<valueType>::minimum(){
  data.moveToHead();
  int temp = data.getCurrentData();
  for (size_t i = 0; i < data.getLength(); i++){
    if (data.getCurrentData() < temp){
      temp = data.getCurrentData();
    }
    data.foward();
  }
  return temp;
}/*END: minimum()                                                              */

/*Function to return the maximum score within list of scores                   */
template <typename valueType>
valueType Queue<valueType>::maximum(){
  data.moveToHead();
  int temp = data.getCurrentData();
  for (size_t i = 0; i < data.getLength(); i++){
    if (data.getCurrentData() > temp){
      temp = data.getCurrentData();
    }
    data.foward();
  }
  return temp;
}/*END: maximum()                                                              */

/*Function to return standard deviation of scores                              */
template <typename valueType>
double Queue<valueType>::stdeviation(){
  data.moveToHead();
  double temp1 = 0;
  double temp2 = 0;
  double average1 = average();
  data.moveToHead();

  for (size_t i = 0; i < data.getLength(); i++){
      temp2 = data.getCurrentData();
      temp2 = pow((temp2 - average1), 2);
    temp1 = temp1 + temp2;
    data.foward();
  }

  temp1 = temp1/data.getLength();
  temp1 = sqrt(temp1);
  return temp1;
}/*END: stdeviation()                                                          */
