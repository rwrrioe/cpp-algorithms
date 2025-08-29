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
	//MST
	vector<Edge>MST;
	// in the tree number of edges is V - 1, where V is the number of vertices
	Graph(int vertices) : V(vertices) { parent.resize(V, -1); }

	void addEdge(int u, int v, int w) {
		edges.push_back(Edge(u, v, w));
	}

	int findRoot(int s) {
		int result = s;

		while (parent[result] > 0) {
			result = parent[result];
		}
		return result;
	}

	void Union(int v, int u) {
		u = findRoot(u);
		v = findRoot(v);

		if (u == v) return;

		//v stores more than u(roots stores -size)
		if (parent[u] > parent[v]) {
			parent[v] += parent[u];
			parent[u] = v;
		}
		else {
			parent[u] += parent[v];
			parent[v] = u;
		}
	}
	void Kruskall();
};

void Graph::Kruskall() {
	sort(edges.begin(), edges.end(), []( const Edge& a, const Edge& b) { return a.weight < b.weight; });
	int edgeCount = 0;

	while (edgeCount < edges.size() && MST.size() < V - 1) {
		int u = edges[edgeCount].from;
		int v = edges[edgeCount].to;

		if (findRoot(u) != findRoot(v)) {
			MST.push_back(edges[edgeCount]);
			Union(u, v);
		}
		edgeCount++;
	}
}