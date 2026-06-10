#include <stdio.h>

struct process {
    int pid, bt, rem, wt, tat;
};

int main() {
    int n, tq, i;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct process p[n];

    printf("Enter burst times:\n");

    for(i = 0; i < n; i++) {
        p[i].pid = i + 1;
        scanf("%d", &p[i].bt);
        p[i].rem = p[i].bt;
    }

    printf("Enter time quantum: ");
    scanf("%d", &tq);

    int time = 0, done;

    do {
        done = 1;

        for(i = 0; i < n; i++) {
            if(p[i].rem > 0) {
                done = 0;

                if(p[i].rem > tq) {
                    time += tq;
                    p[i].rem -= tq;
                }
                else {
                    time += p[i].rem;
                    p[i].wt = time - p[i].bt;
                    p[i].rem = 0;
                }
            }
        }

    } while(!done);

    for(i = 0; i < n; i++)
        p[i].tat = p[i].wt + p[i].bt;

    printf("\nPID\tBT\tWT\tTAT\n");

    for(i = 0; i < n; i++)
        printf("%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].bt,
               p[i].wt, p[i].tat);

    return 0;
}