#include <stdlib.h>
#include <iostream>
#include <stdio.h>

using namespace std;
#include "task.h"
#include "list.h"
#include "cpu.h"
#include "schedulers.h"

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
 *  * Run the Priority RR scheduler
 */
void schedule(llist &list) 
{
  cout << "\nRound Robin Scheduler\n";
  cout << "List Contains: ";
  list.displayAll();
  cout << endl;

  task deletedTask; // deleted task that hold the task
  task preemptedTask;
  int turnaroundTime = 0, waitingTime = 0;
  float averageWaiting = 0, averageTurnaround = 0;
  int count = list.Count;

  while (list.isEmpty() != true) // Traverse the list and delete as you go
  {
   list.deleteFront(deletedTask);// delete the front of the list then save task into deleted task
   
   if (deletedTask.burst > QUANTUM)// if the burst is longer than the quantum, then preempt
   {
     turnaroundTime += QUANTUM;
     deletedTask.burst = deletedTask.burst - QUANTUM;
     preemptedTask = run(deletedTask, QUANTUM,turnaroundTime);
     list.addRear(preemptedTask);
     continue;
   }

   else if (deletedTask.burst - QUANTUM <= 0 ) // if the burst is less than or equal to the quantum, do not preempt
   {
     turnaroundTime += deletedTask.burst;
     averageTurnaround += turnaroundTime;
     deletedTask.burst = 0;

     waitingTime = turnaroundTime - deletedTask.waitingTime;
     averageWaiting += waitingTime;
     preemptedTask = run(deletedTask, QUANTUM,turnaroundTime);
   }

  }
  
  cout << "Average Turnaround Time = " << averageTurnaround / count << ", Average Waiting Time = " << averageWaiting / count  << endl;
}
