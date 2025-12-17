Here is your **Binary Search Tree (BST)** exam cheat sheet.

Since this is a standard BST (not self-balancing like AVL), the most important thing to remember for your exam is the difference between **Average Case** (balanced-ish) and **Worst Case** (skewed/linked list).

---

###**Summary of Time Complexities**Here, **h** is the height of the tree.

* **Average Case:** h \approx \log n
* **Worst Case:** h \approx n (This happens if you insert sorted data like 1, 2, 3, 4...).

| Operation | Average Case | Worst Case |
| --- | --- | --- |
| **Search** | O(\log n) | O(n) |
| **Insertion** | O(\log n) | O(n) |
| **Deletion** | O(\log n) | O(n) |
| **Space** | O(n) | O(n) |

---

###**1. Search****Goal:** Find if value `X` exists in the tree.

* **Process:**
1. Start at Root.
2. Compare `X` with current node.
3. **If `X` == Node:** Found it! Stop.
4. **If `X` < Node:** Move **Left**.
5. **If `X` > Node:** Move **Right**.
6. Repeat until found or you hit `NULL` (not found).


* **Complexity Breakdown:**
* **Comparison at each node:** O(1)
* **Number of nodes visited:** You visit one node per level. Max nodes = Height (h).
* **Total:** **O(h)**.



---

###**2. Insertion****Goal:** Add value `X` to the tree at the correct spot.

* **Process:**
1. **Search (O(h)):** Start at Root and move down (Left if smaller, Right if larger) exactly like the Search operation.
2. **Find Spot:** Continue until you hit a `NULL` pointer.
3. **Link (O(1)):** Create the new node and attach it to that `NULL` spot.


* **Complexity Breakdown:**
* **Traversing down:** O(h)
* **Linking pointer:** O(1)
* **Total:** **O(h)**.



---

###**3. Deletion (The Big One)****Goal:** Remove value `X` and keep the tree valid (sorted).

This has **3 Cases** depending on the node you want to delete.

####**Step 1: Search for the node*** **Time:** O(h)
* You must find the node first. If it's not there, you can't delete it.

####**Step 2: Delete (Physical Removal)*** **Time:** O(1) (Pointer changes are instant).

**The 3 Cases Logic:**

* **Case A: Node is a LEAF (No children)**
* **Action:** Just cut it off. Set parent's pointer to `NULL`.
* *Example:* Delete 10 from [5, 10]. Parent (5) now points to nothing.


* **Case B: Node has 1 CHILD**
* **Action:** Cut the node out and link its **Parent** directly to its **Child**.
* *Example:* Delete 10 from [5 -> 10 -> 15]. 5 connects directly to 15.


* **Case C: Node has 2 CHILDREN**
* This is where people fail exams. You cannot just delete the node because it leaves two "orphans."
* **Action:**
1. **Find Inorder Successor:** Go to the **Right Subtree**, then go all the way **Left**. (This is the smallest value that is still bigger than the node you are deleting).
* *Time:* O(h) in worst case.


2. **Copy Value:** Replace the deletion target's **value** with the Successor's value.
* *Time:* O(1).


3. **Delete Successor:** Now call the delete function on the **Successor node** (which is easy because a Successor is guaranteed to have 0 or 1 child).
* *Time:* O(h) to traverse down again.







####**Total Deletion Complexity:**---

###**Quick Exam Recap: AVL vs BST*** **BST:**
* Logic is simple.
* No rotations.
* **Danger:** If data is sorted, it becomes a linked list (O(n)).


* **AVL:**
* Logic is complex (Rotations).
* **Guarantee:** Always balanced (O(\log n)).

---

Here is the **Ultimate Formula Cheat Sheet** for Binary Search Trees (and Binary Trees in general).

**⚠️ CRITICAL EXAM WARNING:**
Check how your professor defines "Height" (h).

* **Convention A (Common):** Height = Number of **edges** from root to deepest leaf. (Root is at height 0).
* **Convention B:** Height = Number of **nodes** on longest path. (Root is at height 1).

*I will give formulas for **Convention A (Root = 0)** because it is the standard in Computer Science. If your exam uses Convention B, just replace h with h-1 in these formulas.*

---

###**1. Nodes (N) vs. Height (h)**####**Max & Min Nodes (Given Height h)*** **Maximum Nodes (Full/Perfect Tree):**



*(e.g., Height 2 \rightarrow 2^3 - 1 = 7 nodes)*
* **Minimum Nodes (Skewed Tree):**



*(Just a linked list)*

####**Max & Min Height (Given Nodes N)*** **Minimum Height (Best Case / Balanced):**



