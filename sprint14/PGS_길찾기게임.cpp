#include <bits/stdc++.h>

using namespace std;

struct FNode
{
    int Number = 0;
    int x = 0, y = 0;
    FNode* Left = nullptr, *Right = nullptr;
};

vector<FNode> SortNodes;

void AddNode(FNode* AddNode)
{
    FNode* PrevNode = nullptr;
    
    for(FNode* CurrentNode = &SortNodes[0]; CurrentNode;)
    {
        PrevNode = CurrentNode;
        CurrentNode = AddNode->x < CurrentNode->x ? CurrentNode->Left : CurrentNode->Right;
    }
    
    if(AddNode->x < PrevNode->x)
    {
        PrevNode->Left = AddNode;
    }
    else
    {
        PrevNode->Right = AddNode;
    }
    
    cout << PrevNode->Number << ' ';
}

void PreOrder(FNode* CurrentNode, vector<int>& PreOrderResult)
{
    if(!CurrentNode)
    {
        return;
    }
    
    PreOrderResult.push_back(CurrentNode->Number);
    
    PreOrder(CurrentNode->Left, PreOrderResult);
    PreOrder(CurrentNode->Right, PreOrderResult);
}

void PostOrder(FNode* CurrentNode, vector<int>& PostOrderResult)
{
    if(!CurrentNode)
    {
        return;
    }
    
    PostOrder(CurrentNode->Left, PostOrderResult);
    PostOrder(CurrentNode->Right, PostOrderResult);
    
    PostOrderResult.push_back(CurrentNode->Number);
}

vector<vector<int>> solution(vector<vector<int>> NodeInfos) {
    const int NodeInfosSize = NodeInfos.size();
    SortNodes.resize(NodeInfosSize);
    
    for(int i = 0; i < NodeInfosSize; ++i)
    {
        const int x = NodeInfos[i][0];
        const int y = NodeInfos[i][1];
        
        SortNodes[i].Number = i + 1;
        SortNodes[i].x = x;
        SortNodes[i].y = y;
    }
    
    sort(SortNodes.begin(), SortNodes.end(), [](const FNode& Lhs, const FNode& Rhs)
        {
            return Lhs.y != Rhs.y ? Rhs.y < Lhs.y : Lhs.x < Rhs.x;
        });
    
    
    for(int i = 1; i < NodeInfosSize; ++i)
    {
        AddNode(&SortNodes[i]);
    }
    
    vector<vector<int>> answer(2);
    PreOrder(&SortNodes[0], answer[0]);
    PostOrder(&SortNodes[0], answer[1]);
    
    return answer;
}
