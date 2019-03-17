/*PROGRAM NAME: BTNode.hpp                                                     */
/*PROGRAMMER: Sean Clark c3269995                                              */
/*COURSE: SENG1120 - Data Structures                                           */
/*USE: Assignment 3                                                            */
/*                                                                             */
/*Includes                                                                     */
#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
using namespace std;


template <typename valueType>
BTNode<valueType>::BTNode(){
  data = valueType();
  left = NULL;
  right = NULL;
}/*END: BTNode()*/

template <typename valueType>
BTNode<valueType>::BTNode(const valueType& dataIn, BTNode<valueType>* leftIn, BTNode<valueType>* rightIn){
  data = dataIn;
  left = leftIn;
  right = rightIn;
}/*END: BTNode()*/

template <typename valueType>
BTNode<valueType>::~BTNode(){
  left = NULL;
  right = NULL;
  data.~valueType();
}/*END: ~BTNode()*/

template <typename valueType>
void BTNode<valueType>::setData(const valueType& dataD){
  data = dataD;
}/*END: setData()*/

template <typename valueType>
void BTNode<valueType>::setParent(BTNode<valueType>* parentP){
  parent = parentP;
}/*END: setParent()*/

template <typename valueType>
void BTNode<valueType>::setLeft(BTNode<valueType>* leftL){
  left = leftL;
}/*END: setLeft()*/

template <typename valueType>
void BTNode<valueType>::setRight(BTNode<valueType>* rightR){
  right = rightR;
}/*END: setRight()*/

template <typename valueType>
valueType& BTNode<valueType>::getData(){
  return data;
}/*END: getData()*/

template <typename valueType>
const BTNode<valueType>* BTNode<valueType>::getParent() const{
  return parent;
}/*END: getParent() const*/
template <typename valueType>
BTNode<valueType>* BTNode<valueType>::getParent(){
  return parent;
}/*END: getParent()*/

template <typename valueType>
const BTNode<valueType>* BTNode<valueType>::getLeft() const{
  return left;
}/*END: getLeft() const*/
template <typename valueType>
BTNode<valueType>* BTNode<valueType>::getLeft(){
  return left;
}/*END: getLeft()*/

template <typename valueType>
const BTNode<valueType>* BTNode<valueType>::getRight() const{
  return right;
}/*END: getRight() const*/
template <typename valueType>
BTNode<valueType>* BTNode<valueType>::getRight(){
  return right;
}/*END: getRight()*/

