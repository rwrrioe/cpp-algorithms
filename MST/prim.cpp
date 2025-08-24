#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Graph {
	class Node {
	public:
		int V;
		// (parent, weight)
		vector<pair<int, int>>parents;
		// (child, weight)
		vector<pair<int, int>>children;
		//value by default; optimized to implement in generics
		Node(int value = 0) : V(value) {}
	};

public:
	vector<Node>nodes;
	// marks if a vertex belongs to the component
	vector<bool>isThere;
	// array of vertices currently in the component
	vector<int>component; 
	Graph(const vector<int>& values) {
		for (int v : values)
		{
			nodes.push_back(Node(v));
		}
		int n = nodes.size();
		isThere.resize(n, false);
		component.resize(1);
	}

	//simple functions of adding nodes and edges
	void addNode(int V) { nodes.push_back(Node(V)); }
	void removeNode(int V) {
		//removal of incident edges
		for (auto& child : nodes[V].children)
		{
			auto& parents = nodes[child.first].parents;
			parents.erase(
				remove_if(parents.begin(), parents.end(),
					[&](auto& p) {return p.first == V;}),
				parents.end()
			);
		}

		for (auto& parent : nodes[V].parents)

		{
			auto& children = nodes[parent.first].children;
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

	void Prim(int startNode) {};
};

void Graph::Prim(int startNode) {
	isThere[startNode] = true;
	component.push_back(startNode);

	auto children = nodes[startNode].children;
	
}
