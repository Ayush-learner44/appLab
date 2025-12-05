#include <stdio.h>

#define INF 99999
#define V 5

int dist[V][V];

void floydwarshall(int graph[V][V])
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            dist[i][j] = graph[i][j];
        }
    }

    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (dist[i][k] != INF && dist[k][j] != INF &&
                    (dist[i][k] + dist[k][j]) < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
                printf(" INF ");
            else
                printf(" %d ", dist[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int graph[V][V] = {
        {0, 3, 8, INF, INF},
        {INF, 0, INF, 1, 7},
        {INF, INF, 0, 4, INF},
        {INF, INF, INF, 0, 2},
        {INF, INF, INF, INF, 0}};
    floydwarshall(graph);
    return 0;
}