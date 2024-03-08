#include <stdio.h>

#define MAX_PROCESSES 10

typedef struct {
    int arrivalTime;
    int burstTime;
    int waitingTime;
    int turnaroundTime;
} Process;

void calculateTimes(Process processes[], int numProcesses) {
    int completionTime = 0;

    for (int i = 0; i < numProcesses; ++i) {
        processes[i].waitingTime = completionTime - processes[i].arrivalTime;
        processes[i].turnaroundTime = processes[i].waitingTime + processes[i].burstTime;
        completionTime += processes[i].burstTime;
    }
}

void displayProcessTable(Process processes[], int numProcesses) {
    printf("Process\tArrival Time\tBurst Time\tTurnaround Time\tWaiting Time\n");

    for (int i = 0; i < numProcesses; ++i) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n",
               i + 1, processes[i].arrivalTime,
               processes[i].burstTime, processes[i].turnaroundTime,
               processes[i].waitingTime);
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int numProcesses;

    printf("Enter the number of processes (up to %d): ", MAX_PROCESSES);
    scanf("%d", &numProcesses);

    printf("Enter arrival time and burst time for each process:\n");
    for (int i = 0; i < numProcesses; ++i) {
        printf("Process %d: ", i + 1);
        scanf("%d %d", &processes[i].arrivalTime, &processes[i].burstTime);
    }

    // Calculate turnaround time and waiting time
    calculateTimes(processes, numProcesses);

    // Display the process table
    displayProcessTable(processes, numProcesses);

    return 0;
}

