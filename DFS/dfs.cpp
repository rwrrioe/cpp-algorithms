#include<iostream>
#include<vector>
using namespace std;

//in this realization we store only the nodes with list of incident edges which is implemented by parent and children vectors
//all the nodes arranged in a ascending order
int timer = 0; //global timer
enum class Color {
	WHITE,
	GRAY,
	BLACK
};

class Graph {
	class Node {
	public:
		int V;
		vector<int>parents;
		vector<int>children;
		Node(int value = 0) : V(value) {}//value by default; optimized to implement in generics
	};

public:
	vector<Node>nodes;
	vector<int> tin, tout;// in and out vectors with Nodes indexes
	vector<Color> color;
	Graph(const vector<int>& values) {
		for (int v : values)
		{
			nodes.push_back(Node(v));
		}
		int n = nodes.size();

		tin.resize(n, 0);
		tout.resize(n, 0);
		color.resize(n, Color::WHITE);
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

	void DFS(int startNode);	// main function
};

void Graph::DFS(int startNode) {
	if (color[startNode] == Color::BLACK) { return; }

	color[startNode] = Color::GRAY;
	auto& children = nodes[startNode].children;
	tin[startNode] = timer;
	timer++;

	for (int to : children)
	{
		if (color[to] == Color::WHITE) { DFS(to); }
	}

	tout[startNode] = timer;
	timer++;
	color[startNode] = Color::BLACK;
}