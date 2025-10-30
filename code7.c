// 7. Implement Linear Queue ADT using an array
#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

// Add element to queue
void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("-1\n"); // Queue full
        return;
    }
    if (front == -1) {
        front = 0;      // First element entry
    }
    queue[++rear] = value;
}

// Remove element from queue
void dequeue() {
    if (front == -1 || front > rear) {
        printf("-1\n"); // Queue empty
        return;
    }
    front++; // Move front forward
}

// Display queue elements
void display() {
    if (front == -1 || front > rear) {
        printf("-1\n"); // Queue empty
        return;
    }
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;
    do {
        // Menu input: 1 = enqueue, 2 = dequeue, 3 = display, 4 = exit
        scanf("%d", &choice);
        switch (choice) {
            case 1: 
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                break;
            default:
                printf("-1\n"); // Invalid choice
        }
    } while (choice != 4);
    return 0;
}