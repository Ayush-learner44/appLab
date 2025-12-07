Here is your **Lab 13 Exam Cheat Sheet**. It is designed for you to look at 5 minutes before the test and instantly recall the logic.

Each section contains the **Question**, the **Core Logic (The "Trick")**, and the **Code Skeleton** you need to memorize.

-----

### **1. Find Level of an Element**

**Question:** For a given binary tree, write a program to find the level for the user-given element (root is level 0).

  * **⚡ The Logic:**
      * It is a **Search** operation.
      * You must carry a `level` variable **down** with you in the recursion.
      * Increment `level + 1` every time you go deeper.
  * **⚠️ The Gotcha:** When you find the node, return `level`, **NOT** `0` or `1`. If not found, return `-1`.
  * **📝 Quick Code:**
    ```c
    int findLevel(node *root, char target, int level) {
        if (!root) return -1;
        if (root->data == target) return level; // Found it!

        int left = findLevel(root->left, target, level + 1);
        if (left != -1) return left; // Found in left side

        return findLevel(root->right, target, level + 1); // Check right side
    }
    ```

-----

### **2. Level-Order Traversal**

**Question:** Write a program to traverse the tree using level-order traversing (BFS).

  * **⚡ The Logic:**
      * **Recursion won't work.** You need a **QUEUE**.
      * **FIFO (First-In, First-Out):** Put Root in $\rightarrow$ Take Root out & Print $\rightarrow$ Put Children in.
  * **⚠️ The Gotcha:** Your Queue array must store `node*` (pointers), **NOT** `char` or `int`. If you store chars, you lose the links to children.
  * **📝 Quick Code:**
    ```c
    void levelOrder(node *root) {
        enqueue(root);
        while (!isEmpty()) {
            node *temp = dequeue(); // 1. Get front
            printf("%c ", temp->data); // 2. Print

            if (temp->left) enqueue(temp->left);   // 3. Queue Left
            if (temp->right) enqueue(temp->right); // 4. Queue Right
        }
    }
    ```

-----

### **3. Count Nodes (Total, External, Internal)**

**Question:** Count the total number of nodes, internal nodes, and external nodes.

  * **⚡ The Logic:**
      * **Total:** `1 + count(left) + count(right)`.
      * **External (Leaf):** If `!left && !right` return `1`.
      * **Internal:** Just calculate `Total - External` in `main()`. Don't write a separate function.
  * **⚠️ The Gotcha:** Base case for recursion is always `if (!root) return 0`.
  * **📝 Quick Code:**
    ```c
    int countTotal(node *root) {
        if (!root) return 0;
        return 1 + countTotal(root->left) + countTotal(root->right);
    }

    int countLeaves(node *root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 1; // It's a leaf
        return countLeaves(root->left) + countLeaves(root->right);
    }
    // Main: int internal = total - leaves;
    ```

-----

### **4. Mirror Image**

**Question:** Create a binary tree that is a mirror image of the given binary tree.

  * **⚡ The Logic:**
      * **Swap Children.**
      * You must mirror the subtrees **before** (or after) you swap the pointers at the current node.
      * Think: `Left` becomes `Right`, `Right` becomes `Left`.
  * **⚠️ The Gotcha:** Don't lose the pointers\! Use temporary variables or just assign the recursive result directly.
  * **📝 Quick Code:**
    ```c
    node* mirror(node* root) {
        if (!root) return NULL;

        node* leftMirror = mirror(root->left);   // Recurse first
        node* rightMirror = mirror(root->right);

        root->left = rightMirror; // Swap!
        root->right = leftMirror;
        return root;
    }
    ```

-----

### **5. Build Tree from Preorder & Inorder**

**Question:** Create a binary tree from preorder and inorder traversal given by the user.

  * **⚡ The Logic:**
      * **Preorder** tells you **WHO** is the Root (First element).
      * **Inorder** tells you **WHERE** the Left and Right subtrees are (Left of Root vs Right of Root).
      * You need a global/static `preIndex` to walk through the Preorder array.
  * **⚠️ The Gotcha:** Pass `(len - 1)` as the end index in `main`, not `len`. Remember `search()` finds the index in **Inorder**.
  * **📝 Quick Code:**
    ```c
    // Global: int preIndex = 0;
    node* build(char in[], char pre[], int start, int end) {
        if (start > end) return NULL;

        node* root = createNode(pre[preIndex++]); // 1. Pick root from Pre
        if (start == end) return root;

        int split = search(in, start, end, root->data); // 2. Find split in In

        root->left = build(in, pre, start, split - 1); // 3. Build Left
        root->right = build(in, pre, split + 1, end);  // 4. Build Right
        return root;
    }
    ```

-----

### **6. Check Strict Binary Tree**

**Question:** Check whether the given binary tree is a strict binary tree or not.

  * **⚡ The Logic:**
      * **Strict** = 0 Children OR 2 Children.
      * **Bad** = Exactly 1 Child.
      * The condition is: If (Left is NULL **OR** Right is NULL) it fails... **UNLESS** both are NULL.
  * **⚠️ The Gotcha:** Don't forget to check subtrees recursively\! `return strict(left) && strict(right)`.
  * **📝 Quick Code:**
    ```c
    int isStrict(node *root) {
        if (!root) return 1; // Empty is valid
        
        // Leaf is valid
        if (!root->left && !root->right) return 1; 

        // If one is missing but not the other -> INVALID
        if (!root->left || !root->right) return 0; 

        // Check children
        return isStrict(root->left) && isStrict(root->right);
    }
    ```

-----

**Next Step:** Would you like to do a quick "rapid fire" where I give you a tree scenario and you tell me which logic applies?