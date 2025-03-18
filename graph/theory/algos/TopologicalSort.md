# Topological Sort

## Introduction
Topological sorting is a linear ordering of vertices in a Directed Acyclic Graph (DAG) such that for every directed edge `u -> v`, vertex `u` comes before `v` in the ordering. This is commonly used in scheduling problems, task dependencies, and compiler construction.

## Algorithm
1. **Calculate In-Degree:**
   - Compute the in-degree (number of incoming edges) of each vertex.
2. **Initialize Queue:**
   - Enqueue all vertices with in-degree `0`.
3. **Process Queue:**
   - Dequeue a vertex, append it to the result.
   - Reduce in-degree of its adjacent vertices by `1`.
   - If any adjacent vertex's in-degree becomes `0`, enqueue it.
4. **Repeat Until Queue is Empty.**

## Complexity Analysis
- **Building the Graph:** `O(V + E)`
- **Computing In-Degree:** `O(V + E)`
- **Processing the Queue:** `O(V + E)`
- **Total Complexity:** `O(V + E)`, where `V` is the number of vertices and `E` is the number of edges.

## Applications
- **Task Scheduling**
- **Dependency Resolution** (e.g., package managers)
- **Course Prerequisite Planning**
- **Compiler Optimization**

## Limitations
- Only works on **DAGs**.
- Fails for graphs with cycles.

## Conclusion
Topological sorting is a crucial algorithm in graph theory, especially for dependency-based systems. It ensures that each task is executed only after its prerequisites are completed.
