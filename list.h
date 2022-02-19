/**
 * list data structure containing the tasks in the system
 */

 #include "task.h"

//a list node is defined here as a struct Node for now
struct Node
{
  task task_;   // elem is the element stored
  Node *Next;  // next is the pointer to the next node
};
//---------------------------------------------------------

class llist 
{
 protected:
  Node *Front;       // pointer to the front node
  Node *Rear;        // pointer to the rear node
          // counter for the number of nodes

  // untility function to move to a specified node position
  void moveTo(int, Node*&);
  
 public:
int  Count;
  // Exception handling classes 
  class Underflow{};
  class OutOfRange{};  // thrown when the specified Node is out of range

  llist ();     // constructor to create a list object
  //~llist();     // destructor to destroy all nodes
  
  //shows if the list is empty
  bool isEmpty();
    
  // displays all the nodes in the list
  void displayAll();

  //adds a node to the front of the list
  void addFront(task);
    
  //adds a node to the rear of the list
  void addRear(task);

  // deletes a node in the front of the list 
  void deleteFront(task&);
    
  //deletes a node in the rear of the list
  void deleteRear(task&);

  //inserts a node at the Ith position
  void insertIth(int, task);   // calls moveTo

  //returns the front of the list
  Node* returnFront(llist);

};
