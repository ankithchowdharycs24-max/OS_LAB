#include <stdio.h>

struct process {
    int pid, bt, wt, tat;
};

int main() {
    int n, i;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct process p[n];

    printf("Enter burst times:\n");
    for(i = 0; i < n; i++) {
        p[i].pid = i + 1;
        scanf("%d", &p[i].bt);
    }

    p[0].wt = 0;

    for(i = 1; i < n; i++)
        p[i].wt = p[i - 1].wt + p[i - 1].bt;

    for(i = 0; i < n; i++)
        p[i].tat = p[i].wt + p[i].bt;

    printf("\nPID\tBT\tWT\tTAT\n");

    for(i = 0; i < n; i++)
        printf("%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].bt, p[i].wt, p[i].tat);

    return 0;
}