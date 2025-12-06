#include <stdio.h>
#include <stdlib.h>

#define Max 10

int queue[Max], front = -1, rear = -1;

int visited[Max] = {0};

typedef struct node
{
    int vertex;
    struct node *next;
} Node;

void enqueue(int k)
{
    if (rear == (Max - 1))
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = k;
}

int dequeue()
{
    if (front == -1 || front > rear)
        return -1;
    return queue[front++];
}

Node *createNode(int vertex)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

void addEdge(Node *adjList[Max], int src, int dest)
{
    Node *newNode = createNode(dest);
    newNode->next = adjList[src];
    adjList[src] = newNode;

    newNode = createNode(src);
    newNode->next = adjList[dest];
    adjList[dest] = newNode;
}

void bfs(Node *adjList[Max], int vertices, int start)
{
    enqueue(start);
    visited[start] = 1;

    int vertex;

    while ((vertex = dequeue()) != -1)
    {
        printf("%d ", vertex);
        Node *temp = adjList[vertex];

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
    int n = 4; // number of vertices
    Node *adjList[Max] = {NULL};

    // Hardcoded graph edges
    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 2);
    addEdge(adjList, 1, 3);

    printf("BFS Traversal starting from 0: ");
    bfs(adjList, n, 0);

    return 0;
}
