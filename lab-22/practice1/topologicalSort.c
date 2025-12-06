#include <stdio.h>
#include <stdlib.h>

#define V 4
#define Max 100

int stack[Max], top = -1;

int visited[V] = {0};

typedef struct Node
{
    int vertex;
    struct Node *next;
} node;

node *createNode(int v)
{
    node *newNode = malloc(sizeof(node));
    newNode->next = NULL;
    newNode->vertex = v;
    return newNode;
}

void addEdge(node *adjList[], int src, int dest)
{
    node *newNode = createNode(dest);
    newNode->next = adjList[src];
    adjList[src] = newNode;
}

void push(int vertex)
{
    if (top >= Max - 1)
        return;
    stack[++top] = vertex;
}

int pop()
{
    if (top != -1)
        return stack[top--];
    return -1;
}

void topologicalSort(node *adjList[], int start)
{
    visited[start] = 1;

    node *temp = adjList[start];
    while (temp)
    {
        if (!visited[temp->vertex])
            topologicalSort(adjList, temp->vertex);
        temp = temp->next;
    }
    push(start);
}

int main()
{
    node *adjList[V] = {NULL};

    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 2);
    addEdge(adjList, 0, 3);
    addEdge(adjList, 1, 2);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 2, 3);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
            topologicalSort(adjList, i);
    }

    printf("----Topological Sort----\n");

    int j = 0;
    for (int i = 0; i < V; i++)
    {
        if ((j = pop()) != -1)
            printf(" %d", j);
    }

    return 0;
}