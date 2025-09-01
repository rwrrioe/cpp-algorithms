#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


class rootedTree {
	struct Node {
		int value;
		vector<Node*>children;
		//vector of 2^k-th ansectors
		vector<Node*>ansectors;
		//construct root node
		Node(int v, int log) : value(v), ansectors(log, nullptr) {}
	};

	int timer = 0;
	vector<int> tin, tout;
	//binary lifts (generation, descendant)
	vector<vector<int>>up

	Node* root = nullptr;
	int LOG;
	int nodeCount;
	//stores all nodes to update ansectors
	vector<Node*> allNodes;
public:
	rootedTree(int rootValue) {
		nodeCount = 1;
		LOG = 1;
		initRoot(rootValue);

		tin.resize(2);
		tout.resize(2);
	}

	Node* initRoot(int value) {
		Node* root = new Node(value, 1);
		this->root = root;
		timer = 0;
		allNodes.push_back(root);
	}

	Node* addChild(Node* parent, int value) {
		nodeCount++;
		int newLOG = (int)ceil(log2(nodeCount));

		//if LOG became greater, expand up
		if (newLOG > LOG) {
			LOG = newLOG;
			for (auto n : allNodes)
			{
				n->ansectors.resize(LOG, nullptr);
			}
		}

		Node* child = new Node(value, newLOG);
		parent->children.push_back(child);
		allNodes.push_back(child);
		child->ansectors[0] = parent;

		//enter binary ansectors
		for (int k = 1; k < newLOG; k++)
		{
			if (child->ansectors[k - 1] != nullptr) {
				child->ansectors[k] = child->ansectors[k - 1]->ansectors[k - 1];
			}
		}

		return child;
	}

	// LCA algorithms

	// is u the ansector of v
	bool IsAnsector(Node* u, Node* v) {
		return tin[u->value] <= tin[v->value] && tout[u->value] >= tout[v->value];
	}

	void dfs(Node* root) {
		tin[root->value] = timer++;
		for (auto child : root->children) {
			dfs(child);
		}
		tout[root->value] = timer;
	}

	Node* getRoot() { return root; }

	Node* lca(Node* u, Node* v) {
		if (IsAnsector(u, v)) { return u; }

		for (int k = LOG - 1; k >= 0; k--) {
			if (u->ansectors[k] != nullptr && !IsAnsector(u->ansectors[k], v)) {
				u = u->ansectors[k];
			}
		}

		return u->ansectors[0];
	}

	//TODO add destructors
};


