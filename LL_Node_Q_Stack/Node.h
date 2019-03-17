/*PROGRAM NAME: Node.h                                                         */
/*PROGRAMMER: Sean Clark c3269995                                              */
/*COURSE: SENG1120 - Data Structures                                           */
/*USE: ASSIGNMMENT 2                                                           */

/*Macro Guard                                                                  */
#ifndef SEAN_Node
#define SEAN_Node

/*Includes                                                                     */
#include <cstdlib>
#include <string>

/*Node class for Node.h and all connected programs*/
template <typename valueType>
class Node{

  /*Public Functions/Variables*/
  public:

    Node();
    Node(const valueType& initData, Node<valueType>* initNext, Node<valueType>* initPrevious);

    /*Destructor*/
    ~Node();

    /*___________________________________________________________________________*/
    /*Functions                                                                  */
    /*___________________________________________________________________________*/

    /*****************************************************************************/
    /*Description                                                                */
    /*Sets Data to student class to store                                        */
    /*Precondition:                                                              */
    /*Student class exists to store data with getters and setters                */
    /*Postcondition:                                                             */
    /*Data is stored for use throughout the program                              */
    void setData(const valueType& newData);

    /*****************************************************************************/
    /*Description                                                                */
    /*Set the next node within the linked list                                   */
    /*Precondition:                                                              */
    /*Data exists within student class to set                                    */
    /*Postcondition:                                                             */
    /*Data is set for use throughout the program                                 */
    void setNext(Node<valueType>* nextLink);

    /*****************************************************************************/
    /*Description                                                                */
    /*Set the previous node within the  linked list                              */
    /*Precondition:                                                              */
    /*Data exists within the student class to set                                */
    /*Postcondition:                                                             */
    /*Data is set for use throughout the program                                 */
    void setPrevious(Node<valueType>* previousLink);

    /*___________________________________________________________________________*/
    /*Constant Member Functions                                                  */
    /*___________________________________________________________________________*/
    valueType& getData();

    /*****************************************************************************/
    /*Description                                                                */
    /*Gets the previous Node                                                     */
    /*Precondition:                                                              */
    /*Node exists to get                                                         */
    /*Postcondition:                                                             */
    /*gets node from within linked list                                          */
    const Node<valueType>* getPrevious() const;
    Node<valueType>* getPrevious();

    /*****************************************************************************/
    /*Description                                                                */
    /*Gets the next Node                                                         */
    /*Precondition:                                                              */
    /*Node exists to get                                                         */
    /*Postcondition:                                                             */
    /*gets node from within linked list                                          */
    const Node<valueType>* getNext() const;
    Node<valueType>* getNext();

    /*****************************************************************************/
    /*Description                                                                */
    /*Gets the current  Node                                                     */
    /*Precondition:                                                              */
    /*Node exists to get                                                         */
    /*Postcondition:                                                             */
    /*gets node from within linked list                                          */
    // const Node* getCurrent() const;
    Node* getCurrent();



  /*Private Functions/Variables*/
  private:
    valueType data;
    Node<valueType>* next;
    Node<valueType>* previous;
    Node<valueType>* current;


};

#include "Node.hpp"


#endif
/*END SEAN_Node*/
