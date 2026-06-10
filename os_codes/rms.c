#include <stdio.h>

struct task {
    int id, period;
};

int main() {
    int n, i, j;

    printf("Enter number of tasks: ");
    scanf("%d", &n);

    struct task t[n], temp;

    printf("Enter periods:\n");

    for(i = 0; i < n; i++) {
        t[i].id = i + 1;
        scanf("%d", &t[i].period);
    }

    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(t[i].period > t[j].period) {
                temp = t[i];
                t[i] = t[j];
                t[j] = temp;
            }
        }
    }

    printf("\nExecution Order:\n");

    for(i = 0; i < n; i++)
        printf("Task %d Period %d\n", t[i].id, t[i].period);

    return 0;
}