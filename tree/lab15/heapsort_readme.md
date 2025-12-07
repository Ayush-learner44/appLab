Absolutely Ayush 👌 — let’s dry run **Heap Sort using Min Heap** step by step so you can see exactly how it works.

---

## 🧩 Input Array
```
[50, 10, 20, 30, 5, 90, 80, 100, 85]
```

Goal: Sort this in **descending order** using Min Heap.

---

## 🔁 Step 1: Build Min Heap

We apply `heapifyMin()` bottom-up from index `n/2 - 1 = 3`.

Final Min Heap:
```
[5, 10, 20, 30, 50, 90, 80, 100, 85]
```

Tree form:
```
        5
       / \
     10   20
    / \   / \
  30 50 90 80
 / \
100 85
```

---

## 🔁 Step 2: Heap Sort Loop

We repeatedly:
- Swap root (min) with last element.
- Reduce heap size.
- Heapify root.

### 🔹 i = 8
Swap `arr[0]` and `arr[8]` → `[85, 10, 20, 30, 50, 90, 80, 100, 5]`  
Heapify `arr[0]` in size 8 → becomes `[10, 30, 20, 85, 50, 90, 80, 100, 5]`

### 🔹 i = 7
Swap `arr[0]` and `arr[7]` → `[100, 30, 20, 85, 50, 90, 80, 10, 5]`  
Heapify → `[20, 30, 100, 85, 50, 90, 80, 10, 5]`

### 🔹 i = 6
Swap `arr[0]` and `arr[6]` → `[80, 30, 100, 85, 50, 90, 20, 10, 5]`  
Heapify → `[30, 50, 100, 85, 80, 90, 20, 10, 5]`

### 🔹 i = 5
Swap `arr[0]` and `arr[5]` → `[90, 50, 100, 85, 80, 30, 20, 10, 5]`  
Heapify → `[50, 80, 100, 85, 90, 30, 20, 10, 5]`

### 🔹 i = 4
Swap `arr[0]` and `arr[4]` → `[90, 80, 100, 85, 50, 30, 20, 10, 5]`  
Heapify → `[80, 85, 100, 90, 50, 30, 20, 10, 5]`

### 🔹 i = 3
Swap `arr[0]` and `arr[3]` → `[90, 85, 100, 80, 50, 30, 20, 10, 5]`  
Heapify → `[85, 90, 100, 80, 50, 30, 20, 10, 5]`

### 🔹 i = 2
Swap `arr[0]` and `arr[2]` → `[100, 90, 85, 80, 50, 30, 20, 10, 5]`  
Heapify → `[90, 100, 85, 80, 50, 30, 20, 10, 5]`

### 🔹 i = 1
Swap `arr[0]` and `arr[1]` → `[100, 90, 85, 80, 50, 30, 20, 10, 5]`  
Done.

---

## ✅ Final Sorted Array (Descending)
```
[100, 90, 85, 80, 50, 30, 20, 10, 5]
```

---

## ⚖️ Summary
- Build Min Heap → root is smallest.
- Repeatedly extract root and heapify → smallest elements bubble to the end.
- Result: **descending sort**.

---

I can now plug this dry run into your viva-ready Lab 15 Q3 code with print statements and comments if you want a full walkthrough.