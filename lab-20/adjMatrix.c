#include <stdio.h>

#define V 5 // number of vertices

int main()
{
    int adj[V][V] = {0}; // initialize all to 0

    // Define 6 edges (undirected)
    int edges[6][2] = {
        {0, 1},
        {0, 2},
        {1, 2},
        {1, 3},
        {2, 4},
        {3, 4}};

    // Fill adjacency matrix
    for (int i = 0; i < 6; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    // Display the matrix
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}
