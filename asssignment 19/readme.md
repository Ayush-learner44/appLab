Perfect Ayush 👌 — let’s extend the code you already have (which checks if one tree is a subtree of another) to also handle **Lab 19 Question 2 (check if a tree is a BST)** and **Question 3 (find LCA in a BST)**.  

---

## ✅ Edited Code with Q2 and Q3

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} node;

node* createNode(int key) {
    node* newNode = malloc(sizeof(node));
    newNode->data = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// ---------- Q1: Subtree check ----------
int isSameTree(node* a, node* b) {
    if (!a && !b) return 1;
    if (!a || !b) return 0;
    if (a->data != b->data) return 0;
    return isSameTree(a->left, b->left) && isSameTree(a->right, b->right);
}

int isSubTree(node* T, node* S) {
    if (!S) return 1;
    if (!T) return 0;
    if (isSameTree(T, S)) return 1;
    return isSubTree(T->left, S) || isSubTree(T->right, S);
}

// ---------- Q2: Check if tree is BST ----------
int isBSTUtil(node* root, int* prev) {
    if (!root) return 1;

    if (!isBSTUtil(root->left, prev))
        return 0;

    if (root->data <= *prev)
        return 0;

    *prev = root->data;

    return isBSTUtil(root->right, prev);
}

int isBST(node* root) {
    int prev = -100000; // assume all values > -1e5
    return isBSTUtil(root, &prev);
}

// ---------- Q3: Lowest Common Ancestor in BST ----------
node* LCA(node* root, int n1, int n2) {
    if (!root) return NULL;

    if (root->data > n1 && root->data > n2)
        return LCA(root->left, n1, n2);

    if (root->data < n1 && root->data < n2)
        return LCA(root->right, n1, n2);

    return root; // split point
}

// ---------- Traversal ----------
void inorder(node* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    // Example tree (BST)
    node* root = createNode(26);
    root->left = createNode(10);
    root->right = createNode(30);
    root->left->left = createNode(4);
    root->left->right = createNode(20);

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    // Q2: Check if BST
    if (isBST(root))
        printf("Tree is a BST\n");
    else
        printf("Tree is NOT a BST\n");

    // Q3: Find LCA
    int n1 = 4, n2 = 20;
    node* lca = LCA(root, n1, n2);
    if (lca)
        printf("LCA of %d and %d is %d\n", n1, n2, lca->data);

    return 0;
}
```

---

## 🧪 Example Output

```
Inorder traversal: 4 10 20 26 30
Tree is a BST
LCA of 4 and 20 is 10
```

---

## ⚖️ Summary
- **Q2 (isBST):** Inorder traversal must be strictly increasing.  
- **Q3 (LCA in BST):** Use BST property:  
  - If both nodes < root → go left.  
  - If both nodes > root → go right.  
  - Else root is LCA.  

---

Got you Ayush 👌 — let’s strip this down to **simple dry runs** so you can *see* how the logic works step by step.  

---

# 🔎 Part 1: Check if a Binary Tree is a BST

### Rule
- In a **BST**, **inorder traversal** (Left → Root → Right) must give values in **sorted order**.

### Example Tree (BST)
```
       10
      /  \
     5    20
```

👉 Inorder = `5 10 20` → sorted → ✅ BST.

### Example Tree (Not BST)
```
       10
      /  \
    15    20
```

👉 Inorder = `15 10 20` → not sorted → ❌ Not BST.

### Dry Run
- Start with `prev = -∞`.
- Visit left → `5` > prev → ok, update prev = 5.
- Visit root → `10` > prev → ok, update prev = 10.
- Visit right → `20` > prev → ok, update prev = 20.
- All checks passed → BST.

---

# 🔎 Part 2: Lowest Common Ancestor (LCA) in BST

### Rule
- If both nodes < root → go left.  
- If both nodes > root → go right.  
- Otherwise root is LCA.

### Example BST
```
        20
       /  \
     10    30
    /  \
   5    15
```

👉 Find LCA(5, 15).

### Dry Run
- Root = 20.  
- Both 5 and 15 < 20 → go left.  
- Now root = 10.  
- One node (5) < 10, other (15) > 10 → split happens here.  
- ✅ LCA = 10.

---

### Another Example
👉 Find LCA(5, 30).

- Root = 20.  
- One node (5) < 20, other (30) > 20 → split at root.  
- ✅ LCA = 20.

---

# ⚖️ Summary
- **isBST**: Inorder must be sorted.  
- **LCA in BST**: Walk down from root, split point = LCA.  

---


Ayush 👌 — your code is **almost correct**, but there are two small mistakes that will cause problems:

---

## 🔎 Issues

1. **In `isbst()` check:**
```c
if (root <= *prev)
    return 0;
```
- Here you are comparing the **pointer `root`** with `*prev`.  
- You should compare the **node’s data**:
```c
if (root->data <= *prev)
    return 0;
```

2. **In `binaryCheck()`:**
```c
return isbst(root, prev);
```
- `isbst()` expects a pointer to `prev`, but you are passing the value.  
- Fix:
```c
return isbst(root, &prev);
```

3. **`isbst()` return path:**
- At the end of the function, if everything passes, you should return `1`.  
- Right now, if the last recursive call succeeds, it may return nothing.

---

## ✅ Corrected Functions

```c
int isbst(node *root, int *prev)
{
    if (!root)
        return 1;

    if (!isbst(root->left, prev))
        return 0;

    if (root->data <= *prev)
        return 0;

    *prev = root->data;

    if (!isbst(root->right, prev))
        return 0;

    return 1; // success
}

int binaryCheck(node *root)
{
    int prev = INT_MIN; // use proper minimum
    return isbst(root, &prev);
}
```

---

## 🧪 Dry Run Example

Tree: `{4, 2, 6, 1, 3, 5, 7, 8}`  
- Inorder traversal = `1 2 3 4 5 6 7 8` → sorted → ✅ BST.  
- `binaryCheck(root1)` will return `1`.

LCA(8, 5):  
- Root = 4 → one node (5) > 4, other (8) > 4 → go right.  
- Root = 6 → one node (5) < 6, other (8) > 6 → split here.  
- ✅ LCA = 6.

---

## ⚖️ Summary
- Fix `isbst()` to compare `root->data` not `root`.  
- Pass `&prev` instead of `prev`.  
- Add `return 1` at the end of `isbst()`.  
- Then your program correctly checks BST property and finds LCA.

---

👉 Do you want me to rewrite your **full corrected program** so you can copy-paste and run it directly without patching pieces?
