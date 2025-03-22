# Dijkstra's Algorithm - Shortest Path Algorithm

## Introduction
Dijkstra's Algorithm is a **graph-based shortest path algorithm** used to find the **minimum distance** from a **source node** to all other nodes in a **weighted graph**. It guarantees the shortest path when all edge weights are **non-negative**.

## Key Features
- **Finds the shortest path from one node to all other nodes** in a graph.
- **Only works for graphs with non-negative edge weights**.
- **Uses a priority queue (or an array) to process nodes efficiently**.
- **Time Complexity:**
  - Using a priority queue (Min Heap): **O(V + E log V)**
  - Using an array (naïve approach): **O(V²)**

## 📌 How Dijkstra’s Algorithm Works

### **1️⃣ Graph Representation**
A graph is represented as:
- **Nodes (Vertices)**: Represent places or points.
- **Edges (Connections)**: Represent roads or paths with weights (distances or costs).

Example Graph:
```
        (4)
    0 ------- 1
     |  \     |
    (1)  (2)  (5)
     |     \  |
    2 ------- 3
        (3)    \
                (1)
                 4
```
Where:
- **0 → 1 (4 km)**
- **0 → 2 (1 km)**
- **0 → 3 (2 km)**
- **1 → 3 (5 km)**
- **2 → 3 (3 km)**
- **3 → 4 (1 km)**

### **2️⃣ Algorithm Steps**

1. **Initialize** distances:
   - Set the source node’s distance to `0`.
   - Set all other nodes’ distances to `∞` (infinity).
   - Use a **priority queue** (or a simple array) to track the nearest node.

2. **Pick the node with the smallest distance** (start from source).
   - Mark it as **visited** (included in shortest path set).
   - Update distances for **neighboring nodes**.

3. **Repeat until all nodes are processed**.
   - Always pick the next nearest node.
   - Update distances if a **shorter path** is found.

### **3️⃣ Dry Run Example**

#### **Initial Setup (Start from Node 0)**
| Node  | Distance from 0 | Previous Node |
|-------|----------------|---------------|
| 0     | 0              | -             |
| 1     | ∞              | -             |
| 2     | ∞              | -             |
| 3     | ∞              | -             |
| 4     | ∞              | -             |

#### **Step 1: Pick Node 0 (Smallest Distance = 0)**
- **Update its neighbors:**
  - 1 → 4
  - 2 → 1
  - 3 → 2

| Node  | Distance from 0 | Previous Node |
|-------|----------------|---------------|
| 0     | 0              | -             |
| 1     | 4              | 0             |
| 2     | 1              | 0             |
| 3     | 2              | 0             |
| 4     | ∞              | -             |

#### **Step 2: Pick Node 2 (Smallest Distance = 1)**
- **Update its neighbors:**
  - 3 → 1+3 = 4 (no change, 2 is smaller)

#### **Step 3: Pick Node 3 (Smallest Distance = 2)**
- **Update its neighbors:**
  - 4 → 2+1 = 3

| Node  | Distance from 0 | Previous Node |
|-------|----------------|---------------|
| 0     | 0              | -             |
| 1     | 4              | 0             |
| 2     | 1              | 0             |
| 3     | 2              | 0             |
| 4     | 3              | 3             |

#### **Step 4: Pick Node 4 (Smallest Distance = 3)**
- No new updates

#### **Step 5: Pick Node 1 (Smallest Distance = 4)**
- No new updates

🎯 **Final Shortest Path Distances from Node 0:**
```
0 → 0
1 → 4
2 → 1
3 → 2
4 → 3
```

## 🎯 **Key Observations**
- **Greedy Approach**: Always processes the smallest distance node first.
- **Handles Weighted Graphs** (non-negative weights only).
- **Can be optimized using priority queues for large graphs**.
- **Used in GPS Navigation, Network Routing, AI Pathfinding.**

## 📚 **Applications of Dijkstra’s Algorithm**
✅ **Google Maps / GPS Navigation** (Finding the shortest route between locations)  
✅ **Network Routing Protocols** (Optimizing data transmission paths)  
✅ **AI Pathfinding in Games** (Character movement in strategy and adventure games)  
✅ **Robot Navigation** (Determining the shortest path for automated robots)  
✅ **Traffic Flow Analysis** (Optimizing road networks based on real-time traffic)

## 🚀 **Conclusion**
Dijkstra’s Algorithm is an essential tool for **shortest path finding** in **weighted graphs**. Its **greedy approach** makes it **fast and efficient**, widely used in **real-world applications** like GPS and AI pathfinding.



