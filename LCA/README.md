Learning LCA Algorithm with Binary Lifting
========================================

This repository contains a simple implementation of a rooted tree in C++ with LCA (Lowest Common Ancestor) algorithm using Binary Lifting.

Files:
------
- `rootedTree.cpp` : Implementation of the tree, DFS traversal, binary lifting, and LCA function.

Key Features:
-------------
- Dynamic tree construction using Node pointers.
- `tin` and `tout` arrays to determine ancestor relationships.
- Binary lifting (`ansectors` vector) to find k-th ancestor efficiently.
- LCA function to find the lowest common ancestor of two nodes.

Usage:
------
1. Initialize the tree with a root node:
   ```cpp
   rootedTree tree(rootValue);
   ```
2. Add child nodes:
   ```cpp
   auto child = tree.addChild(parentNode, childValue);
   ```
3. Perform DFS to initialize tin/tout arrays:
   ```cpp
   tree.dfs(tree.getRoot());
   ```
4. Find LCA between two nodes:
   ```cpp
   auto ancestor = tree.lca(node1, node2);
   ```

Notes:
------
- This code is intended for learning purposes and experimentation with tree structures and LCA.
- Node values are assumed to be unique integers starting from 1.
- Memory management (destructor) is not implemented yet; this is left for future improvement.



