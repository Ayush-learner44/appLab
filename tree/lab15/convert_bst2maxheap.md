**Lab 15 Question 5 asks you to convert a Binary Search Tree (BST) into a Max Heap. The key idea is: use an inorder traversal to collect sorted values, then overwrite the BST using postorder traversal to build the Max Heap.**

---

## 🔎 Goal: Convert BST → Max Heap

### ✅ Properties to satisfy:
- **Max Heap**: Every parent node ≥ its children.
- **Tree structure remains the same** (don’t change links).
- **Node values are rearranged** to satisfy Max Heap.

---

## 🧩 Step-by-Step Process

### 1. **Inorder Traversal** of BST
- Collect all node values in **ascending order**.
- This gives a sorted array of values.

### 2. **Postorder Traversal** of BST
- Visit left → right → root.
- Replace each node’s value with the **last unused value** from the sorted array (starting from the largest).
- This ensures **Max Heap property**: children are filled before parent.

---

## 🧪 Example BST (from your assignment)

```
        4
       / \
      2   6
     / \ / \
    1  3 5  7
```

### Inorder traversal:
```
[1, 2, 3, 4, 5, 6, 7]
```

### Postorder traversal:
```
1 → 3 → 2 → 5 → 7 → 6 → 4
```

### Assign values in reverse:
```
Assign 7 → 1  
Assign 6 → 3  
Assign 5 → 2  
Assign 4 → 5  
Assign 3 → 7  
Assign 2 → 6  
Assign 1 → 4
```

### Final Max Heap:
```
        4
       / \
      6   7
     / \ / \
    1  3 2  5
```

---

## ✅ C Code Skeleton

```c
int idx = 0;

void inorder(struct Node* root, int arr[]) {
    if (!root) return;
    inorder(root->left, arr);
    arr[idx++] = root->data;
    inorder(root->right, arr);
}

void postorderAssign(struct Node* root, int arr[]) {
    if (!root) return;
    postorderAssign(root->left, arr);
    postorderAssign(root->right, arr);
    root->data = arr[idx--];
}

void convertBSTtoMaxHeap(struct Node* root) {
    int arr[100]; // assuming max 100 nodes
    idx = 0;
    inorder(root, arr);     // fill sorted values
    idx--;                  // point to last element
    postorderAssign(root, arr);
}
```

---

## ⚖️ Summary
- **Inorder** → get sorted values.
- **Postorder** → assign values from largest to smallest.
- Result: same tree structure, but values now satisfy Max Heap.

---

I can also plug this into a full runnable C program with tree creation and traversal if you want to test it live.