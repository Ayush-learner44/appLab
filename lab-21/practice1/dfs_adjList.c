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

void addEdge(node *adjList[], int src, int dest)
{
    node *newNode = createNode(dest);
    newNode->next = adjList[src];
    adjList[src] = newNode;
    newNode = createNode(src);
    newNode->next = adjList[dest];
    adjList[dest] = newNode;
}

void dfs(node *adjList[], int start)
{
    printf(" %d", start);
    visited[start] = 1;

    node *temp = adjList[start];

    while (temp)
    {
        if (!visited[temp->vertex])
            dfs(adjList, temp->vertex);
        temp = temp->next;
    }
}

int isConnected()
{
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == 0)
            return 0;
    }
    return 1;
}

int main()
{
    node *adjList[V] = {NULL};
    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 4);
    addEdge(adjList, 1, 2);
    // addEdge(adjList, 2, 3);
    // addEdge(adjList, 2, 4);
    dfs(adjList, 0);

    if (!isConnected())
        printf("Disconnected!!\n");
    else
        printf("Connected!!!");
    return 0;
}
