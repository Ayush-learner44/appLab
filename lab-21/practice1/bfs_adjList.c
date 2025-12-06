#include <stdio.h>
#include <stdlib.h>

#define V 7

int queue[V], front = -1, rear = -1, visited[V] = {0};

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

void enqueue(int vertex)
{
    if (rear == V)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = vertex;
}

int dequeue()
{
    if (front == -1 || front > rear)
        return -1;
    return queue[front++];
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

void bfs(node *adjList[V], int start)
{
    enqueue(start);
    visited[start] = 1;

    int vertex;

    while ((vertex = dequeue()) != -1)
    {
        printf("%d ", vertex);

        node *temp = adjList[vertex];

        while (temp)
        {
            if (!visited[temp->vertex])
            {
                enqueue(temp->vertex);
                visited[temp->vertex] = 1;
            }

            temp = temp->next;
        }
    }
}

int main()
{
    node *adjList[V] = {NULL};

    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 4);
    addEdge(adjList, 1, 2);
    addEdge(adjList, 2, 3);
    addEdge(adjList, 2, 4);

    bfs(adjList, 0);
    return 0;
}