#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int INF = static_cast<int>(1e9);

// this is the simplest, greedy like implementation, and it takes O(N^2)
class Graph {
	class Node {
	public:
		int V;
		// (parent, weight)
		vector<pair<int,int>>parents;
		// (child, weight)
		vector<pair<int,int>>children; 
		//value by default; optimized to implement in generics
		Node(int value = 0) : V(value) {}
	};

public:
	vector<Node>nodes;
	//found by Dijkstra distance from the startNode to current node
	vector<int>dist; 
	vector<bool>expanded;
	//we store queue of nodes with distance == x for each x
	map<int, queue<int>> q; 
	Graph(const vector<int>& values) {
		for (int v : values)
		{
			nodes.push_back(Node(v));
		}
		int n = nodes.size();
		dist.resize(n, INF);
		expanded.resize(n, false);
	}

	//simple functions of adding nodes and edges
	void addNode(int V) { nodes.push_back(Node(V)); }
	void removeNode(int V) {
		//removal of incident edges
		for (auto &[child,_] : nodes[V].children)
		{
			auto& parents = nodes[child].parents;
			parents.erase(
				remove_if(parents.begin(), parents.end(),
					[&](auto& p) {return p.first == V;}),
				parents.end()
			);
		}

		for (auto& [parent, _] : nodes[V].parents)
		{
			auto& children = nodes[parent].children;
			children.erase(
				remove_if(children.begin(), children.end(),
					[&](auto& ch) {return ch.first == V;}),
				children.end()
			);
		}

		//indexes shift after the removal of edges
		for (auto& node : nodes) {
			for (auto& child : node.children)
				if (child.first > V) child.first--;
			for (auto& parent : node.parents)
				if (parent.first > V) parent.first--;
		}
	}
	void addEdge(int from, int to, int weight) {  
		if (from >= nodes.size() || to >= nodes.size()) { return; }
		nodes[from].children.push_back({ to, weight });
		nodes[to].parents.push_back({ from, weight });
	}
	void removeEdge(int from, int to) {
		auto& children = nodes[from].children;
		children.erase(
			remove_if(children.begin(), children.end(),
				[&](auto& p) {return p.first == to;}),
			children.end()
		);

		auto& parents = nodes[to].parents;
		parents.erase(
			remove_if(parents.begin(), parents.end(),
				[&](auto& p) {return p.first == from;}),
			parents.end()
		);
		//shifts all elements except 'from' to the left, then deletes 'from' Node
	}

	// main functions
	void expand(int V);
	void Dijkstra(int startNode);	
};

void Graph::expand(int V) {
	if (expanded[V] == true) { return; }

	int y;
	for  (int &[child,weight] : nodes[V].children)
	{
		y = dist[V] + weight;
		if (dist[child] > y) {
			dist[child] = y;
			q[y].push(child);
		}
	}
}

void Graph::Dijkstra(int startNode) {
	dist[startNode] = 0;
	q[0].push(startNode);

	while (!q.empty()) {
		auto it = q.begin();
		int v = it->second.front();
		it->second.pop();
		if (it->second.empty()) q.erase(it);

		if (expanded[v]) continue;
		expanded[v] = true;
		expand(v);
	}
}