/**
To run this program do make sjf
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

#include "task.h"
#include "list.h"
#include "schedulers.h"

using namespace std;

#define SIZE    100

int main(int argc, char *argv[])
{
    std::cout << "\n\nCS 433 Programming assignment 3" << endl;
    std::cout << "Author: Dylan Kral" << endl;
    std::cout << "Date: 11/07/2021" << endl;
    std::cout << "Course: CS433 (Operating Systems)" << endl;
    std::cout << "Description : Scheduling program which takes processes and runs them based on the scheduling algorithm used. " << endl;
    std::cout << "=================================" << endl;

    FILE *in;
    char *temp;
    char task[SIZE];
    llist list;

    char *name;
    int priority;
    int burst;
    
    in = fopen(argv[1],"r");
    
    while (fgets(task,SIZE,in) != NULL) {
        temp = strdup(task);
        name = strsep(&temp,",");
        priority = atoi(strsep(&temp,","));
        burst = atoi(strsep(&temp,","));

        // add the task to the scheduler's list of tasks
        add(name,priority,burst, list);

        free(temp);
    }

    fclose(in);

   
    // invoke the scheduler
    schedule(list);

    return 0;
}
