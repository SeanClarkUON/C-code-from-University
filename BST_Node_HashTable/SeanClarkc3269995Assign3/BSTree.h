/*PROGRAM NAME: BSTree.h                                                       */
/*PROGRAMMER: Sean Clark c3269995                                              */
/*COURSE: SENG1120 - Data Structures                                           */
/*USE: Assignment 3                                                            */

/*Macro Guard                                                                  */
#ifndef SEAN_BTTREE
#define SEAN_BTTREE

/*Includes                                                                     */
#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
#include "BTNode.h"
using namespace std;

/*Class Template                                                               */
template <typename valueType>
class BSTree {

/*Public Functions                                                             */
public:
	
  /*Preconditions*/
  /*None*/
  /*Post Conditions*/
  /*Root is created*/	
  BSTree();
  
  /*Preconditions*/
  /*Tree exists to be deleted*/
  /*Post Conditions*/
  /*Tree is deleted with deleteTree function recursively*/
  ~BSTree();

  /*Preconditions*/
  /*Data exists to be added*/
  /*Post Conditions*/
  /*Data is added to node and tree*/
  void add(const valueType data);
  
  /*Preconditions*/
  /*Data exists to be searched*/
  /*Post Conditions*/
  /*Returned true is data is in tree. False if data is not*/
  const valueType& search(const valueType& data);
  
  /*Preconditions*/
  /*None*/
  /*Post Conditions*/
  /*Node is removed from tree and and tree is reconstructed*/
  void remove(const valueType data);
  
  
  /*Preconditions*/
  /*None*/
  /*Post Conditions*/
  /*Calls inOrderPrint*/
  void inOrder();

/*Private Functions                                                            */
private:


  /*Preconditions*/
  /*None*/
  /*Post Conditions*/
  /*Functions to print out tree inOrder*/
  void inOrderPrint(BTNode<valueType>* node);

  /*Preconditions*/
  /*Tree exists to be deleted*/
  /*Post Conditions*/
  /*Recursively deletes all nodes within tree*/
  void deleteTree(BTNode<valueType>* node);

  /*Preconditions*/
  /**/
  /*Post Conditions*/
  /**/
  void insert(BTNode<valueType>* node, const valueType data);
  
  /*Preconditions*/
  /*Data exists to be deleted*/
  /*Post Conditions*/
  /*Deletes Node from tree and reorganises it*/
  bool deleteNode(BTNode<valueType>* node, valueType data);
    
  /*Preconditions*/
  /*None*/
  /*Post Conditions*/
  /*Returns True is data is found, False if it is not*/
  const valueType& find(BTNode<valueType>* node, const valueType& data);

  /*Creates root node. Sets to NULL*/
  BTNode<valueType>* root = NULL;

};

/*Cout overload*/
template<typename valueType>
ostream& operator <<(ostream& out, BSTree<valueType>& printOut);

/*Template Include                                                             */
#include "BSTree.hpp"

#endif
/*End Class: */
