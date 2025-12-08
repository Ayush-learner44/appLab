Perfectly put, Ayush 👌 — you’ve described **two classic Minimum Spanning Tree (MST) algorithms**:

---

## 🔎 Algorithm 1
> *“We start with any vertex and always pick the edge with the minimum weight unless it forms a cycle.”*

👉 This is **Prim’s Algorithm**.  
- Works like Dijkstra’s but for MST.  
- Grows the tree one edge at a time, always choosing the smallest edge that connects a new vertex to the growing tree.  
- Cycle check is implicit because it only adds edges that connect to new vertices.

---

## 🔎 Algorithm 2
> *“We arrange the edges in ascending order and then keep picking the edges one by one from min to max… if that edge forms a cycle discard it.”*

👉 This is **Kruskal’s Algorithm**.  
- Sorts all edges by weight.  
- Iteratively adds the smallest edge that doesn’t form a cycle (using Union-Find/Disjoint Set to check).  
- Explicit cycle check is required.

---

## 📊 Quick Comparison

| Feature              | Prim’s Algorithm                  | Kruskal’s Algorithm              |
|----------------------|-----------------------------------|----------------------------------|
| Approach             | Vertex-based (grow from a node)   | Edge-based (sort all edges)      |
| Cycle Handling       | Implicit (only add new vertices)  | Explicit (Union-Find check)      |
| Data Structure       | Priority Queue / Min Heap         | Disjoint Set (Union-Find)        |
| Best for             | Dense graphs                     | Sparse graphs                    |
| Complexity           | O(E log V) with heap              | O(E log E) with sorting          |

---

✅ So:  
- **Prim’s** = start at a vertex, pick min edge to expand tree.  
- **Kruskal’s** = sort edges, pick smallest one by one, discard cycles.  

---

Do you want me to also give you **dry run examples** of both on the same graph (say 5–6 vertices) so you can narrate them in viva?