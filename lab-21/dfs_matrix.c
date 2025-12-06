#include <stdio.h>
#include <stdlib.h>

#define Max 10

int visited[Max] = {0};

void dfs(int adj[Max][Max], int vertices, int start)
{
    printf("%d ", start);
    visited[start] = 1;

    for (int i = 0; i < vertices; i++)
    {
        if (adj[start][i] == 1 && !visited[i])
        {
            dfs(adj, vertices, i);
        }
    }
}

int main()
{
    int n = 4;
    int adj[Max][Max] = {
        {0, 1, 1, 0}, // 0 → 1, 0 → 2
        {1, 0, 0, 1}, // 1 → 0, 1 → 3
        {1, 0, 0, 0}, // 2 → 0
        {0, 1, 0, 0}  // 3 → 1
    };

    printf("DFS Traversal (Matrix): ");
    dfs(adj, n, 0);

    return 0;
}