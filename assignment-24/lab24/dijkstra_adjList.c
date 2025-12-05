#include <stdio.h>
#include <stdlib.h>

#define V 9
#define INF 99999

struct Node
{
    int vertex;
    int weight;
    struct Node *next;
};

struct Node *createNode(int vertex, int wt)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->next = NULL;
    newNode->vertex = vertex;
    newNode->weight = wt;

    return newNode;
}

void addEdge(struct Node *graph[V], int src, int dest, int wt)
{
    struct Node *newNode = createNode(dest, wt);
    newNode->next = graph[src];
    graph[src] = newNode;
    newNode = createNode(src, wt);
    newNode->next = graph[dest];
    graph[dest] = newNode;
}

int minDistance(int dist[V], int vis[V])
{
    int min = INF, minIndex = -1;

    for (int i = 0; i < V; i++)
    {
        if (!vis[i] && dist[i] < min)
        {
            min = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void dijkstra(struct Node *graph[V], int src)
{
    int visited[V];
    int distance[V];

    for (int i = 0; i < V; i++)
    {
        visited[i] = 0;
        distance[i] = INF;
    }
    distance[src] = 0;

    for (int i = 0; i < V - 1; i++)
    {
        int u = minDistance(distance, visited);
        visited[u] = 1;

        struct Node *temp = graph[u];

        while (temp)
        {
            int v = temp->vertex;
            int wt = temp->weight;

            if (!visited[v] && distance[u] != INF && (distance[u] + wt) < distance[v])
                distance[v] = distance[u] + wt;

            temp = temp->next;
        }
    }

    for (int i = 0; i < V; i++)
    {
        if (distance[i] == INF)
            printf(" distace of the %d from the %d is INF \n", src, i);
        else
            printf(" distace of the %d from the %d is %d \n", src, i, distance[i]);
    }
}

int main()
{
    struct Node *graph[V] = {NULL};

    addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 7, 8);
    addEdge(graph, 1, 2, 8);
    addEdge(graph, 1, 7, 11);
    addEdge(graph, 2, 3, 7);
    addEdge(graph, 2, 8, 2);
    addEdge(graph, 2, 5, 4);
    addEdge(graph, 3, 4, 9);
    addEdge(graph, 3, 5, 14);
    addEdge(graph, 4, 5, 10);
    addEdge(graph, 5, 6, 2);
    addEdge(graph, 6, 7, 1);
    addEdge(graph, 6, 8, 6);
    addEdge(graph, 7, 8, 7);

    dijkstra(graph, 3);
    return 0;
}