# MST Algorithms in C++

This repository contains implementations of MST in C++, such as Kruskal algorithm and Prim's algorithm for Minimum Spanning Tree (MST).

## Features
 **Prim's Algorithm**: Builds the Minimum Spanning Tree by iteratively adding the smallest edge connecting the growing MST to an unvisited vertex.
 **Kruskal's Algorithm**: Builds the Minimum Spanning Tree (MST) by sorting all edges by weight and iteratively adding the smallest edge that does not form a cycle, until all vertices are connected.

### Prim's Algorithm

```bash
cd MST
g++ -std=c++17 prim.cpp -o prim
./prim
```
### Kruskal's Algorithm
```bash
cd MST
g++ -std=c++17 kruskal.cpp -o prim
./kruskal
```

## Future Improvements

- ~~Add Kruskal's algorithm for MST~~  - Added✅.
- Implement Bellman-Ford.
- Add priority - queue implementation for Prim's algorithm.
- Create a CLI interface for easier interaction.

