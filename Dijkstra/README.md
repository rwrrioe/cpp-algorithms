# Dijkstra Algorithm Implementation in C++

This project contains a simple implementation of the Dijkstra shortest-path algorithm in C++ using a `map<int, queue<int>>` structure. The code demonstrates a "greedy" approach, maintaining vertices grouped by their distance values.

----------

## Features

-   **Graph class** with nodes and weighted edges.
    
-   **Dynamic addition and removal** of nodes and edges.
    
-   **Dijkstra algorithm using a map of queues**:
    
    -   `map<int, queue<int>>` stores vertices for each distance value.
        
    -   Vertices are processed in order of increasing distance.
        
-   **Expand function** to update distances of neighbors.
    

----------

## Usage

1.  **Include the Graph class** in your project.
    
2.  **Create a graph**:
    

```cpp
vector<int> values = {0, 1, 2, 3};
Graph g(values);

```

3.  **Add edges**:
    

```cpp
g.addEdge(0, 1, 5);
g.addEdge(0, 2, 10);
g.addEdge(1, 3, 2);

```

4.  **Run Dijkstra from a start node**:
    

```cpp
g.Dijkstra(0);

```

5.  **Access shortest distances**:
    

```cpp
for (int i = 0; i < g.dist.size(); i++) {
    cout << "Distance to " << i << " is " << g.dist[i] << endl;
}

```

----------

## Implementation Details

-   `Node` class stores children and parents with weights.
    
-   `dist` vector stores shortest distances from the start node.
    
-   `expanded` vector ensures each vertex is processed only once.
    
-   `expand(int V)` updates distances for all neighbors of vertex `V`.
    

----------

## Possible Improvements

1.  **Use `priority_queue`** instead of `map` for better performance on large graphs (O(E log V) complexity).
    
2.  **Support negative weights** using Bellman-Ford algorithm.
    
3.  **Template Graph class** to support different numeric types for weights.
    
4.  **Add path reconstruction** to get the actual shortest path, not just distances.
    
5.  **Optimize memory usage** by removing parent lists if not needed.
    
6.  **Support directed and undirected graphs** with a flag in `addEdge`.
    

----------

## Notes

-   This implementation is simple and easy to understand, suitable for educational purposes.
    
-   For very large graphs, the map-based approach can be slower than a `priority_queue` implementation.
    
-   Edge removal and node removal are supported but may be costly due to vector operations.