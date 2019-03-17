/*PROGRAM NAME: BSTree.hpp                                                     */
/*PROGRAMMER: Sean Clark c3269995                                              */
/*COURSE: SENG1120 - Data Structures                                           */
/*USE: Assignment 3                                                            */

/*Includes                                                                     */
#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
using namespace std;

template <typename valueType>
BSTree<valueType>::BSTree(){
	root = NULL;
}/*END: BSTree()*/

template <typename valueType>
BSTree<valueType>::~BSTree(){
  deleteTree(root);
}/*END: ~BSTree*/

template <typename valueType>
void BSTree<valueType>::deleteTree(BTNode<valueType>* node){
  if (node != NULL){
    deleteTree(node -> getLeft());
    deleteTree(node -> getRight());
    delete node;
  }
}/*END: deleteTree()*/

template <typename valueType>
void BSTree<valueType>::add(const valueType data){

  if (root == NULL){
      BTNode<valueType>* temp = new BTNode<valueType>(data, NULL, NULL);
      root = temp;
  }
  else{
    insert(root, data);
  }
}/*END: add()*/

template <typename valueType>
const valueType& BSTree<valueType>::search(const valueType& data){
  return find(root, data);
}/*END: search()*/

template <typename valueType>
void BSTree<valueType>::remove(const valueType data){
  deleteNode(root, data);
}/*END: remove()*/

template <typename valueType>
void BSTree<valueType>::insert(BTNode<valueType>* node,const  valueType data){

    if (node -> getData() == data){
        return;
    }
    else if (node -> getData() < data)
    {
      if (node -> getRight() == NULL){
        BTNode<valueType>* temp = new BTNode<valueType>(data, NULL, NULL);
        node -> setRight(temp);
      }
      else{
        insert(node -> getRight(), data);
      }
    }
    else if (node -> getData() > data){

      if (node -> getLeft() == NULL){

        BTNode<valueType>* temp = new BTNode<valueType>(data, NULL, NULL);
        node -> setLeft(temp);
      }
      else{
        insert(node -> getLeft(), data);
      }
    }
}/*END: insert()*/

template <typename valueType>
const valueType& BSTree<valueType>::find(BTNode<valueType>* node, const valueType& data){
  if (node == NULL){
    return NULL;
  }
  if (node -> getData() == data){
    data = node;
    return node -> getNodeData();
  }
  valueType temp;
  temp = find(node -> getLeft(), data);
  if (temp == data){
    return temp;
  }
  temp = find(node -> getRight(), data);
}/*END: find()*/

template <typename valueType>
bool BSTree<valueType>::deleteNode(BTNode<valueType>* node, valueType data){
  if (node == NULL){
    return false;
  }
  if (node -> getData() > data){
    deleteNode(node -> getRight(), data);
  }
  else if (node -> getData() < data){
    deleteNode(node -> getLeft(), data);
  }
  else{
    if (node -> getLeft() == NULL && node -> getRight() == NULL){
      if (node -> getData() == data){
        data = -1;
      }

      else{
        if (node -> getRight() != NULL){
          node -> getParent() -> setRight(NULL);
        }
        else{
          node -> getParent() -> setLeft(NULL);
        }
      }

      delete node;
    }
    else if((node -> getLeft() == NULL && node -> getRight() != NULL) || (node -> getLeft() != NULL && node -> getRight() == NULL)){

      if (node -> getData() == data){
        if (node -> getRight() != NULL){
          node -> getRight() -> setParent(NULL);
          data = node -> getRight() -> getData();
        }
        else{
          node -> getLeft() -> setParent(NULL);
          data = node -> getLeft() -> getData();
        }
      }
      else if (node -> getRight() != NULL){
        node -> getRight() -> setParent(node -> getParent());
        if (node -> getRight() != NULL){
          node -> getParent() -> setRight(node -> getRight());
        }
        else{
          node -> getParent() -> setLeft(node -> getRight());
        }
      }
      else{
        node -> getLeft() -> setParent(node -> getParent());
        if (node -> getRight() != NULL){
          node -> getParent() -> setRight(node -> getLeft());
        }
        else{
          node -> getParent() -> setLeft(node -> getLeft());
        }
      }
      delete node;
    }

    else{
      BTNode<valueType>* temp = new BTNode<valueType>(data, NULL, NULL);
      deleteNode(node -> getRight(), temp -> getData());
      node -> setData(temp -> getData());
    }

    return true;
  }
  return false;
}/*END: deleteNode()*/

template <typename valueType>
void BSTree<valueType>::inOrder(){
  inOrderPrint(root);
}/*END: isOrder()*/

template <typename valueType>
void BSTree<valueType>::inOrderPrint(BTNode<valueType>* node){

  if (node != NULL){

    inOrderPrint(node -> getLeft());
    cout << node -> getData() << " ";
    inOrderPrint(node -> getRight());

  }
}/*END: inOrderPrint()*/


template<typename valueType>
ostream& operator <<(ostream& out, BSTree<valueType>& printOut){
  printOut.inOrder();
  return out;
}/*END: overload*/
