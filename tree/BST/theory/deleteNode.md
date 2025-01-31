# Deleting a Node in a Binary Search Tree (BST)

## Introduction

Deleting a node in a Binary Search Tree (BST) requires careful handling to maintain the BST properties:

1. **Left subtree** contains values **less than** the node.
2. **Right subtree** contains values **greater than** the node.

We consider three main cases when deleting a node:

1. **Node is a leaf** (no children)
2. **Node has one child** (left or right)
3. **Node has two children** (requires swapping with in-order successor or predecessor)

---

## Case 1: Deleting a Leaf Node

### Example BST Before Deletion

```
        50
       /  \
     30    70
    /  \   /  \
   20  40 60   80
  /
 10
```

**Delete node \*\***`10`\*\* (a leaf node).

### Steps:

- Find node `10`.
- Since `10` has no children, simply remove it.

### BST After Deletion

```
        50
       /  \
     30    70
    /  \   /  \
   20  40 60   80
```

✅ **BST remains valid!**

---

## Case 2: Deleting a Node with One Child

### Example BST Before Deletion

```
        50
       /  \
     30    70
    /  \   /  \
   20  40 60   80
  /
 10
```

**Delete node \*\***`20`**, which has **one child (\***\*`10`\*\***)\*\*.

### Steps:

- Find node `20`.
- Replace it with its only child (`10`).

### BST After Deletion

```
        50
       /  \
     30    70
    /  \   /  \
   10  40 60   80
```

✅ **BST remains valid!**

---

## Case 3: Deleting a Node with Two Children

### Example BST Before Deletion

```
        50
       /  \
     30    70
    /  \   /  \
   20  40 60   80
  /  \     \
 10   25     65
```

**Delete node \*\***`50`**, which has **two children (\***\*`30`\*\*** and \***\*`70`\*\***)\*\*.

### **Using the In-Order Successor** (Leftmost node in right subtree)

#### Steps:

1. Find **in-order successor** of `50` → **`60`**.
2. Swap `50` with `60`.
3. Delete the original `60` (which has a right child `65`).
4. Connect `65` as the left child of `70`.

### BST After Deletion

```
        60
       /  \
     30    70
    /  \   /  \
   20  40 65   80
  /  \
 10   25
```

✅ **BST remains valid!**

### **Using the In-Order Predecessor** (Rightmost node in left subtree)

#### Steps:

1. Find **in-order predecessor** of `50` → **`40`**.
2. Swap `50` with `40`.
3. Delete the original `40`.

### BST After Deletion

```
        40
       /  \
     30    70
    /      /  \
   20     60   80
  /  \       \
 10   25      65
```

✅ **BST remains valid!**

---

## **Doubts & Explanations**

### **Why Do We Swap with the Successor Instead of Its Right Child?**

- The successor **may have a right child**, but it **never has a left child**.
- If the successor has a right child, we simply connect its parent to this child before deleting the successor.
- If we swap directly with a deeper right node (instead of the successor), we risk violating BST properties.

### **Can We Always Use Either Successor or Predecessor?**

Yes! We can use either the **in-order successor** (leftmost node in the right subtree) or the **in-order predecessor** (rightmost node in the left subtree). Both maintain the BST structure.

### **What If the Node to Delete is the Root?**

If the root node has two children, we follow the same process:

- Find in-order successor or predecessor.
- Swap values.
- Delete the successor/predecessor node.
- If the root has only one child, we directly replace it with that child.

---

## **Final Summary**

✅ **Leaf nodes are deleted directly.**
✅ **Nodes with one child are replaced by their child.**
✅ **Nodes with two children swap with in-order successor/predecessor before deletion.**
✅ **BST properties remain valid in all cases!** 🚀
