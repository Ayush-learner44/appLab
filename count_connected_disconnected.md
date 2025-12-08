Perfect viva-style question Ayush 👌 — let’s break it down clearly and give you a **C program template** to count connected and disconnected components in a graph.

---

# 📘 Counting Connected & Disconnected Components in a Graph (C)

---

## 🔎 Idea
- Represent graph using **adjacency list** or **adjacency matrix**.
- Use **DFS (Depth First Search)** or **BFS (Breadth First Search)** to explore nodes.
- Keep a `visited[]` array.
- For each unvisited node:
  - Run DFS/BFS → marks all nodes in that connected component.
  - Increment `componentCount`.
- At the end:
  - `componentCount` = number of connected components.
  - If `componentCount > 1` → graph is disconnected.

---

## ✅ C Code (Adjacency List + DFS)

```c
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int visited[MAX];
int adj[MAX][MAX]; // adjacency matrix

void dfs(int v, int n) {
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[v][i] && !visited[i]) {
            dfs(i, n);
        }
    }
}

int main() {
    int n, e;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);

    // initialize adjacency matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    printf("Enter edges (u v):\n");
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; // undirected graph
    }

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    int componentCount = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, n);
            componentCount++;
        }
    }

    printf("Number of connected components: %d\n", componentCount);
    if (componentCount == 1)
        printf("Graph is connected\n");
    else
        printf("Graph is disconnected\n");

    return 0;
}
```

---

## 🧪 Example Run

Input:
```
Vertices = 5
Edges = 3
Edges: 
0 1
1 2
3 4
```

Output:
```
Number of connected components: 2
Graph is disconnected
```

---

## ⚖️ Summary
- Use DFS/BFS to explore graph.
- Count how many times you start a new DFS → that’s the number of connected components.
- If count = 1 → connected, else disconnected.

---

👉 Do you want me to also show you the **BFS version** (queue-based) so you can compare both approaches side by side for viva prep?