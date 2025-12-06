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

void addEdge(node *adjList[Max], int src, int dest)
{
    node *newNode = createNode(dest);
    newNode->next = adjList[src];
    adjList[src] = newNode;

    newNode = createNode(src);
    newNode->next = adjList[dest];
    adjList[dest] = newNode;
}

void dfs(node *adjList[Max], int start)
{
    printf("%d ", start);
    visited[start] = 1;

    node *temp = adjList[start];

    while (temp)
    {
        if (!visited[temp->vertex])
        {
            dfs(adjList, temp->vertex);
        }
        temp = temp->next;
    }
}
int main()
{
    int vertices = 4;

    node *adjList[Max] = {NULL};

    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 2);
    addEdge(adjList, 1, 3);

    printf("DFS Traversal (List): ");
    dfs(adjList, 0);

    return 0;
}