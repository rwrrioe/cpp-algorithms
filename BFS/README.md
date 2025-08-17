# BFS (Breadth-First Search)

This project implements **Breadth-First Search (BFS)** on a graph.  
The graph is represented as a list of nodes (`Node`) with parents and children.  
The algorithm computes the minimum distances from the starting node to all other nodes, weighted function is 1 by default.

---

## 📖 Theory

- BFS uses a **queue** to traverse the graph.  
- Each node is marked with its distance `dist[v]` from the starting node.  
- If a node has not been visited yet → distance is `-1`.  
- When a node is visited, its neighbors get a distance `dist[child] = dist[v] + 1`.  

The algorithm guarantees the shortest path in an unweighted graph.

---

## ⚙️ Project structure

```
BFS/
│── bfs.cpp        # Graph and BFS implementation
│── README.md      # Project description
```

---

## 🚀 How to run

1. Open the project in **Visual Studio** (or any other C++ IDE).
2. Make sure you select **Console Application** mode.
3. In `main()` you can:
   - Create a graph
   - Add nodes and edges
   - Call `BFS(startNode)`
   - Print distances from the starting node