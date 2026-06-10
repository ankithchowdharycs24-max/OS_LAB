#include <stdio.h>

int main() {
    int n, f, i, j, k, ch, faults = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    int pages[n];

    printf("Enter page reference string:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    int frame[f];

    for(i = 0; i < f; i++)
        frame[i] = -1;

    printf("\n1.FIFO\n2.LRU\n3.Optimal\n");
    scanf("%d", &ch);

    switch(ch) {

    case 1: {
        int pos = 0;

        for(i = 0; i < n; i++) {
            int found = 0;

            for(j = 0; j < f; j++)
                if(frame[j] == pages[i])
                    found = 1;

            if(!found) {
                frame[pos] = pages[i];
                pos = (pos + 1) % f;
                faults++;
            }
        }
        break;
    }

    case 2:

        for(i = 0; i < n; i++) {
            int found = 0;

            for(j = 0; j < f; j++)
                if(frame[j] == pages[i])
                    found = 1;

            if(!found) {
                int pos = -1;

                for(j = 0; j < f; j++)
                    if(frame[j] == -1) {
                        pos = j;
                        break;
                    }

                if(pos == -1) {
                    int lru = i, idx;

                    for(j = 0; j < f; j++) {
                        int last = -1;

                        for(k = i - 1; k >= 0; k--) {
                            if(frame[j] == pages[k]) {
                                last = k;
                                break;
                            }
                        }

                        if(last < lru) {
                            lru = last;
                            idx = j;
                        }
                    }

                    pos = idx;
                }

                frame[pos] = pages[i];
                faults++;
            }
        }
        break;

    case 3:

        for(i = 0; i < n; i++) {
            int found = 0;

            for(j = 0; j < f; j++)
                if(frame[j] == pages[i])
                    found = 1;

            if(!found) {
                int pos = -1;

                for(j = 0; j < f; j++)
                    if(frame[j] == -1) {
                        pos = j;
                        break;
                    }

                if(pos == -1) {
                    int farthest = -1, idx;

                    for(j = 0; j < f; j++) {
                        int next = n;

                        for(k = i + 1; k < n; k++) {
                            if(frame[j] == pages[k]) {
                                next = k;
                                break;
                            }
                        }

                        if(next > farthest) {
                            farthest = next;
                            idx = j;
                        }
                    }

                    pos = idx;
                }

                frame[pos] = pages[i];
                faults++;
            }
        }
        break;

    default:
        printf("Invalid Choice");
        return 0;
    }

    printf("Page Faults = %d\n", faults);

    return 0;
}