#include <stdio.h>

int main() {
    int n, m, i, j, k;

    printf("Enter number of processes and resources: ");
    scanf("%d%d", &n, &m);

    int alloc[n][m], req[n][m];
    int avail[m], finish[n];

    printf("Enter Allocation Matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter Request Matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            scanf("%d", &req[i][j]);

    printf("Enter Available Resources:\n");
    for(i = 0; i < m; i++)
        scanf("%d", &avail[i]);

    for(i = 0; i < n; i++) {
        int flag = 0;

        for(j = 0; j < m; j++) {
            if(alloc[i][j] != 0) {
                flag = 1;
                break;
            }
        }

        finish[i] = !flag;
    }

    int count = 0;

    while(count < n) {

        int found = 0;

        for(i = 0; i < n; i++) {

            if(!finish[i]) {

                for(j = 0; j < m; j++)
                    if(req[i][j] > avail[j])
                        break;

                if(j == m) {

                    for(k = 0; k < m; k++)
                        avail[k] += alloc[i][k];

                    finish[i] = 1;
                    found = 1;
                    count++;
                }
            }
        }

        if(!found)
            break;
    }

    int deadlock = 0;

    for(i = 0; i < n; i++) {
        if(!finish[i]) {
            printf("P%d ", i);
            deadlock = 1;
        }
    }

    if(deadlock)
        printf("are in deadlock");
    else
        printf("No deadlock detected");

    return 0;
}