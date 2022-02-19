/**
 * Various list operations
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"
#include "task.h"

#include<iostream>

using namespace std;

llist::llist()
{ 
  this -> Count = 0;
  this -> Front = NULL;
  this-> Rear = NULL;
}
 
// be sure to display horizontally in [  ] with
// blanks between elements
  
bool llist::isEmpty() 
{
if (Count == 0 && Front == NULL && Rear == NULL)
{ return true; }

else return false;

}

//PURPOSE:adds a node into the rear of the list
//PARAMETER: NewNum elem
void llist::addRear( task NewTask) 
{
  Node * ptr = new Node;
  ptr->task_ = NewTask;

  if (Count == 0) // if there are no elements then front and rear equal the first elem
  {
    Front = ptr;//front points to ptr
    Rear = ptr; //rear points to ptr
    Rear->Next = NULL;//set rear next to NULL
    Count++;//increments the counter
  }

  else  //if the list is not empty then it will insert at rear 
  {
    Rear->Next = ptr;// adds ptr after rear
    Rear = ptr;//rear points to ptr
    Rear->Next = NULL;//set rear next to NULL
    Count++;//increment the counter
  }

} // comment the 2 cases

//PURPOSE: Adds the elem to the front of the list
//PARAMETER: newnum
void llist::addFront(task NewTask) 
{
  Node * ptr = new Node;
  ptr->task_ = NewTask;

  if (Count == 0) // if the list is empty then make front and rear = to the new elem
  {
    Front = ptr;//have front point to ptr
    Rear = Front;//have rear point to front
    Rear ->Next =  NULL;//set rears next to NULL
    Count++;//increment counter
  }

  else //Adds the elem in the front 
  {
    ptr->Next = Front; //connect ptr to front
    Front = ptr;//have front point to ptr
    Count++;//increment counter
  }

} // comment the 2 cases

//PURPOSE: Delete the front elem
//PARAMETER: oldnum to store the old element
void llist::deleteFront(task& OldTask) 
{ 
  Node *ptr = new Node;
  if (Count == 0) // if the list is empty then it will throw underflow
  {
    throw Underflow();
  }

  else if (Count == 1) //if the list will become 0 after the deletion
  {
    OldTask = Front ->task_;
    delete Front;//delete front
    Front = NULL;//setfront to NULL
    Rear = NULL;//set rear to NULL
    Count--;//decrement counter
  }

  else // Normal Case
  {
    OldTask = Front->task_;//store the elem to oldnum
    ptr = Front->Next;// connect ptr to front
    delete Front;//delete the object
    Front = ptr;//set front to ptr
    Count--;//decrement counter
  }

} // comment the 3 cases


//PURPOSE: Delete the rear elem
//PARAMETER: Oldnum 
void llist::deleteRear(task& OldTask)
{
  Node * ptr; // creates a pointer for the second to last elem
  OldTask = Rear->task_;
  if (Count == 0) //throw underflow 
  {throw Underflow();}

  else if (Count == 1)//if this will make the list empty then delete and set front and rear to NULL
  {
    OldTask = Rear->task_;//store the element to OldNum
    delete Front;// delete the object
    Front = NULL;//set front to NULL
    Rear = NULL;//set rear to NULL
    Count--;//decrementes counter
  }

  else //If the list is normal then it will only delete rear
  {
    moveTo(Count, ptr);//ptr goes to rear-1
    Rear = ptr;//rear points to ptr
    delete Rear->Next;//delete the object
    Rear->Next = NULL; //rear next must point to NULL
    Count--; //count is decremented
  }
} // comment the 3 cases

Node* llist::returnFront(llist list)
{
  Node *ptr;

  ptr = list.Front;

  return ptr;
}

/* harder ones follow */

void llist::moveTo(int J, Node*& temp)
{ // moves temp J-1 times to go to the Jth node
  // for ( int K = ... ) temp = temp->Next;
 temp = Front; 
  for (int k = 1; k < J-1; k++)
  {temp = temp->Next;}
}

void llist::insertIth(int I, task newTask)
{
  if (I > Count +1  || I < 1) // Error case
  {throw OutOfRange();}

  if (I == 1) //if i is equal to 1 then add front
  {
    addFront(newTask);//go to addFront
  }

  else if (I > Count) // if i is equal to count then add rear
  {
    addRear(newTask);//go to addRear
  }

  else
  {
    Node *ptr = new Node;// holds the new value that is to be input
    Node *secondptr;//points to the element before the position
    Node * thirdptr;//points to the elements at the position

    ptr->task_ = newTask;
 
    moveTo(I, secondptr);//move second pointer to i
    
    thirdptr = secondptr->Next;//thirpointer is the object after seconpointer

    secondptr->Next = ptr;//connect secondptr to ptr

    ptr->Next = thirdptr;//connect ptr to thirdptr
    Count ++;//increment the count
  }
}

void llist::displayAll() 
{
  Node * ptr;
  ptr = Front;

  if (Count == 0)
  { cout << "[ Empty ]";}

else
 {
  cout << "[";

  while (ptr != NULL)
  {
    cout << ptr->task_.name << " ";
    ptr = ptr->Next;
    
  }
cout << "]" << endl;

 } 
} 
