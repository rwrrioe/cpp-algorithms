
# Algorithms in C++

This repository contains implementations of fundamental graph algorithms
**in C+**+.
The goal is to build a collection of examples for educational purposes and self-learning.

## Implemented Algorithms

-   DFS (Depth-First Search)
-   BFS (Breadth-First Search)
-   More algorithms coming soon (Dijkstra, MST, LCA, etc.)

## Project Structure

Each algorithm is placed in its own folder:

    project_root/
    │
    ├── dfs/
    │   ├── dfs.cpp
    │   └── README.md
    │
    ├── bfs/
    │   ├── bfs.cpp
    │   └── README.md
    │
    └── README.md   <- this file

## How to Build & Run

1.  Clone the repository:

        git clone https://github.com/<your-username>/<repo-name>.git
        cd <repo-name>

2.  Go to the folder with the algorithm you want to build, for example
    BFS:

        cd bfs

3.  Compile:

        g++ bfs.cpp -o bfs

4.  Run:

        ./bfs

Notes

 -   Code is written in modern C++17.
 -   Graphs are implemented as adjacency lists.
 -   Default weights are 1 (unweighted graph), but algorithms can be
    extended to weighted graphs.
 - 0 - K BFS, Kosaraju's algorithm, Topological sorting will be added soon

------------------------------------------------------------------------

✍️ Contributions are welcome — feel free to add new algorithms or
improve documentation.
