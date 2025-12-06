#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

// Number of vertices in the graph (matching your previous example)
#define V 4

// A utility function to find the vertex with the minimum key value,
// from the set of vertices not yet included in MST
int minKey(int key[], bool mstSet[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

// Function to print the constructed MST stored in parent[]
void printMST(int parent[], int graph[V][V])
{
    printf("Edges in the MST (Prim's):\n");
    int mstWeight = 0;
    for (int i = 1; i < V; i++) // Start from 1 because 0 is the root
    {
        printf("%d--%d = %d\n", parent[i], i, graph[i][parent[i]]);
        mstWeight += graph[i][parent[i]];
    }
    printf("Total Weight : %d\n", mstWeight);
}

// Function to construct and print MST for a graph represented using adjacency matrix
void primMST(int graph[V][V])
{
    int parent[V];  // Array to store constructed MST
    int key[V];     // Key values used to pick minimum weight edge
    bool mstSet[V]; // To represent set of vertices included in MST

    // Initialize all keys as INFINITE and mstSet[] as false
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    // Always include first 1st vertex in MST.
    key[0] = 0;     // Make key 0 so that this vertex is picked as first vertex
    parent[0] = -1; // First node is always root of MST

    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++)
    {
        // Pick the minimum key vertex from the set of vertices NOT yet in MST
        int u = minKey(key, mstSet);

        // Add the picked vertex to the MST Set
        mstSet[u] = true;

        // Update key value and parent index of the adjacent vertices of the picked vertex.
        // Consider only those vertices which are not yet included in MST
        for (int v = 0; v < V; v++)
        {
            // graph[u][v] is non zero only for adjacent vertices of m
            // mstSet[v] is false for vertices not yet included in MST
            // Update the key only if graph[u][v] is smaller than key[v]
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph);
}

int main()
{
    // Using the same graph data as your Kruskal example
    // 0--1 (10), 0--2 (6), 0--3 (5), 1--3 (15), 2--3 (4)
    int graph[V][V] = {
        {0, 10, 6, 5},
        {10, 0, 0, 15},
        {6, 0, 0, 4},
        {5, 15, 4, 0}};

    primMST(graph);

    return 0;
}