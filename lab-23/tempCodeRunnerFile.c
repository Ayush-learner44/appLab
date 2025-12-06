#include <stdio.h>
#include <stdlib.h>

typedef struct Edge
{
    int src, dest, wt;
} edge;

int cmp(const void *a, const void *b)
{
    return ((edge *)a)->wt - ((edge *)b)->wt;
}

int find(int parent[], int i)
{
    if (parent[i] != i)
        parent[i] = find(parent, i);
    return parent[i];
}

void unionFind(int parent[], int rank[], int u, int v)
{
    int uRoot = find(parent, u);
    int vRoot = find(parent, v);

    if (rank[uRoot] < rank[vRoot])
    {
        parent[uRoot] = vRoot;
    }
    else if (rank[uRoot] > rank[vRoot])
    {
        parent[vRoot] = uRoot;
    }
    else
    {
        parent[vRoot] = uRoot;
        rank[vRoot]++;
    }
}

void krushkal(edge edges[], int V, int E)
{
    qsort(edges, E, sizeof(edge), cmp);

    int parent[V], rank[V];

    for (int i = 0; i < V; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }

    int mstWeight = 0;
    printf("Edges in the MST\n");

    for (int i = 0; i < E; i++)
    {
        int u = edges[i].src;
        int v = edges[i].dest;
        int wt = edges[i].wt;

        int setU = find(parent, u);
        int setV = find(parent, v);

        if (setU != setV)
        {
            printf("%d--%d = %d\n", u, v, wt);
            mstWeight += wt;
            unionFind(parent, rank, u, v);
        }
    }

    printf("Total Weight : %d\n", mstWeight);
}

int main()
{
    int E = 5, V = 4;
    edge edges[] = {
        {0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}};
    krushkal(edges, V, E);
    return 0;
}