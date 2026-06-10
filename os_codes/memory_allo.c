#include <stdio.h>

int main() {
    int nb, np, i, j, ch;

    printf("Enter number of blocks and processes: ");
    scanf("%d%d", &nb, &np);

    int b[nb], p[np], alloc[np];

    printf("Enter block sizes:\n");
    for(i = 0; i < nb; i++)
        scanf("%d", &b[i]);

    printf("Enter process sizes:\n");
    for(i = 0; i < np; i++)
        scanf("%d", &p[i]);

    printf("\n1.First Fit\n2.Best Fit\n3.Worst Fit\n");
    scanf("%d", &ch);

    for(i = 0; i < np; i++)
        alloc[i] = -1;

    switch(ch) {

    case 1:

        for(i = 0; i < np; i++) {
            for(j = 0; j < nb; j++) {
                if(b[j] >= p[i]) {
                    alloc[i] = j;
                    b[j] -= p[i];
                    break;
                }
            }
        }
        break;

    case 2:

        for(i = 0; i < np; i++) {
            int best = -1;

            for(j = 0; j < nb; j++) {
                if(b[j] >= p[i]) {
                    if(best == -1 || b[j] < b[best])
                        best = j;
                }
            }

            if(best != -1) {
                alloc[i] = best;
                b[best] -= p[i];
            }
        }
        break;

    case 3:

        for(i = 0; i < np; i++) {
            int worst = -1;

            for(j = 0; j < nb; j++) {
                if(b[j] >= p[i]) {
                    if(worst == -1 || b[j] > b[worst])
                        worst = j;
                }
            }

            if(worst != -1) {
                alloc[i] = worst;
                b[worst] -= p[i];
            }
        }
        break;

    default:
        printf("Invalid Choice");
        return 0;
    }

    printf("\nProcess\tSize\tBlock\n");

    for(i = 0; i < np; i++) {
        if(alloc[i] != -1)
            printf("P%d\t%d\t%d\n", i + 1, p[i], alloc[i] + 1);
        else
            printf("P%d\t%d\tNot Allocated\n", i + 1, p[i]);
    }

    return 0;
}