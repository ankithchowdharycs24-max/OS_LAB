#include <stdio.h>

#define N 5

int state[N];
int i;

void take_fork(int n) {
    if(state[(n + 4) % N] != 1 &&
       state[n] != 1 &&
       state[(n + 1) % N] != 1) {

        state[n] = 1;
        printf("Philosopher %d is Eating\n", n + 1);
    }
    else {
        state[n] = 0;
        printf("Philosopher %d is Waiting\n", n + 1);
    }
}

void put_fork(int n) {
    state[n] = 0;
    printf("Philosopher %d is Thinking\n", n + 1);
}

int main() {

    for(i = 0; i < N; i++)
        state[i] = 0;

    for(i = 0; i < N; i++) {
        take_fork(i);
        put_fork(i);
    }

    return 0;
}