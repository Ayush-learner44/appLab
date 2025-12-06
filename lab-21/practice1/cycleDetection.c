#include <stdio.h>
#include <stdlib.h>

#define V 5

int visited[V] = {0};

typedef struct Node
{
    int vertex;
    struct Node *next;
} node;

node *createNode(int key)
{
    node *newNode = malloc(sizeof(node));
    newNode->next = NULL;
    newNode->vertex = key;
    return newNode;
}

void addEdge(node *adjList[V], int src, int dest)
{
    node *newNode = createNode(dest);
    newNode->next = adjList[src];
    adjList[src] = newNode;
    newNode = createNode(src);
    newNode->next = adjList[dest];
    adjList[dest] = newNode;
}

int dfsCycle(node *adjList[], int v, int parent)
{
    visited[v] = 1;

    node *temp = adjList[v];

    while (temp)
    {
        int u = temp->vertex;

        if (!visited[u])
        {
            if (dfsCycle(adjList, u, v))
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

void hasCycle(node *adjList[])
{
    for (int i = 0; i < V; i++)
    {
        if (dfsCycle(adjList, i, -1))
        {
            printf("Yes the graph contains Cycle!!!");
            return;
        }
    }
    printf("No cycle exist!!");
}

int main()
{
    node *adjList[V] = {NULL};

    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 4);
    addEdge(adjList, 1, 2);
    addEdge(adjList, 2, 3);
    addEdge(adjList, 2, 4);

    hasCycle(adjList);

    return 0;
}
