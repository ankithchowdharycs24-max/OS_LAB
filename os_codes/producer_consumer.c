#include <stdio.h>

int mutex = 1, full = 0, empty = 5, x = 0;

int wait(int s) {
    return --s;
}

int signal(int s) {
    return ++s;
}

int main() {
    int ch;

    while(1) {
        printf("\n1. Produce\n2. Consume\n3. Exit\n");
        scanf("%d", &ch);

        switch(ch) {

        case 1:
            if(empty != 0 && mutex == 1) {
                mutex = wait(mutex);
                full = signal(full);
                empty = wait(empty);
                x++;
                printf("Produced item %d", x);
                mutex = signal(mutex);
            }
            else
                printf("Buffer Full");
            break;

        case 2:
            if(full != 0 && mutex == 1) {
                mutex = wait(mutex);
                full = wait(full);
                empty = signal(empty);
                printf("Consumed item %d", x);
                x--;
                mutex = signal(mutex);
            }
            else
                printf("Buffer Empty");
            break;

        case 3:
            return 0;
        }
    }
}