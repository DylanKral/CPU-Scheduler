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
	Task newTask;// create new task to hold values
  Node *ptr; // create node pointer to access list
  ptr = list.returnFront(list);
  //int count = 1;

  newTask.name = name;//instantiate values
  newTask.priority = priority;
  newTask.burst = burst;
  newTask.waitingTime = burst;
  int count = 1;

  if (list.isEmpty() == true)//insert into empty list
    {
      list.addFront(newTask);
      list.displayAll();
      return;
    }

  else 
  {
   
    while (ptr != NULL)
    {
      if (ptr->Next == NULL)
      {
        if ( ptr->task_.priority >= newTask.priority)
        {
          list.addRear(newTask);
          list.displayAll();
          break;
        }

        else if ( ptr->task_.priority <newTask.priority )
        {
          list.insertIth(count, newTask);
          list.displayAll();
          break;
        }

      }
      
      else if (ptr->task_.priority >= newTask.priority)
      {
        ptr = ptr->Next;
        count++;
        continue;
      }

      else if (ptr->task_.priority < newTask.priority)
      {
        list.insertIth(count, newTask);
        list.displayAll();
        break;
      }

     
    }
  }
}

/**
 *  * Run the Priority scheduler
 *   
 */
void schedule(llist &list) 
{
cout << "\nPriority Scheduler\n";
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
