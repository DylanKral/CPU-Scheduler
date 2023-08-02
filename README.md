# CPU-Scheduler
This program shows emulates a CPU scheduler and shows different algorithms that are used.

"Virtual" CPU that also maintains track of system time.
To run this code, Enter make then pick a scheduling algorithm of your 
choosing. After doing so do ./(algorithm) schedule.txt

EX) 

    make rr
    
    ./rr schedule.txt
EX) 

    make fcfs
    
    ./fcfs schedule.txt

The program shows the turn around time and the waiting time for each task, as well as the tasks that the list contains. At the end, it will 
calculate the average turnaround time and average waiting time for all
of the tasks.
