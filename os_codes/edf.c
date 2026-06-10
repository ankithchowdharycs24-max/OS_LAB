#include <stdio.h>

struct task {
    int id, deadline;
};

int main() {
    int n, i, j;

    printf("Enter number of tasks: ");
    scanf("%d", &n);

    struct task t[n], temp;

    printf("Enter deadlines:\n");

    for(i = 0; i < n; i++) {
        t[i].id = i + 1;
        scanf("%d", &t[i].deadline);
    }

    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(t[i].deadline > t[j].deadline) {
                temp = t[i];
                t[i] = t[j];
                t[j] = temp;
            }
        }
    }

    printf("\nExecution Order:\n");

    for(i = 0; i < n; i++)
        printf("Task %d Deadline %d\n", t[i].id, t[i].deadline);

    return 0;
}