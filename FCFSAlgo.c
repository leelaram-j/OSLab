//
// Created by Lee on 06/10/20.
//

#include "stdio.h"

int main() {
    int n, burstTime[20], waitingTime[20], tat[20], i, j;
    float avgwaitingTime = 0, avgtat = 0;
    printf("Enter total number of processes \n");
    scanf("%d", &n);
    printf("\nEnter process burst time:\n");
    for (i = 0; i < 5; i++) {
        scanf("%d", &burstTime[i]);
    }
    waitingTime[0] = 0;

    // calculating waiting time
    for (i = 1; i < n; i++) {
        waitingTime[i] = 0;
        for (j = 0; j < i; j++)
            waitingTime[i] += burstTime[j];
    }

    printf("\nProcess\t\tBurst Time\t\t Waiting Time\t\tTurn Around Time");
    // calculating tat
    for (i = 0; i < n; i++) {
        tat[i] = burstTime[i] + waitingTime[i];
        avgwaitingTime += waitingTime[i];
        avgtat += tat[i];
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d", i, burstTime[i], waitingTime[i], tat[i]);
    }

    avgwaitingTime /= n;
    avgtat /= n;
    printf("\n Average waiting time: %f", avgwaitingTime);
    printf("\n Average turn around time: %f", avgtat);
    return 0;
}