#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Adjacency Matrix
int adjMatrix[MAX][MAX];
int visited[MAX];
int front = -1, rear = -1;
char queue[MAX];
char stack[MAX];
int top = -1;

// Helper function to add edge in the graph
void addEdge(char vertices[], int size, char u, char v) {
    int uIndex = -1, vIndex = -1;
    for (int i = 0; i < size; i++) {
        if (vertices[i] == u) uIndex = i;
        if (vertices[i] == v) vIndex = i;
    }
    adjMatrix[uIndex][vIndex] = 1;
    adjMatrix[vIndex][uIndex] = 1;
}

// BFS function
void BFS(char vertices[], int size, char start) {
    printf("BFS Traversal: ");
    int startIndex = -1;
    
    for (int i = 0; i < size; i++) {
        if (vertices[i] == start) {
            startIndex = i;
            break;
        }
    }

    if (startIndex == -1) {
        printf("Start node not found!\n");
        return;
    }

    front = 0;
    rear = 0;
    queue[rear] = start;
    visited[startIndex] = 1;

    while (front <= rear) {
        char node = queue[front++];
        printf("%c ", node);

        int nodeIndex = -1;
        for (int i = 0; i < size; i++) {
            if (vertices[i] == node) {
                nodeIndex = i;
                break;
            }
        }

        for (int i = 0; i < size; i++) {
            if (adjMatrix[nodeIndex][i] == 1 && !visited[i]) {
                queue[++rear] = vertices[i];
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

// DFS function
void DFS(char vertices[], int size, char start) {
    printf("DFS Traversal: ");
    int startIndex = -1;

    for (int i = 0; i < size; i++) {
        if (vertices[i] == start) {
            startIndex = i;
            break;
        }
    }

    if (startIndex == -1) {
        printf("Start node not found!\n");
        return;
    }

    top = 0;
    stack[top] = start;
    visited[startIndex] = 1;

    while (top >= 0) {
        char node = stack[top--];
        printf("%c ", node);

        int nodeIndex = -1;
        for (int i = 0; i < size; i++) {
            if (vertices[i] == node) {
                nodeIndex = i;
                break;
            }
        }

        for (int i = 0; i < size; i++) {
            if (adjMatrix[nodeIndex][i] == 1 && !visited[i]) {
                stack[++top] = vertices[i];
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

// Reset visited array
void resetVisited(int size) {
    for (int i = 0; i < size; i++) {
        visited[i] = 0;
    }
}

int main() {
    int n, e;
    char u, v, start;
    
    // Input number of nodes
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    char vertices[n];
    
    // Input the vertices
    printf("Enter the vertices (characters): ");
    for (int i = 0; i < n; i++) {
        scanf(" %c", &vertices[i]);
    }
    
    // Input number of edges
    printf("Enter number of edges: ");
    scanf("%d", &e);
    
    // Input edges
    for (int i = 0; i < e; i++) {
        printf("Enter edge (u v): ");
        scanf(" %c %c", &u, &v);
        addEdge(vertices, n, u, v);
    }

    // Input start vertex for BFS and DFS
    printf("Enter start vertex for traversal: ");
    scanf(" %c", &start);

    // BFS Traversal
    resetVisited(n); // reset visited array
    BFS(vertices, n, start);

    // DFS Traversal
    resetVisited(n); // reset visited array
    DFS(vertices, n, start);

    return 0;
}