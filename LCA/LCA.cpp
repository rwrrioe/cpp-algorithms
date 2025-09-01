#include <iostream>
#include <vector>
using namespace std;


class rootedGraph {
	int t = 0;
	vector<int> tin;
	vector<int>tout;

	struct Node {
		int value;
		vector<Node*>children;
		Node(int v) : value(v) {}
	};

	Node* root = nullptr;
public:
	Node* initRoot(int value, int n) {
		Node* root = new Node(value);
		tin.assign(n + 1, 0);
		tout.assign(n + 1, 0);
		t = 0;
	}

	Node* addChild(Node* parent, int value) {
		Node* child = new Node(value);
		parent->children.push_back(child);
		return child;
	}

	void dfs(Node* root) {
		tin[root->value] = t++;
		for (auto child : root->children) {
			dfs(child);
		}
		tout[root->value] = t;
	}

	Node* getRoot() {
		return root;
	}


};


