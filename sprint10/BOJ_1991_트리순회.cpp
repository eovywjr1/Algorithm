#include <iostream>
#include <string>
#include <unordered_map>
#include <memory>
#include <algorithm>

using namespace std;

struct Node
{
    Node(const char name, Node* leftChild, Node* rightChild)
        : _name(name), _leftChild(leftChild), _rightChild(rightChild)
    {}

    char _name;
    shared_ptr<Node> _leftChild = nullptr;
    shared_ptr<Node> _rightChild = nullptr;
};

class Tree
{
public:
    void preOrderTraversal(const Node* node) const
    {
        if (node == nullptr)
            return;

        cout << node->_name;
        preOrderTraversal(node->_leftChild.get());
        preOrderTraversal(node->_rightChild.get());
    }

    void inOrderTraversal(const Node* node) const
    {
        if (node == nullptr)
            return;

        inOrderTraversal(node->_leftChild.get());
        cout << node->_name;
        inOrderTraversal(node->_rightChild.get());
    }


    void postOrderTraversal(const Node* node) const
    {
        if (node == nullptr)
            return;

        postOrderTraversal(node->_leftChild.get());
        postOrderTraversal(node->_rightChild.get());
        cout << node->_name;
    }

    const Node* getRootNode() { return _root.get(); } const
    void setRootNode(shared_ptr<Node>& root) { _root = move(root); }

private:
    shared_ptr<Node> _root = nullptr;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int nodeCount = 0;
    cin >> nodeCount;

    Tree tree;
    unordered_map<char, shared_ptr<Node>> nodeSubtrees;

    {
        string str;
        getline(cin, str);
    }

    for (int nodeIndex = 0; nodeIndex < nodeCount; ++nodeIndex)
    {
        string subtree;
        getline(cin, subtree);

        subtree.erase(remove(subtree.begin(), subtree.end(), ' '), subtree.end());

        if (nodeSubtrees.find(subtree[0]) == nodeSubtrees.end())
        {
            nodeSubtrees[subtree[0]] = make_shared<Node>(subtree[0], nullptr, nullptr);
        }

        Node* parentNode = nodeSubtrees[subtree[0]].get();

        if (subtree[1] != '.')
        {
            if (nodeSubtrees.find(subtree[1]) == nodeSubtrees.end())
            {
                nodeSubtrees[subtree[1]] = make_shared<Node>(subtree[1], nullptr, nullptr);
            }

            parentNode->_leftChild = nodeSubtrees[subtree[1]];
        }

        if (subtree[2] != '.')
        {
            if (nodeSubtrees.find(subtree[2]) == nodeSubtrees.end())
            {
                nodeSubtrees[subtree[2]] = make_shared<Node>(subtree[2], nullptr, nullptr);
            }

            parentNode->_rightChild = nodeSubtrees[subtree[2]];
        }
    }

    tree.setRootNode(nodeSubtrees['A']);

    tree.preOrderTraversal(tree.getRootNode());
    cout << endl;

    tree.inOrderTraversal(tree.getRootNode());
    cout << endl;

    tree.postOrderTraversal(tree.getRootNode());
    cout << endl;
}
