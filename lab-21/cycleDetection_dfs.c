#include <stdio.h>
#include <stdlib.h>

#define Max 10

int visited[Max] = {0};

typedef struct Node
{
    int vertex;
    struct Node *next;
} node;

node *createNode(int vertex)
{
    node *newNode = malloc(sizeof(node));
    newNode->next = NULL;
    newNode->vertex = vertex;
    return newNode;
}

void addEdge(node *graph[Max], int src, int dest)
{
    node *newNode = createNode(dest);
    newNode->next = graph[src];
    graph[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph[dest];
    graph[dest] = newNode;
}

int dfsCycle(node *graph[Max], int v, int parent)
{
    visited[v] = 1;

    node *temp = graph[v];

    while (temp)
    {
        int u = temp->vertex;

        if (!visited[u])
        {
            if (dfsCycle(graph, u, v))
                return 1;
        }
        else
        {
            if (u != parent)
                return 1;
        }
        temp = temp->next;
    }
    return 0;
}

void hasCycle(node *graph[Max], int vertices)
{
    for (int i = 0; i < vertices; i++)
        visited[i] = 0;
    for (int v = 0; v < vertices; v++)
    {
        if (!visited[v])
        {
            if (dfsCycle(graph, v, -1))
            {
                printf("Graph has Cycle!!\n");
                return;
            }
        }
    }
    printf("Graph doesn't contain cycle!!!\n");
}

int main()
{
    node *adjList[Max] = {NULL};
    int vertices = 5;

    addEdge(adjList, 0, 1);
    addEdge(adjList, 1, 2);
    addEdge(adjList, 3, 4);

    hasCycle(adjList, vertices);
    return 0;
}