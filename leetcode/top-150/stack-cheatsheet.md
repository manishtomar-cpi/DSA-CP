# 🧰 Stack Problem Cheat Sheet – When to Use a Stack

Use this guide to quickly recognize when a problem is best solved using a **stack**. This is especially helpful for interviews, contests, and daily practice.

---

## ✅ 1. Undo / Go Back

Use a stack when the problem involves undoing the most recent action, or going back to a previous state.

**Examples:**
- Simplify Unix Path (`/a/b/../c`)
- Text editor with backspace
- Browser history navigation

---

## ✅ 2. Matching Pairs / Balanced Symbols

Perfect for problems that involve **opening and closing** characters or tags.

**Examples:**
- Valid parentheses: `()[]{}`
- HTML/XML tag validation
- Expression syntax checker

---

## ✅ 3. Monotonic Stack

Use when you're finding the **next or previous greater/smaller** element while maintaining order.

**Examples:**
- Stock Span Problem
- Daily Temperatures
- Largest Rectangle in Histogram

---

## ✅ 4. Reversal Problems

When you need to reverse a sequence of operations or elements.

**Examples:**
- Reverse Polish Notation (RPN) calculator
- Decode string like `"3[a2[c]]"`
- Reverse words or characters

---

## ✅ 5. Recursion Simulation / DFS

Use a stack to simulate recursion or perform **depth-first search** iteratively.

**Examples:**
- Iterative binary tree traversal (inorder, preorder)
- Flood fill algorithms
- Backtracking (maze solving, combinations)

---

## ✅ 6. Stateful Expression Evaluation

Great when parsing and evaluating complex expressions with nested structures.

**Examples:**
- Math expression evaluator: `2*(3+(4-1))`
- Infix to postfix conversion
- Calculator with +, -, *, /

---

## ✅ 7. Path or Sequence Building

Stack helps in building a result where you might need to **remove previous steps** conditionally.

**Examples:**
- Simplify file paths
- Keyboard typing simulations (`leet<<code` → `leecode`)
- Canonical URL building

---

## 🗞️ Summary Table

| Problem Pattern             | Use Stack? ✅ | Example                             |
|----------------------------|----------------|-------------------------------------|
| Undo/Go back               | Yes            | File paths, browser history         |
| Matching brackets/tags     | Yes            | Valid parentheses, HTML tags        |
| Find next/previous values  | Yes            | Monotonic stack (daily temps)       |
| Reverse operations         | Yes            | Decode string, reverse expression   |
| Manual recursion / DFS     | Yes            | Maze solving, tree traversal        |
| Stateful eval              | Yes            | Math evaluator, nested expressions  |
| Sequence/path building     | Yes            | File path simplification, typing    |

---

## 💪 Tip to Remember:

> If you need to **track something and undo the last thing you did**, a **stack** is the best choice!

---

Let me know if you'd like a PDF version, visual guide, or practice problems for each stack category!