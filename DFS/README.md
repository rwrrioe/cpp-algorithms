DFS (Depth-First Search)

This folder contains the implementation of Depth-First Search (DFS) in C++.

---

Files

- DFS.cpp — source code
- README.md — this file

---

Description

DFS is a graph traversal algorithm that explores as far as possible along each branch before backtracking.
This implementation tracks parents and children of each node and uses in/out timestamps.

---

Example Graph

0 → 1 → 3
│
└→ 2

- Start DFS from node 0.
- Traversal order: 0 → 1 → 3 → 2 (depending on children order in vector)

---

Example Usage

#include "DFS.cpp"

int main() {
    Graph g({0, 1, 2, 3});
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);

    g.DFS(0); // start DFS from node 0

    return 0;
}

- DFS.cpp implements the DFS traversal with parent/children vectors, tin/tout timestamps, and node coloring.

---

Complexity

- Time Complexity: O(V + E) — visits each node and edge once
- Space Complexity: O(V) — for color, tin, tout vectors

---

References

- Depth-First Search on Wikipedia: https://en.wikipedia.org/wiki/Depth-first_search