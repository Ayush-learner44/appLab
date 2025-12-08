Here is the logic breakdown for the two parts of Lab 17. The key difference between a normal Binary Search Tree (BST) and an AVL tree is that the AVL tree code must **self-balance** after every insertion.

### Part 1: Logic for AVL Tree Creation (Insertion & Rotation)

The code for Question 1 revolves around the `insert` function. Unlike a standard BST insertion which just adds a leaf and stops, the AVL `insert` function has to "unwind" (go back up the tree) to fix imbalances.

**1. The Node Structure**
The data structure needs an extra field compared to a normal BST: `height`.

```c
struct Node {
    int key;
    struct Node *left;
    struct Node *right;
    int height; // Critical for checking balance
};
```

**2. The Insertion Logic (Recursive)**
The function follows these 3 sequential steps:

  * **Step A: Standard BST Insert.** Recursively find the correct spot (Left if `key < root->key`, Right if `key > root->key`) and place the new node.
  * **Step B: Update Height.** As the recursion returns (moves back up from the leaf to the root), update the height of *every* ancestor node visited.
    $$Height = 1 + \max(Height(Left), Height(Right))$$
  * **Step C: Check Balance Factor.** Calculate the balance for the current node:
    $$Balance = Height(Left) - Height(Right)$$
      * If the Balance is $> 1$ or $< -1$, the tree is unbalanced at this node.

**3. The Rotation Logic (The "Fix")**
If an imbalance is found in Step C, the code must perform one of 4 rotations based on where the new key was inserted relative to the unbalanced node:

  * **Case 1: Left-Left (LL)**
      * *Condition:* Balance $> 1$ and New Key $<$ Left Child's Key.
      * *Fix:* Perform **Right Rotate**.
  * **Case 2: Right-Right (RR)**
      * *Condition:* Balance $< -1$ and New Key $>$ Right Child's Key.
      * *Fix:* Perform **Left Rotate**.
  * **Case 3: Left-Right (LR)**
      * *Condition:* Balance $> 1$ and New Key $>$ Left Child's Key.
      * *Fix:* **Left Rotate** the child, then **Right Rotate** the current node.
  * **Case 4: Right-Left (RL)**
      * *Condition:* Balance $< -1$ and New Key $<$ Right Child's Key.
      * *Fix:* **Right Rotate** the child, then **Left Rotate** the current node.

-----

### Part 2: Logic for Traversal with Balance Factor

The code for Question 2 is simpler. It requires traversing the tree you built in Part 1 and calculating the balance factor on the fly.

**1. Traversal Logic**
You can use any standard traversal (Inorder is best because it prints sorted output).

  * **Logic:** `Go Left` $\rightarrow$ `Process Node` $\rightarrow$ `Go Right`.

**2. Calculating Balance Factor on Output**
Inside the print statement of your traversal, you don't just print `root->key`. You call a helper function to get the height difference.

  * **Helper Logic:**
      * If `root` is NULL, return 0.
      * Calculate `h_left = height(root->left)`.
      * Calculate `h_right = height(root->right)`.
      * Print: `(h_left - h_right)`.

**Visualizing the Output Logic:**
Your `inOrder` function will look effectively like this:

```c
void inOrder(struct Node *root) {
    if(root != NULL) {
        inOrder(root->left); // 1. Go Left

        // 2. Process Node: Print Data AND Balance Factor
        int bf = height(root->left) - height(root->right);
        printf("Node: %d (BF: %d)\n", root->key, bf);

        inOrder(root->right); // 3. Go Right
    }
}
```

### Summary of what happens with your specific data:

For the input `50, 10, 20...`

1.  **50, 10, 20**: This creates a "Left-Right" imbalance at 50. The code will rotate 10 left, then 50 right. 20 becomes the new root of this subplot.
2.  **...90, 80**: This creates a "Right-Left" imbalance. The code will rotate 90 right, then the parent left.

Would you like me to generate the full **C code** for this solution so you can run it directly?