#include <stdio.h>

#define MAX 20
#define INF 9999

void dijkstra(int graph[MAX][MAX], int n, int source) {
    int distance[MAX], visited[MAX];
    int i, j, min, next;

    for (i = 0; i < n; i++) {
        distance[i] = graph[source][i];
        visited[i] = 0;
    }

    distance[source] = 0;
    visited[source] = 1;

    for (i = 1; i < n; i++) {
        min = INF;
        next = -1;

        for (j = 0; j < n; j++) {
            if (visited[j] == 0 && distance[j] < min) {
                min = distance[j];
                next = j;
            }
        }

        if (next == -1)
            break;

        visited[next] = 1;

        for (j = 0; j < n; j++) {
            if (visited[j] == 0 &&
                graph[next][j] != INF &&
                distance[next] + graph[next][j] < distance[j]) {
                distance[j] = distance[next] + graph[next][j];
            }
        }
    }

    printf("\nShortest distances from vertex %d:\n", source);

    for (i = 0; i < n; i++) {
        if (distance[i] == INF)
            printf("Vertex %d -> No path\n", i);
        else
            printf("Vertex %d -> %d\n", i, distance[i]);
    }
}

int main() {
    int graph[MAX][MAX];
    int n, source;
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter weighted adjacency matrix:\n");
    printf("(Enter 9999 for no direct road)\n");

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter source vertex: ");
    scanf("%d", &source);

    if (source < 0 || source >= n) {
        printf("Invalid source vertex\n");
        return 0;
    }

    dijkstra(graph, n, source);

    return 0;
}

/*
Output:

Enter number of vertices: 5

Enter weighted adjacency matrix:
0 10 9999 30 100
10 0 50 9999 9999
9999 50 0 20 10
30 9999 20 0 60
100 9999 10 60 0

Enter source vertex: 0

Shortest distances from vertex 0:
Vertex 0 -> 0
Vertex 1 -> 10
Vertex 2 -> 50
Vertex 3 -> 30
Vertex 4 -> 60
*/