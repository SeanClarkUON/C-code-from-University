/*PROGRAM NAME: BTNode.h                                                       */
/*PROGRAMMER: Sean Clark c3269995                                              */
/*COURSE: SENG1120 - Data Structures                                           */
/*USE: Assignment 3                                                            */

/*Macro Guard                                                                  */
#ifndef SEAN_BTNODE
#define SEAN_BTNODE

/*Includes                                                                     */
#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
using namespace std;

/*Class Template                                                               */
template <typename valueType>
class BTNode{

/*Public Functions                                                             */
public:

  /*Preconditions*/
  /*None*/
  /*Post Conditions*/
  /*Variables set to NULL*/
  BTNode();

  /*Preconditions*/
  /*None*/
  /*Post Conditions*/
  /*Variables and Node created at default values*/
  BTNode(const valueType& dataIn, BTNode<valueType>* leftIn, BTNode<valueType>* rightIn);

  /*Preconditions*/
  /*None*/
  /*Post Conditions*/
  /*All nodes within tree are deleted*/
  ~BTNode();

  /*Setters*/

  /*Preconditions*/
  /*Data exists to be set*/
  /*Post Conditions*/
  /*Input data set to data*/
  void setData(const valueType& dataD);

  /*Preconditions*/
  /*Data exists to be set*/
  /*Post Conditions*/
  /*Data is set to parent*/
  void setParent(BTNode<valueType>* parentP);

  /*Preconditions*/
  /*Data exists to be set*/
  /*Post Conditions*/
  /*Data is set to left*/
  void setLeft(BTNode<valueType>* leftL);

  /*Preconditions*/
  /*Data exists to be set*/
  /*Post Conditions*/
  /*Data is set to right*/
  void setRight(BTNode<valueType>* rightR);

  /*Getters*/

  /*Preconditions*/
  /*Data exists to be get*/
  /*Post Conditions*/
  /*Returns current data*/
  valueType& getData();

  /*Preconditions*/
  /*Node exists to be retrieved*/
  /*Post Conditions*/
  /*Returns parent data*/
  const BTNode<valueType>* getParent() const;

  /*Preconditions*/
  /*Node exists to be retrieved*/
  /*Post Conditions*/
  /*Returns parent data*/
  BTNode<valueType>* getParent();

  /*Preconditions*/
  /*Node exists to be retrieved*/
  /*Post Conditions*/
  /*Returns left data*/
  const BTNode<valueType>* getLeft() const;

  /*Preconditions*/
  /*Node exists to be retrieved*/
  /*Post Conditions*/
  /*Returns left data*/
  BTNode<valueType>* getLeft();

  /*Preconditions*/
  /*Node exists to be retrieved*/
  /*Post Conditions*/
  /*Returns right data*/
  const BTNode<valueType>* getRight() const;

  /*Preconditions*/
  /*Node exists to be retrieved*/
  /*Post Conditions*/
  /*Returns right data*/
  BTNode<valueType>* getRight();

/*Private Functions                                                            */
private:

  valueType data;
  BTNode<valueType>* parent;
  BTNode<valueType>* left;
  BTNode<valueType>* right;

};

/*Template Include                                                             */
#include "BTNode.hpp"

#endif
/*End Class: */
