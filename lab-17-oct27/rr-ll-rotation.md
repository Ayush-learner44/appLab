Alright Ayush 👊 — let’s go **deep into the rotate functions** and the “preserving” part you’re asking about. This is the subtle bit that makes rotations work, so I’ll break it down pointer by pointer.

---

## 🔎 Why “preserve” subtrees?

When you rotate, you’re moving nodes around. Each node may already have children. If you don’t **preserve** those children, you’d lose them. That’s why in the code you see variables like `T2` — they temporarily hold a subtree so it can be reattached after rotation.

Think of it like rearranging books on a shelf: you can’t just yank one out and shove it somewhere else without remembering what was next to it. `T2` is that “book” you set aside so it doesn’t get lost.

---

## ✅ Right Rotation (LL case)

Code:
```c
Node *rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    // Rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}
```

### Step-by-step:
- `y` is the unbalanced node (too heavy on the left).
- `x = y->left` (the left child that will become new root).
- `T2 = x->right` (the subtree hanging on the right of x).

**Preserve:** `T2` must be remembered, because after rotation it becomes the left child of `y`.

**Rewire:**
- `x->right = y` → move y down to the right of x.
- `y->left = T2` → reattach the preserved subtree.

**Visual:**
Before:
```
    y
   /
  x
   \
    T2
```
After:
```
    x
   / \
  ?   y
     /
    T2
```
(`?` is x’s left child, unchanged.)

---

## ✅ Left Rotation (RR case)

Code:
```c
Node *leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

    // Rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}
```

### Step-by-step:
- `x` is the unbalanced node (too heavy on the right).
- `y = x->right` (the right child that will become new root).
- `T2 = y->left` (the subtree hanging on the left of y).

**Preserve:** `T2` must be remembered, because after rotation it becomes the right child of `x`.

**Rewire:**
- `y->left = x` → move x down to the left of y.
- `x->right = T2` → reattach the preserved subtree.

**Visual:**
Before:
```
  x
   \
    y
   /
  T2
```
After:
```
    y
   / \
  x   ?
   \
    T2
```
(`?` is y’s right child, unchanged.)

---

## 🎯 Why this logic?

- **Preserve subtrees:** Because rotations only rearrange the top two nodes. Any “middle” subtree (like `T2`) must be saved and reattached, otherwise you’d lose part of the tree.
- **Pointer rewiring:** Each rotation is just 2–3 pointer assignments. The preserved subtree is slotted back in the only place it fits without breaking BST ordering.
- **Balance restoration:** After rewiring, heights are recalculated bottom-up, and the subtree is balanced again.

---

## 🧪 Micro dry run (Right Rotation)

Insert 30, 20, 10:
```
    30
   /
  20
 /
10
```

- y=30, x=20, T2=NULL
- x->right = y → 20’s right = 30
- y->left = T2 → 30’s left = NULL

Result:
```
   20
  /  \
10    30
```

Balanced.

---

## 🧪 Micro dry run (Left Rotation)

Insert 10, 20, 30:
```
10
  \
   20
     \
      30
```

- x=10, y=20, T2=NULL
- y->left = x → 20’s left = 10
- x->right = T2 → 10’s right = NULL

Result:
```
   20
  /  \
10    30
```

Balanced.

---

## 🔑 Takeaway

- The “preserve” variables (`T2`) are **temporary holders for middle subtrees** that would otherwise be lost during pointer reassignment.
- Rotations are **local rewiring**: only the unbalanced node, its child, and one preserved subtree are touched.
- The conditions (LL, RR, LR, RL) decide which rotation sequence to apply.

---

👉 Do you want me to annotate the actual C code with inline comments showing **before/after diagrams** for each pointer assignment, so you can literally trace what happens line by line?