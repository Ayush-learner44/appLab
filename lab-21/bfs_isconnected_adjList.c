#include <stdlib.h>
#include <stdio.h>

#define Max 10
int visited[Max] = {0};
int queue[Max], front = -1, rear = -1;

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

void addEdge(node *graph[Max], int src, int dest)
{
    node *newNode = createNode(dest);
    newNode->next = graph[src];
    graph[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph[dest];
    graph[dest] = newNode;
}

void enqueue(int vertex)
{
    if (rear == Max - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = vertex;
}

int dequeue()
{
    if (rear == -1 || front > rear)
        return -1;
    return queue[front++];
}

void bfs(node *graph[Max], int start)
{
    int vertex;
    enqueue(start);
    visited[start] = 1;

    while ((vertex = dequeue()) != -1)
    {
        node *temp = graph[vertex];
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

int isConnected(int vertices)
{
    for (int i = 0; i < vertices; i++)
    {
        if (!visited[i])
            return 0;
    }
    return 1;
}

int main()
{
    int n = 4;
    node *adjList[Max] = {NULL};

    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 2);
    addEdge(adjList, 0, 3);
    addEdge(adjList, 1, 2);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 2, 3);

    bfs(adjList, 0);

    if (isConnected(n))
        printf("Graph is connected\n");
    else
        printf("Graph is NOT connected\n");

    return 0;
}