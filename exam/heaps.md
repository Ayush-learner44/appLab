Here is your **Heap (Binary Heap) Exam Cheat Sheet**.

Heaps are the backbone of **Priority Queues** and **Heapsort**. The most important concept to grasp is that a Heap is a tree implemented as an **Array**.

---

###**1. The Two Types*** **Max-Heap:** Parent \ge Children. Root is the **Maximum**.
* **Min-Heap:** Parent \le Children. Root is the **Minimum**.

*(I will explain everything using a **Max-Heap** for consistency. For Min-Heap, just reverse the logic).*

---

###**2. Array Representation (Formulas)**Heaps are **Complete Binary Trees** (filled level-by-level, left-to-right), so we store them in an array to save space (no pointers needed!).

**For a node at index `i` (0-based indexing):**

| Relation | Formula (0-based) | Formula (1-based) |
| --- | --- | --- |
| **Parent** | \lfloor \frac{i-1}{2} \rfloor | \lfloor \frac{i}{2} \rfloor |
| **Left Child** | 2i + 1 | 2i |
| **Right Child** | 2i + 2 | 2i + 1 |

---

###**3. Complexity Summary**| Operation | Time Complexity | Why? |
| --- | --- | --- |
| **Get Max/Min (Peek)** | **O(1)** | It's always at `arr[0]`. |
| **Insert** | **O(\log n)** | You might have to swap up to the root. |
| **Delete Max/Min** | **O(\log n)** | You have to swap down to a leaf. |
| **Heapify (One Node)** | **O(\log n)** | Maintenance operation on a subtree. |
| **Build Heap (Array \to Heap)** | **O(n)** | **CRITICAL:** It is linear time, not n \log n. |
| **Heapsort** | **O(n \log n)** | Build (O(n)) + n deletions (O(n \log n)). |

---

###**4. Key Operations & Processes**####**A. Insertion (`push`)****Goal:** Add a new element while maintaining the Heap Property.

1. **Place:** Put the new element at the **very end** of the array (bottom-left most empty spot).
2. **Heapify Up (Bubble Up):** Compare the new node with its **Parent**.
* If Child > Parent: **Swap** them.
* Repeat until Parent > Child or you reach the Root.



####**B. Deletion (`pop` / `extract-max`)****Goal:** Remove the Root (the max element) and fix the hole.

1. **Replace:** Take the element at the **very end** of the array (last leaf) and move it to the **Root**.
2. **Remove:** Delete the last element (which is now empty/duplicate).
3. **Heapify Down (Sink Down):** Compare the new Root with its **Children**.
* Find the **larger** of the two children.
* If Parent < Larger Child: **Swap**.
* Repeat until Parent is larger than both children or you hit a leaf.



---

###**5. The "Heapify" Function (The Exam Favorite)**There is a massive confusion between "Heapify" and "Build Heap".

* **`heapify(i)`**: A function that assumes the subtrees of node `i` are already heaps, but node `i` itself might be out of place. It "floats" node `i` down to its correct spot.
* **Time:** O(\log n) (Height of tree).


* **`BuildHeap(arr)`**: Converts a random array into a valid Heap.
* **Process:** You **do not** iterate from the start. You iterate **backwards** starting from the last **non-leaf node** up to the root, calling `heapify(i)` on each.
* **Start Index:** \lfloor \frac{n}{2} \rfloor - 1 (Last non-leaf node).
* **Loop:** `for (int i = n/2 - 1; i >= 0; i--) { heapify(i); }`



**Why is Build Heap O(n) and not O(n \log n)?**
This is a standard proof question.

* Most nodes are at the bottom (leaves). You don't touch them.
* Nodes just above leaves only move down 1 step.
* Only the root moves down \log n steps.
* Mathematically, the sum of "heights" converges to linear time O(n).

---

###**6. Heapsort****Process:**

1. **Build Max Heap** from the array: O(n).
2. **Sort Loop:**
* Swap `arr[0]` (Max) with `arr[end]`.
* Reduce heap size by 1 (ignore the sorted element at the end).
* Call `heapify(0)` to fix the root.
* Repeat n times.
* **Total Time:** O(n \log n).
* **Space:** O(1) (In-place sorting).



