#include <stdio.h>
#include <stdlib.h>

#define Max 10

typedef struct Node
{
    int vertex;
    struct Node *next;
} node;

node *createNode(int vertex)
{
    node *newNode = malloc(sizeof(node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

void addEdge(node *graph[Max], int src, int dest)
{
    node *newNode = createNode(dest);
    newNode->next = graph[src];
    graph[src] = newNode;

    // newNode = createNode(src);
    // newNode->next = graph[dest];
    // graph[dest] = newNode;
}

int main()
{
    int vertices;
    node *graph[Max] = {NULL};

    printf("Number of vertices? : ");
    scanf("%d", &vertices);

    // For each source, keep asking destinations until user types -1
    for (int src = 0; src < vertices; src++)
    {
        printf("\nEnter destinations for source %d (type -1 to stop):\n", src);
        while (1)
        {
            int dest;
            printf("Destination? : ");
            scanf("%d", &dest);

            if (dest == -1)
                break; // move to next source
            if (dest < 0 || dest >= vertices)
            {
                printf("Invalid vertex! Try again.\n");
                continue;
            }
            addEdge(graph, src, dest);
        }
    }

    // Display adjacency list
    printf("\nThe Graph (Adjacency List):\n");
    for (int i = 0; i < vertices; i++)
    {
        printf("%d : ", i);
        node *temp = graph[i];
        while (temp)
        {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }

    return 0;
}
