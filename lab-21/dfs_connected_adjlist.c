#include <stdio.h>
#include <stdlib.h>

#define Max 10

int visited[Max] = {0};

typedef struct Node
{
    int vertex;
    struct Node *next;
} node;

node *createNode(int v)
{
    node *newNode = malloc(sizeof(node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

int isConnected(int vertices)
{

    for (int i = 0; i < vertices; i++)
    {
        if (!visited[i])
            return 0;
    }
    return 1;
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

void dfs(node *graph[Max], int start)
{
    visited[start] = 1;

    node *temp = graph[start];

    while (temp)
    {
        if (!visited[temp->vertex])
            dfs(graph, temp->vertex);
        temp = temp->next;
    }
}

int main()
{
    int vertices = 4;

    node *graph[Max] = {NULL};
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 3, 4);

    dfs(graph, 0);

    if (isConnected(vertices))
        printf("Graph is connected\n");
    else
        printf("Graph is NOT connected\n");

    return 0;
}