---

###**7. Formula Cheat Sheet*** **Height of Heap:** h = \lfloor \log_2 n \rfloor
* **Number of Leaves:** \lceil \frac{n}{2} \rceil (Indices from \lfloor \frac{n}{2} \rfloor to n-1).
* **Number of Internal Nodes:** \lfloor \frac{n}{2} \rfloor.
* **Last Non-Leaf Node Index:** \lfloor \frac{n}{2} \rfloor - 1 (This is where you start the Build Heap loop!).

---

###**8. Quick Comparison****Heap vs. BST:**

* **BST:** Sorted order (Left < Root < Right). Searching is O(\log n).
* **Heap:** Vertical order (Parent > Child). Left and Right are **not** sorted relative to each other. Searching is **O(n)** (you have to scan the whole array).

**Ready to move on to Graphs or Hashing, or do you need a specific example of Heapify?**

---

# **Build Heap**

Here is a clear, step-by-step Dry Run of **Build Heap** using the **Heapify** operation.

We will build a **Max-Heap**.

###**The Input****Array:** `[4, 10, 3, 5, 1]`
**Tree View:**

```text
      4
    /   \
  10     3
 /  \
5    1

```

*Indices:*

* `0`: 4
* `1`: 10
* `2`: 3
* `3`: 5
* `4`: 1

---

###**The Process: Build Heap****Formula for Start Point:**
We start at the **last non-leaf node** and work backwards to the root (index 0).


So, we run `Heapify` on **Index 1**, then on **Index 0**.

---

###**Step 1: Heapify(Index 1)*** **Current Node:** `Arr[1] = 10`
* **Left Child:** `Arr[3] = 5`
* **Right Child:** `Arr[4] = 1`

**Comparison:**
Is `10` smaller than `5`? No.
Is `10` smaller than `1`? No.
10 is already larger than its children. **No Swap.**

**Array State:** `[4, 10, 3, 5, 1]` (No change)

---

###**Step 2: Heapify(Index 0)*** **Current Node:** `Arr[0] = 4`
* **Left Child:** `Arr[1] = 10`
* **Right Child:** `Arr[2] = 3`

**Comparison:**
Who is the largest among {4, 10, 3}?
\rightarrow **10** is the largest.

**Action:** Swap `Arr[0]` (4) with `Arr[1]` (10).

**Array State:** `[10, 4, 3, 5, 1]`
**Tree View Now:**

```text
      10
    /    \
   4      3
 /   \
5     1

```

**CRITICAL STEP (The Ripple Effect):**
Because we moved `4` down to Index 1, we must **re-check (recurse)** on Index 1 to make sure it didn't break the heap property below it.

---

###**Step 2.1: Recursive Heapify(Index 1)***(We are checking the node we just swapped)*

* **Current Node:** `Arr[1] = 4`
* **Left Child:** `Arr[3] = 5`
* **Right Child:** `Arr[4] = 1`

**Comparison:**
Who is the largest among {4, 5, 1}?
\rightarrow **5** is the largest.

**Action:** Swap `Arr[1]` (4) with `Arr[3]` (5).

**Array State:** `[10, 5, 3, 4, 1]`
**Tree View Now:**

```text
      10
    /    \
   5      3
 /   \
4     1

```

**Check Next:** We moved `4` to Index 3. Does Index 3 have children?
No (Indices 7, 8 don't exist). **Stop.**

---

###**Final Result**The array `[10, 5, 3, 4, 1]` is now a valid Max-Heap.

###**Summary of Logic for Exam**1. **Identify Start:** Always calculate `n/2 - 1`.
2. **Loop Backwards:** Go from that index down to 0.
3. **Heapify Logic:**
* Compare Parent vs Left vs Right.
* Pick Largest.
* If Parent is NOT largest \rightarrow **Swap** & **Repeat** on the child position you just swapped into.

