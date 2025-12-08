#include <stdio.h>
#include <stdlib.h>

#define V 5
#define Max 100
int queue[Max], front = -1, rear = -1, top = -1;
int visited[V] = {0};
int stack[Max];

void enqueue(int key)
{
    if (rear >= Max - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = key;
}

int dequeue()
{
    if (front > rear || rear == -1)
        return -1;
    return queue[front++];
}

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

void addEdge(node *graph[], int src, int dest)
{
    node *newNode = createNode(dest);
    newNode->next = graph[src];
    graph[src] = newNode;
    // newNode = createNode(src);
    // newNode->next = graph[dest];
    // graph[dest] = newNode;
}

void bfs(node *graph[], int start)
{
    visited[start] = 1;
    enqueue(start);

    int vertex;

    while ((vertex = dequeue()) != -1)
    {
        printf("%d ", vertex);
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

void dfs(node *adjList[], int start)
{
    visited[start] = 1;
    printf("%d ", start);

    node *temp = adjList[start];

    while (temp)
    {
        if (!visited[temp->vertex])
            dfs(adjList, temp->vertex);
        temp = temp->next;
    }
}

void push(int key)
{
    if (top >= Max - 1)
        return;
    stack[++top] = key;
}

int pop()
{
    if (top == -1)
        return -1;
    return stack[top--];
}

void topologicalSortUtil(node *graph[], int start)
{
    visited[start] = 1;

    node *temp = graph[start];

    while (temp)
    {
        if (!visited[temp->vertex])
            topologicalSortUtil(graph, temp->vertex);
        temp = temp->next;
    }
    push(start);
}

void topologicalSort(node *graph[])
{
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
            topologicalSortUtil(graph, i);
    }

    // Now pop and print once
    while (top != -1)
    {
        printf("%d ", pop());
    }
}
void resetVisited()
{
    for (int i = 0; i < V; i++)
    {
        visited[i] = 0;
    }
    front = rear = -1; // also reset queue pointers for BFS
}

int main()
{
    node *graph[V] = {NULL};

    // Build sample graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);

    printf("\nTopological Sort!\n");
    resetVisited();
    topologicalSort(graph);

    return 0;
}
