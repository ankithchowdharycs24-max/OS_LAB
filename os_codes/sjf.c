#include <stdio.h>

struct process {
    int pid, bt, wt, tat;
};

int main() {
    int n, i, j;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct process p[n], temp;

    printf("Enter burst times:\n");

    for(i = 0; i < n; i++) {
        p[i].pid = i + 1;
        scanf("%d", &p[i].bt);
    }

    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(p[i].bt > p[j].bt) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
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