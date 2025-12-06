#include <stdio.h>

#define Max 10

int queue[Max], front = -1, rear = -1;
int visited[Max] = {0};

void enqueue(int k)
{
    if (rear >= Max - 1)
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

void bfs(int adj[Max][Max], int n, int start)
{

    int vertex;

    enqueue(start);
    visited[start] = 1;

    while ((vertex = dequeue()) != -1)
    {
        printf("%d ", vertex);
        for (int i = 0; i < n; i++)
        {
            if (adj[vertex][i] == 1 && !visited[i])
            {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main()
{
    int n = 4; // number of vertices
    int adj[Max][Max] = {
        {0, 1, 1, 0}, // connections of vertex 0
        {1, 0, 0, 1}, // connections of vertex 1
        {1, 0, 0, 0}, // connections of vertex 2
        {0, 1, 0, 0}  // connections of vertex 3
    };

    printf("Bfs traversal\n");

    bfs(adj, n, 0);

    return 0;
}