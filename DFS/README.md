# Depth-First Search (DFS)

This folder contains an implementation of the Depth-First Search (DFS)
algorithm in C++.
DFS is a fundamental graph traversal algorithm that explores as far as
possible along each branch before backtracking.

------------------------------------------------------------------------

## Algorithm Overview

-   DFS starts from a given node (source).
-   It explores one branch completely before moving to another branch.
-   Can be implemented using recursion (stack implicitly) or an explicit
    stack.

------------------------------------------------------------------------

## File Structure

    dfs/
    ├── dfs.cpp      # Implementation of DFS
    └── README.md    # Documentation (this file)

------------------------------------------------------------------------

## How to Build & Run

1.  Navigate to the dfs folder:

        cd dfs

2.  Compile the code:

        g++ dfs.cpp -o dfs

3.  Run the program:

        ./dfs

------------------------------------------------------------------------

## Notes

-   Written in modern C++17.
-   Uses adjacency lists for graph representation.
-   Can be easily extended to handle weighted graphs or iterative DFS.
-   Topological sorting, Kosaraju/Tarjan algorithms will be added soon.
