#include <stdio.h>

#define MAX 20

int graph[MAX][MAX];
int visited[MAX];
int n;

void bfs(int start) {
    int queue[MAX];
    int front = 0, rear = 0;
    int i, current;

    visited[start] = 1;
    queue[rear++] = start;

    printf("BFS Traversal: ");

    while (front < rear) {
        current = queue[front++];
        printf("%d ", current);

        for (i = 0; i < n; i++) {
            if (graph[current][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }

    printf("\n");
}

int main() {
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    if (start < 0 || start >= n) {
        printf("Invalid starting vertex\n");
        return 0;
    }

    bfs(start);

    return 0;
}

/*
Test Case 1 - Connected Graph:

Input:
5
0 1 1 0 0
1 0 1 1 0
1 1 0 0 1
0 1 0 0 1
0 0 1 1 0
Starting vertex: 0

Output:
BFS Traversal: 0 1 2 3 4


Test Case 2 - Partially Connected Graph:

Input:
5
0 1 0 0 0
1 0 1 0 0
0 1 0 0 0
0 0 0 0 1
0 0 0 1 0
Starting vertex: 0

Output:
BFS Traversal: 0 1 2

Vertices 3 and 4 are not connected to the starting vertex.
The visited[] array prevents a vertex from being processed twice.
*/