// 8. Implement Graph Traversal techniques: Depth First Search
#include <stdio.h>
#define MAX 100

int graph[MAX][MAX];   // Adjacency matrix
int visited[MAX];      // Track visited nodes
int n;                 // Number of vertices

// DFS function
void dfs(int vertex) {
    visited[vertex] = 1;     // Mark vertex as visited
    printf("%d ", vertex);   // Print current vertex

    for (int i = 0; i < n; i++) {
        // If edge exists AND neighbor is not visited
        if (graph[vertex][i] == 1 && visited[i] == 0) {
            dfs(i);          // Visit next connected vertex
        }
    }
}

int main() {
    scanf("%d", &n);   // Input number of vertices

    // Input adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int start;
    scanf("%d", &start); // Input starting vertex

    // Initialize visited array
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    dfs(start); // Start DFS

    return 0;
}