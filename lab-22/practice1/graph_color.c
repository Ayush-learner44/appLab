#include <stdio.h>
#include <stdlib.h>

#define Max 100

int Color[Max] = {0};

typedef struct Node
{
    int vertex;
    struct Node *next;
} node;

struct Graph
{
    int vertices;
    struct Node *adjList[Max];
};

node *createNode(int key)
{
    node *newNode = malloc(sizeof(node));
    newNode->next = NULL;
    newNode->vertex = key;
    return newNode;
}

struct Graph *createGraph(int vertices)
{
    struct Graph *g = malloc(sizeof(struct Graph));
    g->vertices = vertices;
    for (int i = 0; i < vertices; i++)
    {
        g->adjList[i] = NULL;
        Color[i] = 0;
    }

    return g;
}

void addEdge(struct Graph *graph, int src, int dest)
{
    node *newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

int dfsColor(struct Graph *graph, int v, int color)
{
    Color[v] = color;
    int neighbourColor = (color == 1) ? 2 : 1;

    node *temp = graph->adjList[v];

    while (temp)
    {
        if (Color[temp->vertex] == 0)
        {
            if (dfsColor(graph, temp->vertex, neighbourColor) == 0)
                return 0;
        }
        else
        {
            if (Color[temp->vertex] == color)
                return 0;
        }
        temp = temp->next;
    }

    return 1;
}
int main()
{
    struct Graph *g = createGraph(3);

    // Triangle cycle
    addEdge(g, 0, 1);
    addEdge(g, 1, 2);
    addEdge(g, 2, 0);

    if (dfsColor(g, 0, 1))
        printf("Graph can be painted with two colors!\n");
    else
        printf("Graph cannot be painted with two colors!\n");

    return 0;
}
