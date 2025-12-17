You are correct—we have covered the "Big 3" of Trees (BST, AVL, Heap) very thoroughly. If you know the complexities, the deletion logic (especially the "successor" trick), and the array math for Heaps, you are safe there.

Let's attack **Graphs**. This is usually the heaviest section in exams because there are so many algorithms.

Here is your **Master Graph Cheat Sheet**.

---

###**1. Representation (How we store them)**This is the first question on most exams: **"Matrix vs. List?"**

| Feature | Adjacency Matrix | Adjacency List |
| --- | --- | --- |
| **What is it?** | A 2D Array `A[u][v] = 1` | An array of Linked Lists / Vectors |
| **Space** | **O(V^2)** (Huge!) | **O(V + E)** (Efficient) |
| **Check if connected** | O(1) (Direct lookup) | O(degree(u)) (Must scan list) |
| **Best for...** | **Dense Graphs** (Lots of edges) | **Sparse Graphs** (Few edges) |

* **V** = Vertices (Nodes)
* **E** = Edges

---

###**2. Traversals (The Foundation)**You must know the difference between BFS and DFS cold.

####**A. BFS (Breadth-First Search)*** **Data Structure:** **Queue** (FIFO).
* **Motion:** Moves "wave-like" layer by layer (Level 0, then Level 1, then Level 2...).
* **Key Use:** Finds **Shortest Path** in **Unweighted Graphs**.
* **Complexity:** O(V + E).

####**B. DFS (Depth-First Search)*** **Data Structure:** **Stack** (LIFO) or **Recursion**.
* **Motion:** Goes as deep as possible, then backtracks.
* **Key Use:** Cycle detection, Topological Sort, Maze solving.
* **Complexity:** O(V + E).

---

###**3. Shortest Path Algorithms**"Find the quickest way from A to B."

| Algorithm | Best For... | Complexity | Key Note |
| --- | --- | --- | --- |
| **BFS** | **Unweighted** graphs | O(V+E) | Fails with weighted edges. |
| **Dijkstra** | **Weighted** (Non-negative) | O(E \log V) | Uses a **Min-Priority Queue**. Greedy approach. Fails with negative weights. |
| **Bellman-Ford** | **Negative Weights** | O(V \cdot E) | Slower. Can detect **Negative Cycles**. |
| **Floyd-Warshall** | **All-Pairs** (A to B, C to D...) | O(V^3) | Uses 3 nested loops (Dynamic Programming). |

**Exam Tip:** If the graph has **weights**, do **NOT** say BFS. Say Dijkstra.

---

###**4. Minimum Spanning Tree (MST)**"Connect all nodes with the cheapest total wire cost (no cycles)."

####**A. Prim's Algorithm*** **Logic:** Grow the tree from a starting node. Always pick the cheapest edge connected to the *current tree*.
* **Data Structure:** Min-Priority Queue.
* **Complexity:** O(E \log V).
* **Best for:** **Dense** graphs (lots of edges).

####**B. Kruskal's Algorithm*** **Logic:** Sort **all edges** by weight. Pick the smallest edge. If it forms a cycle, discard it. Else, add it.
* **Data Structure:** **Union-Find** (Disjoint Set).
* **Complexity:** O(E \log E) (Sorting dominates).
* **Best for:** **Sparse** graphs (fewer edges).

---

