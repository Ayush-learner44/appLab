#include <stdio.h>

struct Edge
{
    int u, v, w;
};

#define INF 999999

void BellmanFord(struct Edge edges[], int V, int E, int src)
{
    int dist[V];
    for (int i = 0; i < V; i++)
    {
        dist[i] = INF; // FIX: use i instead of V
    }

    dist[src] = 0;

    for (int i = 0; i < V - 1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if (dist[u] != INF && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Negative cycle check
    for (int j = 0; j < E; j++)
    {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if (dist[u] != INF && dist[u] + w < dist[v])
        {
            printf("-ve cycle!!\n");
            return;
        }
    }

    // ✅ Print distances
    for (int i = 0; i < V; i++)
    {
        if (dist[i] == INF)
            printf("Distance of vertex %d from source %d is INF\n", i, src);
        else
            printf("Distance of vertex %d from source %d is %d\n", i, src, dist[i]);
    }
}

int main()
{
    int V = 10; // number of vertices
    int E = 18; // number of edges

    struct Edge edges[] = {
        {0, 1, 5}, {0, 2, 3}, {1, 3, 6}, {1, 2, 2}, {2, 4, 4}, {2, 5, 2}, {2, 3, 7}, {3, 4, -1}, {4, 5, 2}, {5, 3, 1}, {6, 7, 3}, {7, 8, -4}, {8, 9, 2}, {9, 6, 1}, {1, 6, 10}, {4, 7, 8}, {5, 8, 5}, {3, 9, 4}};

    BellmanFord(edges, V, E, 0); // source = 0
    return 0;
}
