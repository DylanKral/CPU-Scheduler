#include <stdlib.h>
#include <iostream>
#include <stdio.h>

#include "task.h"
#include "list.h"
#include "cpu.h"
#include "schedulers.h"

using namespace std;

// add a new task to the list of tasks
 void add(char *name, int priority, int burst, llist &list) 
{
	task newTask; // TODO: add your implementation here
  newTask.name = name; // assign values
  newTask.priority = priority;//
  newTask.burst = burst;//
  newTask.waitingTime = burst;

  Node *ptr = new Node; // create new node
  ptr->task_ = newTask;
  
  list.addRear(newTask);
}

/**
 *  * Run the FCFS scheduler
 *   */
void schedule(llist &list) 
{
  cout << "\nFCFS Scheduler\n";
  cout << "List Contains: ";
  list.displayAll();
  cout << endl;
  
  task deletedTask; // deleted task that hold the task
  int turnaroundTime = 0;//hold the total turnaround time
  int slice = 0;
  int count = list.Count;
  float averageTurnaround = 0, averageWaiting = 0;

  while (list.isEmpty() != true) // Traverse the list and delete as you go
  {
   list.deleteFront(deletedTask);// delete the front of the list then save task into deleted task   cout << deletedTask.name << endl;
   slice = deletedTask.burst; // get the proper time slice
   
   turnaroundTime += slice;
   deletedTask.burst -=deletedTask.burst;
   averageTurnaround += turnaroundTime;
   averageWaiting += turnaroundTime - deletedTask.waitingTime;

   run(deletedTask, slice, turnaroundTime); // run the task into the cpu
   
  }

  cout << "Average Turnaround Time = " << averageTurnaround / count << ", Average Waiting Time = " << averageWaiting / count  << endl;
}
