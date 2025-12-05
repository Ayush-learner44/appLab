#include <stdio.h>

#define V 9
#define INF 999999

int minDistance(int visited[V], int dist[V])
{
    int min = INF, minIndex = -1;

    for (int v = 0; v < V; v++)
    {
        if (!visited[v] && dist[v] < min)
        {
            min = dist[v];
            minIndex = v;
        }
    }

    return minIndex;
}

void dijkstra(int graph[V][V], int src)
{
    int visited[V];
    int dist[V];

    for (int i = 0; i < V; i++)
    {
        visited[i] = 0;
        dist[i] = INF;
    }
    dist[src] = 0;
    for (int i = 0; i < V - 1; i++)
    {
        int u = minDistance(visited, dist);
        visited[u] = 1;

        for (int v = 0; v < V; v++)
        {
            if (!visited[v] && graph[u][v] && dist[u] != INF &&
                (graph[u][v] + dist[u] < dist[v]))
                dist[v] = graph[u][v] + dist[u];
        }
    }

    for (int i = 0; i < V; i++)
    {
        printf("The distance of vertex %d from %d is %d \n", src, i, dist[i]);
    }
}

int main()
{
    int graph[V][V] = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}};

    dijkstra(graph, 0);
    return 0;
}