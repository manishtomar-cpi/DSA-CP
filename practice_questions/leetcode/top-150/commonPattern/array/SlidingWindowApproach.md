
# 📘 Sliding Window Approach

## 🔍 What is a Sliding Window?

The **Sliding Window** is a technique used to reduce the time complexity of algorithms that involve arrays or lists. Instead of using nested loops, you "slide" a window (a range) across the data to keep track of useful information.

---

## 🧠 Simple Example

**Problem:**  
Given an array, find the **maximum sum of any 3 consecutive elements**.

```
Input: [1, 3, 2, 5, 4]
Window size = 3
```

---

## 🪟 Step-by-step

1. Take the first window of size 3:  
   ```
   [1, 3, 2] → sum = 6
   ```

2. Slide the window by 1 (remove 1, add 5):  
   ```
   [3, 2, 5] → sum = 10
   ```

3. Slide again (remove 3, add 4):  
   ```
   [2, 5, 4] → sum = 11
   ```

---

## ✅ Final Answer

```
Maximum sum of any 3 consecutive numbers = 11
```

---

## 💡 Key Concepts

- Keep track of the **current sum**.
- Instead of summing all elements again, just subtract the element that's leaving the window and add the new one.
- This makes the algorithm **O(n)** instead of **O(n * k)**.
