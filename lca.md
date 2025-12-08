Great question Ayush 👌 — the **Least Common Ancestor (LCA)** problem is a classic in trees and comes up often in viva/exams. Let’s break it down clearly.

---

## 🔎 What is LCA?
- In a **binary tree**, the **Least Common Ancestor (LCA)** of two nodes `u` and `v` is the **lowest (deepest) node** that has both `u` and `v` as descendants.
- Example:

```
        4
       / \
      2   6
     / \ / \
    1  3 5  7
```

- LCA(1, 3) = 2  
- LCA(1, 7) = 4  
- LCA(5, 7) = 6  

---

## ✅ Method 1: Recursive Approach (Binary Tree)

```c
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* LCA(struct Node* root, int n1, int n2) {
    if (root == NULL) return NULL;

    // If either n1 or n2 is the root, root is LCA
    if (root->data == n1 || root->data == n2)
        return root;

    // Search left and right subtrees
    struct Node* leftLCA = LCA(root->left, n1, n2);
    struct Node* rightLCA = LCA(root->right, n1, n2);

    // If both sides return non-null, root is LCA
    if (leftLCA && rightLCA)
        return root;

    // Otherwise return whichever side is non-null
    return (leftLCA != NULL) ? leftLCA : rightLCA;
}
```

👉 Works for **any binary tree**.

---

## ✅ Method 2: BST Property (Faster for BSTs)

If the tree is a **Binary Search Tree (BST)**:
- If both nodes are smaller than root → LCA is in left subtree.
- If both are larger than root → LCA is in right subtree.
- Otherwise root is LCA.

```c
struct Node* LCA_BST(struct Node* root, int n1, int n2) {
    if (!root) return NULL;

    if (root->data > n1 && root->data > n2)
        return LCA_BST(root->left, n1, n2);

    if (root->data < n1 && root->data < n2)
        return LCA_BST(root->right, n1, n2);

    return root; // split point
}
```

👉 Much faster: O(h), where h = height of tree.

---

## 🔎 Time & Space Complexity
- **Recursive Binary Tree LCA:** O(n) time, O(h) space (stack).
- **BST LCA:** O(h) time, O(1) space.
- With advanced preprocessing (Binary Lifting / Euler Tour + RMQ), LCA can be answered in O(1) after O(n log n) preprocessing — but that’s beyond Lab 15 scope.

---

## ⚖️ Summary
- **General Binary Tree:** use recursive DFS approach.  
- **BST:** use property of BST to find split point.  
- LCA is the lowest node that has both target nodes in its subtree.

---

👉 Do you want me to show you a **dry run example in C** with your Lab 15 BST (nodes 1–7) so you can narrate step-by-step how LCA is found during viva?