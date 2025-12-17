Here is the sharp, exam-ready summary of the "Big 3" Shortest Path Algorithms.

---

###**1. Dijkstra's Algorithm*** **What is it?** Single-Source Shortest Path (One node \to All others).
* **Technique:** **Greedy** (Always picks the closest known node next).
* **Constraint:** Works **ONLY** on non-negative edge weights.
* **Short Working:**
1. Set distance to source = 0, all others = \infty.
2. Put source in a **Min-Priority Queue (Min-Heap)**.
3. While the queue is not empty:
* Extract the node with the smallest distance (u).
* Check all its neighbors (v).
* If going through u is shorter than the current path to v, **update** v and add it to the queue.




* **Most Important Line (Relaxation):**
```python
if dist[u] + weight(u, v) < dist[v]:
    dist[v] = dist[u] + weight(u, v)
    # Push v to Priority Queue

```



---

###**2. Bellman-Ford Algorithm*** **What is it?** Single-Source Shortest Path.
* **Technique:** **Dynamic Programming** (Bottom-up approach).
* **Constraint:** Works with **Negative Weights**. Can detect Negative Cycles.
* **Short Working:**
1. Set distance to source = 0, all others = \infty.
2. **Brute Force Loop:** Repeat V-1 times:
* Iterate through **EVERY edge** (u, v) in the graph.
* Try to relax the edge.


3. **Cycle Check:** Run one more time. If any distance still decreases, there is a "Negative Weight Cycle" (you can loop forever getting smaller costs).


* **Most Important Line (Run V-1 times):**
```python
# Does exactly the same math as Dijkstra, but loops blindly
if dist[u] + weight(u, v) < dist[v]:
    dist[v] = dist[u] + weight(u, v)

```



---

###**3. Floyd-Warshall Algorithm*** **What is it?** **All-Pairs Shortest Path** (From Every Node \to Every Other Node).
* **Technique:** **Dynamic Programming** (3 Nested Loops).
* **Constraint:** Works with negative weights (but no negative cycles).
* **Short Working:**
1. Create a 2D Matrix `D[V][V]` where `D[i][j]` is the weight of edge i \to j.
2. Pick an intermediate node k.
3. Ask: "Is it faster to go from i to j directly, or via k (i \to k \to j)?"
4. Repeat this for every possible intermediate node k (from 0 to V-1).


* **Most Important Line (The Update):**
```python
# The core recurrence relation
dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

```



---

###**Quick Comparison Table**| Algorithm | Type | Strategy | Time Complexity | Best Use Case |
| --- | --- | --- | --- | --- |
| **Dijkstra** | 1 to All | Greedy + Heap | **O(E \log V)** | Google Maps (Standard pathfinding) |
| **Bellman-Ford** | 1 to All | DP (Iterative) | **O(VE)** | Financial arbitrage (handling negatives) |
| **Floyd-Warshall** | All to All | DP (3 Loops) | **O(V^3)** | Dense graphs where you need complete routing tables |

**Would you like me to clarify Hashing (Open Addressing vs Chaining) or Sorting complexities next to wrap up your review?**