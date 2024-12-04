#include <iostream>

using namespace std;

struct Node
{
	int key = 0;

	Node* leftNode = nullptr;
	Node* rightNode = nullptr;
};

Node* findNode(const int num, Node* node)
{
	if (node->key == 0)
	{
		return node;
	}

	if (node->key > num)
	{
		if (node->leftNode == nullptr)
		{
			node->leftNode = new Node();
		}

		return findNode(num, node->leftNode);
	}
	else if(node->key < num)
	{
		if (node->rightNode == nullptr)
		{
			node->rightNode = new Node();
		}

		return findNode(num, node->rightNode);
	}

	return nullptr;
}

void postTraversial(const Node* node)
{
	if (node->leftNode)
	{
		postTraversial(node->leftNode);
	}

	if (node->rightNode)
	{
		postTraversial(node->rightNode);
	}

	cout << node->key << '\n';
}

void postTraversialDeleteNode(Node* node)
{
	if (node->leftNode)
	{
		postTraversialDeleteNode(node->leftNode);
	}

	if (node->rightNode)
	{
		postTraversialDeleteNode(node->rightNode);
	}

	delete node;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Node* rootNode = new Node();
	
	int num = 0;
	while (cin >> num)
	{
		findNode(num, rootNode)->key = num;
	}

	postTraversial(rootNode);
	postTraversialDeleteNode(rootNode);
}
