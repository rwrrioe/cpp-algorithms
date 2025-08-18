#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//weight function == 1 by default, but it can be easily changed

class Graph {
	class Node {
	public:
		int V;
		vector<int>parents;
		vector<int>children;
		Node(int value = 0) : V(value) {}//value by default; optimized to implement using generics
	};

public:
	vector<Node>nodes;
	vector<int>dist;

	Graph(const vector<int>& values) {
		for (int v : values)
		{
			nodes.push_back(Node(v));
		}
		int n = nodes.size();
		dist.resize(n, -1); // -1 is a flag, that means we haven't been in this node
	}

	//simple functions of adding nodes and edges
	void addNode(int V) { nodes.push_back(Node(V)); }
	void addEdge(int from, int to) {
		nodes[from].children.push_back(to);
		nodes[to].parents.push_back(from);
	}

	void removeNode(int V) {
		//removal of incident edges
		for (int child : nodes[V].children)
		{
			auto& parents = nodes[child].parents;
			parents.erase(remove(parents.begin(), parents.end(), V), parents.end());
		}

		for (int parent : nodes[V].parents)
		{
			auto& children = nodes[parent].children;
			children.erase(remove(children.begin(), children.end(), V), children.end());
		}

		nodes.erase(nodes.begin() + V);

		//indexes shift after the removal of edges
		for (auto& node : nodes) {
			for (auto& child : node.children)
				if (child > V) child--;
			for (auto& parent : node.parents)
				if (parent > V) parent--;
		}
	}

	void removeEdge(int from, int to) {
		auto& children = nodes[from].children;
		children.erase(remove(children.begin(), children.end(), to), children.end());

		auto& parents = nodes[to].parents;
		parents.erase(remove(parents.begin(), parents.end(), from), parents.end()); //shifts all elements except 'from' to the left, then deletes 'from' Node
	}

	void BFS(int startNode) {};
};

void Graph::BFS(int startNode) {
	fill(dist.begin(), dist.end(), -1);  //refils vector with default values
	queue<int> q; // queue of the nodes
	dist[startNode] = 0;
	q.push(startNode);

	while (!q.empty()) {
		int v = q.front(); q.pop();
		auto& children = nodes[v].children;
		for (int child : children)
		{
			if (dist[child] == -1) {
				dist[child] = dist[v] + 1;
				q.push(child);
			}
		}
	}
}


