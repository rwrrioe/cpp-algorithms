#include <vector>
#include <algorithm>
using namespace std;

class Graph {
	struct Edge {
		int from, to, weight;
		Edge(int f, int t, int w) : from(f), to(t), weight(w) {}
	};
public:
	//the number of vertices
	int V;
	vector<Edge> edges;
	//disjoint set, root is negative and its value shows the number of vertices in the set
	vector<int>parent;
	// in the tree number of edges is V - 1, where V is the number of vertices
	Graph(int vertices) : V(vertices) { edges.resize(V - 1); }

	void addEdge(int u, int v, int w) {
		edges.push_back(Edge(u, v, w));
	}


	//functions for the disjoint set
	void initializePortion() {
		for (int i = 0; i < V; i++) {
			parent[i] = -1;
		}
	}

	int findRoot(int s) {
		int result = s;

		while (parent[result] > 0) {
			result = parent[result];
		}
		return result;
	}

	void Union(int v, int u) {
		int totalElements = findRoot(u) + findRoot(v);

		if (findRoot(u) > findRoot(v))
		{
			parent[findRoot(u)] = v;
			parent[findRoot(v)] = totalElements;
		}
		else {
			parent[findRoot(v)] = u;
			parent[findRoot(u)] = v;
		}
	}

	void Kruskall();
};

