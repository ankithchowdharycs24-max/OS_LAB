#include <stdio.h>

struct task {
    int id, share;
};

int main() {
    int n, i, total = 0;

    printf("Enter number of tasks: ");
    scanf("%d", &n);

    struct task t[n];

    printf("Enter shares:\n");

    for(i = 0; i < n; i++) {
        t[i].id = i + 1;
        scanf("%d", &t[i].share);
        total += t[i].share;
    }

    printf("\nCPU Allocation:\n");

    for(i = 0; i < n; i++)
        printf("Task %d = %.2f%%\n",
               t[i].id,
               (t[i].share * 100.0) / total);

    return 0;
}