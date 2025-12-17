This code is a standard implementation of **Cycle Detection in an Undirected Graph** using DFS.

###**The Core Logic (The "Magic" Line)**The most important logic is inside the `else` block:
`if (u != parent) return 1;`

* **Meaning:** "I just bumped into a neighbor `u` that I have **already visited**. If this neighbor `u` is **NOT** the parent I just came from, then I must have found a *different* way to reach `u`. That means there is a loop/cycle."

---

###**Dry Run Example**Let's trace this with a simple **Triangle Graph**: 3 nodes (0, 1, 2) all connected.

* **Edges:** `0-1`, `1-2`, `2-0`
* **Cycle:** 0 \rightarrow 1 \rightarrow 2 \rightarrow 0

**Initial State:**

* `visited` array = `[0, 0, 0]`
* We start the search from **Node 0** with parent **-1** (no parent).

####**Step 1: `dfsCycle(graph, 0, -1)**`* **Action:** Mark `visited[0] = 1`.
* **Neighbors of 0:** `1`, `2`.
* **Loop 1 (Neighbor 1):**
* `u = 1`.
* Is `visited[1]` true? **No**.
* **Action:** Recurse! Call `dfsCycle(graph, 1, 0)`.
* *(We pause execution here and go deeper)*



####**Step 2: `dfsCycle(graph, 1, 0)**`* **Current Node:** `v = 1`, `parent = 0`.
* **Action:** Mark `visited[1] = 1`.
* **Neighbors of 1:** `0`, `2`.
* **Loop 1 (Neighbor 0):**
* `u = 0`.
* Is `visited[0]` true? **Yes**.
* **Check:** `if (u != parent)` \rightarrow `if (0 != 0)`? **False**.
* *Explanation:* We just came from 0. Seeing 0 again is normal in an undirected graph (0-1 is the same as 1-0). Ignore it.


* **Loop 2 (Neighbor 2):**
* `temp` moves to next. `u = 2`.
* Is `visited[2]` true? **No**.
* **Action:** Recurse! Call `dfsCycle(graph, 2, 1)`.



####**Step 3: `dfsCycle(graph, 2, 1)**`* **Current Node:** `v = 2`, `parent = 1`.
* **Action:** Mark `visited[2] = 1`.
* **Neighbors of 2:** `1`, `0`.
* **Loop 1 (Neighbor 1):**
* `u = 1`.
* Is `visited[1]` true? **Yes**.
* **Check:** `if (u != parent)` \rightarrow `if (1 != 1)`? **False**.
* *Explanation:* 1 is our parent. Ignore.


* **Loop 2 (Neighbor 0):**
* `temp` moves to next. `u = 0`.
* Is `visited[0]` true? **Yes**.
* **Check:** `if (u != parent)` \rightarrow `if (0 != 1)`? **TRUE!**
* *Explanation:* We found Node 0 again! We came from 1, but we see 0. Since 0 is already visited and it is **not** the node we just came from, we found a "back edge." This completes the circle.


* **Action:** `return 1` (Cycle Found).

####**Step 4: Unwinding the Stack*** **Back to Step 2:** The function receives `1`. It returns `1`.
* **Back to Step 1:** The function receives `1`. It returns `1`.
* **Final Result:** `1` (True, cycle exists).

---

###**Visualizing the "Back Edge"**Think of the recursion stack as a path you are walking:

1. Start at **0**.
2. Walk to **1** (Parent: 0).
3. Walk to **2** (Parent: 1).
4. From **2**, you look ahead and see **0**.
* Is 0 visited? **Yes** (we started there).
* Is 0 your parent? **No** (your parent is 1).
* **Conclusion:** You found a "back door" to the start. That's a cycle.



###**Exam Summary for this Code*** **Time Complexity:** O(V + E) (Standard DFS).
* **Space Complexity:** O(V) (Recursion stack).
* **Crucial Condition:** `visited[u] && u != parent`.
* If you remove `u != parent`, the code breaks because it will think going back and forth along the same edge (A \leftrightarrow B) is a cycle.



Does this dry run clarify *exactly* how the logic catches the cycle?