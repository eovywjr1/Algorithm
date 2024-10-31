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
    unique_ptr<Node> _leftChild = nullptr;
    unique_ptr<Node> _rightChild = nullptr;
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
    void setRootNode(Node* root){ _root.reset(root); }

private:
    unique_ptr<Node> _root = nullptr;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int nodeCount = 0;
    cin >> nodeCount;

    Tree tree;
    unordered_map<char, Node*> nodeSubtrees;

    {
        string str;
        getline(cin, str);
    }
    
    for (int nodeIndex = 0; nodeIndex < nodeCount; ++nodeIndex)
    {
        string subtree;
        getline(cin, subtree);

        subtree.erase(remove(subtree.begin(), subtree.end(), ' '), subtree.end());

        Node* parentNode = nullptr;
        if (nodeSubtrees.find(subtree[0]) != nodeSubtrees.end())
        {
            parentNode = nodeSubtrees[subtree[0]];
        }
        else
        {
            parentNode = new Node(subtree[0], nullptr, nullptr);
        }

        nodeSubtrees[subtree[0]] = parentNode;

        if(subtree[1] != '.')
        {
            Node* leftChildNode = nullptr;
            if (nodeSubtrees.find(subtree[1]) != nodeSubtrees.end())
            {
                leftChildNode = nodeSubtrees[subtree[1]];
            }
            else
            {
                leftChildNode = new Node(subtree[1], nullptr, nullptr);
            }

            parentNode->_leftChild.reset(leftChildNode);
            nodeSubtrees[subtree[1]] = parentNode->_leftChild.get();
        }
        
        if(subtree[2] != '.')
        {
            Node* rightChildNode = nullptr;
            if (nodeSubtrees.find(subtree[2]) != nodeSubtrees.end())
            {
                rightChildNode = nodeSubtrees[subtree[2]];
            }
            else
            {
                rightChildNode = new Node(subtree[2], nullptr, nullptr);
            }

            parentNode->_rightChild.reset(rightChildNode);
            nodeSubtrees[subtree[2]] = parentNode->_rightChild.get();
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
