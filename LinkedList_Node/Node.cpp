/*PROGRAM NAME: Node.cpp                                                       */
/*PROGRAMMER: Sean Clark c3269995                                              */
/*COURSE: SENG1120 - Data Structures                                           */
/*USE: ASSIGNMMENT 1                                                           */

#include <cstdlib>
#include <string>
#include "Node.h"

    /*Constructors for Node*/
    Node::Node(){
      data = dataType();
      next = NULL;
      previous = NULL;
    }
    Node::Node(const dataType& initData, Node* initNext, Node* initPrevious){
      data = initData;
      next = initNext;
      previous = initPrevious;
    }

    /*Destructors for Node*/
    Node::~Node(){
      next = NULL;
      previous = NULL;
      // data.~dataType();
      //This is the method I found to explicity call the destructor. It currently displays the error aborted (core dump)
      //I believe this is the correct way to do it but currently will not talk to student
    }

    /*Modification member functions*/
    /*Function to set data*/
    void Node::setData(const dataType& newData){
      data = newData;
    }/*END: setData*/

    /*Sets next node*/
    void Node::setNext(Node* nextLink){
      next = nextLink;
    }/*END: setNext()*/

    /*Function to get previous node*/
    void Node::setPrevious(Node* previousLink){
      previous = previousLink;
    }/*END: setPrevious*/

    /*Function to get student data*/
    Node::dataType& Node::getData(){
      return data;
    }/*END: getData()*/

    /*Functions to get previous node with both const and non cost versions*/
    const Node* Node::getPrevious() const{
      return previous;
    }/*END: getNext() const*/
    Node* Node::getPrevious(){
      return previous;
    }/*END: getPrevious()*/

    /*Functions to get next node with both const and non const versions*/
    const Node* Node::getNext() const{
      return next;
    }/*END: getNext() const*/
    Node* Node::getNext(){
      return next;
    }/*END: getNext()*/

    // Node* Node::getCurrent(){
    //   return current;
    // }/*END: getCurrent()*/