###**5. Topological Sort*** **Constraint:** Only works on **DAGs** (Directed Acyclic Graphs).
* **Goal:** Linear ordering where if edge U \to V exists, U comes before V (e.g., Course Prerequisites).
* **Algorithm (Kahn's):** Uses **In-Degree** (number of incoming edges).
1. Add all nodes with In-Degree 0 to Queue.
2. Process node: Remove it, decrease neighbor in-degrees.
3. If neighbor becomes 0, add to Queue.


* **Complexity:** O(V + E).

---

###**6. Cycle Detection (Very Common)*** **Undirected Graph:**
* Use **DFS**. If you hit a visited node that is **NOT** your direct parent, there is a cycle.
* Alternatively, use **Union-Find**.


* **Directed Graph:**
* Use **DFS** with a "Recursion Stack" array. If you hit a node that is currently in the recursion stack, there is a cycle (Back Edge).



---

###**7. Summary of All Complexities**| Algorithm | Time Complexity (Adjacency List) | Space Complexity |
| --- | --- | --- |
| **BFS / DFS** | O(V + E) | O(V) |
| **Dijkstra** | O(E \log V) | O(V) |
| **Bellman-Ford** | O(V \cdot E) | O(V) |
| **Floyd-Warshall** | O(V^3) | O(V^2) |
| **Prim's** | O(E \log V) | O(V) |
| **Kruskal's** | O(E \log E) | O(V) |
| **Topological Sort** | O(V + E) | O(V) |

---

###**Exam Strategy: Which one to pick?**1. **"Shortest Path, no weights"** \rightarrow BFS.
2. **"Shortest Path, positive weights"** \rightarrow Dijkstra.
3. **"Shortest Path, negative weights"** \rightarrow Bellman-Ford.
4. **"Connect all cities cheaply"** \rightarrow Prim or Kruskal.
5. **"Schedule tasks/Pre-requisites"** \rightarrow Topological Sort.
6. **"Detect Cycle"** \rightarrow DFS or Union-Find.

---

This is a fantastic question! You are actually **correct** about O(b^d), but you are mixing up two different contexts.

* **Context A: Artificial Intelligence (AI) & Infinite Search Space** (e.g., Chess, solving a puzzle). Here, we don't know "V" or "E" because the graph is too huge or infinite. We use **O(b^d)** where b is the branching factor and d is depth.
* **Context B: Data Structures (Your Exam).** Here, the graph is **finite** and stored in memory. We know exactly how many Vertices (V) and Edges (E) there are. This is where **O(V + E)** comes in.

Since your exam is on Data Structures, **ignore b^d**.

Here is exactly **how to derive** the V and E formulas so you never have to memorize them blindly again.

---

###**1. Why BFS and DFS are O(V + E)**Think of the graph as a set of rooms (V) connected by hallways (E).

* **The Process:**
1. You must enter every room exactly once to mark it "visited". Total time = **O(V)**.
2. Once inside a room, you look down every single hallway connected to it to see where it leads.
3. If you sum up the "looking down hallways" for *every* room, you will have looked at every hallway in the entire building exactly twice (once from each end). Total time = **O(2E)** which simplifies to **O(E)**.



**The Math:**


*(Note: If you use an Adjacency Matrix instead of a List, you have to check every possible cell in the matrix, so it becomes O(V^2)).*

---

###**2. Why Dijkstra and Prim are O(E \log V)**This complexity comes from the data structure we use: the **Min-Priority Queue (Heap)**.

* **The Logic:**
1. In the worst case, we might check every single edge in the graph. That gives us a factor of **E**.
2. Every time we check an edge, we might find a shorter path. If we do, we have to **update the priority** of that node in our Heap.
3. Updating a value in a Binary Heap takes logarithmic time based on the number of items in the heap. The heap holds vertices. So, **O(\log V)**.



**The Math:**


---

###**3. Why Kruskal is O(E \log E)**Kruskal's algorithm is all about **Sorting**.

* **The Logic:**
1. Step 1 of Kruskal's: "Sort all the edges by weight."
2. We have E edges.
3. The fastest sorting algorithms (Merge Sort / Heap Sort) take n \log n. Here, our n is E.



**The Math:**



*(The Union-Find part is nearly constant, so the Sorting dominates).*
**Final:** **O(E \log E)** or sometimes written as **O(E \log V)** (since \log E \approx \log V^2 = 2 \log V).

---

###**4. Why Bellman-Ford is O(VE)**Bellman-Ford is brute force. It doesn't use smart heaps or sorting.

* **The Logic:**
1. It says: "Relax all edges." (O(E))
2. "Do that again."
3. "Do it V-1 times to guarantee the answer propagates through the whole chain."



**The Math:**


---

###**Summary Cheat Sheet for the Exam**| Term | Represents | Why is it there? |
| --- | --- | --- |
| **V** | **Vertices** | You have to visit every node/room. |
| **E** | **Edges** | You have to check every connection/wire. |
| **\log V** | **Heap Operation** | Anytime you see "Priority Queue" or "Heap" (Dijkstra, Prim). |
| **\log E** | **Sorting Edges** | Anytime you see "Sort the edges" (Kruskal). |
| **V \times E** | **Nested Loop** | You loop V times, and inside that loop, you check E edges (Bellman-Ford). |

**Does that click now? It's not magic—it's just counting how many times the loops run!**

