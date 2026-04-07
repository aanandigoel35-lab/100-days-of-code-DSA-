#include <stdio.h>

#define MAX 100

int main() {
    int queue[MAX];
    int front = 0, rear = -1, size = 0;

    int n;
    scanf("%d", &n);

    // Enqueue n elements
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        rear = (rear + 1) % MAX;
        queue[rear] = x;
        size++;
    }

    int m;
    scanf("%d", &m);

    // Dequeue m elements
    for (int i = 0; i < m; i++) {
        if (size > 0) {
            front = (front + 1) % MAX;
            size--;
        }
    }

    // Print remaining elements
    for (int i = 0; i < size; i++) {
        printf("%d ", queue[(front + i) % MAX]);
    }

    return 0;
}