*(This is the complexity of search in best case)*
* **Maximum Height (Worst Case / Skewed):**



*(This is the complexity of search in worst case)*

---

###**2. Level-Based Formulas***(Assume Root is at Level 0)*

* **Max Nodes at Level l:**



*(Level 0 has 1, Level 1 has 2, Level 2 has 4)*
* **Total edges in a tree with N nodes:**



---

###**3. Leaves vs. Internal Nodes***(These specifically apply to a **Full/Strict** Binary Tree, where every node has 0 or 2 children)*

* **Leaf Nodes (L) vs Internal Nodes (I):**



*(If you have 10 internal nodes, you MUST have 11 leaf nodes)*
* **Total Nodes (N) in terms of Leaves (L):**


* **Total Nodes (N) in terms of Internal Nodes (I):**



---

###**4. The "Combinatorics" (Very Common Exam Question)**"How many distinct BSTs can be formed with N unique keys?"

This is the **Catalan Number**. Memorize this.

* N=1 \rightarrow 1 tree
* N=2 \rightarrow 2 trees
* N=3 \rightarrow 5 trees
* N=4 \rightarrow 14 trees

---

###**5. Relationship Cheatsheet**| Property | Formula |
| --- | --- |
| **Sum of nodes at all levels** | \sum_{i=0}^{h} 2^i = 2^{h+1} - 1 |
| **Height of empty tree** | -1 (usually) |
| **Height of tree with 1 node** | 0 |
| **Degree of a node** | Number of children (0, 1, or 2) |
| **Max Degree of BST** | 2 |

---

###**Quick Test for You (Mental Check)**If you have **31 nodes** in a **perfect** BST:

1. What is the height? (h = \lfloor \log_2 31 \rfloor = 4)
2. How many leaves? (In perfect tree: \lceil N/2 \rceil = 16)

---

Here is the **Ultimate Formula Cheat Sheet** for Binary Search Trees (and Binary Trees in general).

**⚠️ CRITICAL EXAM WARNING:**
Check how your professor defines "Height" (h).

* **Convention A (Common):** Height = Number of **edges** from root to deepest leaf. (Root is at height 0).
* **Convention B:** Height = Number of **nodes** on longest path. (Root is at height 1).

*I will give formulas for **Convention A (Root = 0)** because it is the standard in Computer Science. If your exam uses Convention B, just replace h with h-1 in these formulas.*

---

###**1. Nodes (N) vs. Height (h)**####**Max & Min Nodes (Given Height h)*** **Maximum Nodes (Full/Perfect Tree):**



*(e.g., Height 2 \rightarrow 2^3 - 1 = 7 nodes)*
* **Minimum Nodes (Skewed Tree):**



*(Just a linked list)*

####**Max & Min Height (Given Nodes N)*** **Minimum Height (Best Case / Balanced):**



*(This is the complexity of search in best case)*
* **Maximum Height (Worst Case / Skewed):**



*(This is the complexity of search in worst case)*

---

###**2. Level-Based Formulas***(Assume Root is at Level 0)*

* **Max Nodes at Level l:**



*(Level 0 has 1, Level 1 has 2, Level 2 has 4)*
* **Total edges in a tree with N nodes:**



---

###**3. Leaves vs. Internal Nodes***(These specifically apply to a **Full/Strict** Binary Tree, where every node has 0 or 2 children)*

* **Leaf Nodes (L) vs Internal Nodes (I):**



*(If you have 10 internal nodes, you MUST have 11 leaf nodes)*
* **Total Nodes (N) in terms of Leaves (L):**


* **Total Nodes (N) in terms of Internal Nodes (I):**



---

###**4. The "Combinatorics" (Very Common Exam Question)**"How many distinct BSTs can be formed with N unique keys?"

This is the **Catalan Number**. Memorize this.

* N=1 \rightarrow 1 tree
* N=2 \rightarrow 2 trees
* N=3 \rightarrow 5 trees
* N=4 \rightarrow 14 trees

---

###**5. Relationship Cheatsheet**| Property | Formula |
| --- | --- |
| **Sum of nodes at all levels** | \sum_{i=0}^{h} 2^i = 2^{h+1} - 1 |
| **Height of empty tree** | -1 (usually) |
| **Height of tree with 1 node** | 0 |
| **Degree of a node** | Number of children (0, 1, or 2) |
| **Max Degree of BST** | 2 |

---

###**Quick Test for You (Mental Check)**If you have **31 nodes** in a **perfect** BST:

1. What is the height? (h = \lfloor \log_2 31 \rfloor = 4)
2. How many leaves? (In perfect tree: \lceil N/2 \rceil = 16)

Ready for the next topic, or is that everything?