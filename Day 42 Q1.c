#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Queue implementation
int queue[MAX];
int front = -1, rear = -1;

// Stack implementation
int stack[MAX];
int top = -1;

// Queue operations
void enqueue(int x) {
    if (rear == MAX - 1) return;

    if (front == -1) front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

// Stack operations
void push(int x) {
    stack[++top] = x;
}

int pop() {
    if (top == -1) return -1;
    return stack[top--];
}

int isQueueEmpty() {
    return (front == -1 || front > rear);
}

int main() {
    int N, x;

    scanf("%d", &N);

    // Input queue
    for (int i = 0; i < N; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    // Step 1: Queue → Stack
    while (!isQueueEmpty()) {
        push(dequeue());
    }

    // Reset queue
    front = 0;
    rear = -1;

    // Step 2: Stack → Queue
    while (top != -1) {
        enqueue(pop());
    }

    // Print reversed queue
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}
