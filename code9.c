#include <stdio.h>
#define MAX 100

int adj[MAX][MAX];
int visited[MAX];

int queue[MAX];
int front = 0, rear = 0;

// Check if queue is empty
int isEmpty() {
    return front == rear;
}

// Check if queue is full
int isFull() {
    return rear == MAX;
}

// Add element to queue (enqueue)
void enqueue(int x) {
    if (isFull()) {
        printf("-1\n"); // Queue full
        return;
    }
    queue[rear++] = x;
}

// Remove element from queue (dequeue)
int dequeue() {
    if (isEmpty()) {
        printf("-1\n"); // Queue empty
        return -1;
    }
    return queue[front++];
}

void bfs(int start, int n) {
    enqueue(start);
    visited[start] = 1;

    while (!isEmpty()) {
        int current = dequeue();
        printf("%d ", current);

        for (int i = 0; i < n; i++) {
            if (adj[current][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int n, e, u, v, start;

    scanf("%d", &n);
    scanf("%d", &e);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;
        visited[i] = 0;
    }

    for (int i = 0; i < e; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    scanf("%d", &start);

    bfs(start, n);

    return 0;
}