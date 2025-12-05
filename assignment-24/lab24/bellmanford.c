#include <stdio.h>

#define V 6
#define E 7
#define INF 999999
int dist[V];

typedef struct Edge
{
    int src, dest, wt;
} edge;

void bellmanford(edge edges[E], int src)
{
    for (int i = 0; i < V; i++)
    {
        dist[i] = INF;
    }
    dist[src] = 0;
    for (int vertex = 0; vertex < V - 1; vertex++)
    {
        for (int edge = 0; edge < E; edge++)
        {

            int u = edges[edge].src;
            int v = edges[edge].dest;
            int w = edges[edge].wt;

            if (dist[u] != INF && (dist[u] + w) < dist[v])
                dist[v] = dist[u] + w;
        }
    }

    /// check

    for (int edge = 0; edge < E; edge++)
    {

        int u = edges[edge].src;
        int v = edges[edge].dest;
        int w = edges[edge].wt;

        if (dist[u] != INF && (dist[u] + w) < dist[v])
        {
            dist[v] = dist[u] + w;
            printf("Sorry the graph contains the -ve cycle!!");
            return;
        }
    }

    for (int i = 0; i < V; i++)
    {
        printf("distance of %d to %d is %d\n", src, i, dist[i]);
    }
}
int main()
{
    edge edges[E] = {
        {0, 1, 5},
        {0, 2, 4},
        {1, 3, 3},
        {2, 3, 2},
        {3, 4, 6},
        {4, 5, 2},
        {2, 5, 10}};

    bellmanford(edges, 0);
    return 0;
}