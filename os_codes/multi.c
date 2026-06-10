#include <stdio.h>

struct process {
    int pid, bt, type, wt, tat;
};

int main() {
    int n, i;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct process p[n], temp;

    printf("Enter BT and Type (1-System, 0-User):\n");

    for(i = 0; i < n; i++) {
        p[i].pid = i + 1;
        scanf("%d%d", &p[i].bt, &p[i].type);
    }

    for(i = 0; i < n - 1; i++) {
        int j;
        for(j = i + 1; j < n; j++) {
            if(p[i].type < p[j].type) {
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

    printf("\nPID\tBT\tWT\tTAT\tType\n");

    for(i = 0; i < n; i++)
        printf("%d\t%d\t%d\t%d\t%s\n",
               p[i].pid,
               p[i].bt,
               p[i].wt,
               p[i].tat,
               p[i].type ? "System" : "User");

    return 0;
}