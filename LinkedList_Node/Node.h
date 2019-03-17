/*PROGRAM NAME: Node.h                                                         */
/*PROGRAMMER: Sean Clark c3269995                                              */
/*COURSE: SENG1120 - Data Structures                                           */
/*USE: ASSIGNMMENT 1                                                           */

/*Macro Guard*/
#ifndef SEAN_Node
#define SEAN_Node

/*Includes*/
#include <cstdlib>
#include <string>
#include "Student.h"

/*Node class for Node.h and all connected programs*/
class Node{

  /*Public Functions/Variables*/
  public:

    /*Type Definition*/
    typedef Student dataType;

    /*Constructor*/
    Node();
    Node(const dataType& initData, Node* initNext, Node* initPrevious);

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
    void setData(const dataType& newData);

    /*****************************************************************************/
    /*Description                                                                */
    /*Set the next node within the linked list                                   */
    /*Precondition:                                                              */
    /*Data exists within student class to set                                    */
    /*Postcondition:                                                             */
    /*Data is set for use throughout the program                                 */
    void setNext(Node* nextLink);

    /*****************************************************************************/
    /*Description                                                                */
    /*Set the previous node within the  linked list                              */
    /*Precondition:                                                              */
    /*Data exists within the student class to set                                */
    /*Postcondition:                                                             */
    /*Data is set for use throughout the program                                 */
    void setPrevious(Node* previousLink);

    /*___________________________________________________________________________*/
    /*Constant Member Functions                                                  */
    /*___________________________________________________________________________*/
    dataType& getData();

    /*****************************************************************************/
    /*Description                                                                */
    /*Gets the previous Node                                                     */
    /*Precondition:                                                              */
    /*Node exists to get                                                         */
    /*Postcondition:                                                             */
    /*gets node from within linked list                                          */
    const Node* getPrevious() const;
    Node* getPrevious();

    /*****************************************************************************/
    /*Description                                                                */
    /*Gets the next Node                                                         */
    /*Precondition:                                                              */
    /*Node exists to get                                                         */
    /*Postcondition:                                                             */
    /*gets node from within linked list                                          */
    const Node* getNext() const;
    Node* getNext();

    /*****************************************************************************/
    /*Description                                                                */
    /*Gets the current  Node                                                     */
    /*Precondition:                                                              */
    /*Node exists to get                                                         */
    /*Postcondition:                                                             */
    /*gets node from within linked list                                          */
    // const Node* getCurrent() const;
    // Node* getCurrent();



  /*Private Functions/Variables*/
  private:
    dataType data;
    Node* next;
    Node* previous;
    // Node* current;


};


#endif
/*END SEAN_Node*/
