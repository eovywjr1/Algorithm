#include <bits/stdc++.h>

using namespace std;

int MaxSheepCount = 0;
unordered_map<int, vector<int>> Tree;
vector<int>* InfoPtr = nullptr;

bool IsPossibleTravel(const int Number, pair<int, int> SheepAndWolfCount)
{
    (*InfoPtr)[Number] == 0 ? ++SheepAndWolfCount.first : ++SheepAndWolfCount.second;
    
    return SheepAndWolfCount.second < SheepAndWolfCount.first;
}

void TravelTree(const int Node, pair<int, int> SheepAndWolfCount, vector<int> PossibleNodes, vector<int> CheckNodes)
{
    (*InfoPtr)[Node] == 0 ? ++SheepAndWolfCount.first : ++SheepAndWolfCount.second;
    MaxSheepCount = max(MaxSheepCount, SheepAndWolfCount.first);
    
    PossibleNodes.erase(remove(PossibleNodes.begin(), PossibleNodes.end(), Node), PossibleNodes.end());
    CheckNodes.erase(remove(CheckNodes.begin(), CheckNodes.end(), Node), CheckNodes.end());
    
    for(const int& ChildNode : Tree[Node])
    {
        IsPossibleTravel(ChildNode, SheepAndWolfCount) ? PossibleNodes.push_back(ChildNode) : CheckNodes.push_back(ChildNode);
    }

    for(const int& PossibleNode : PossibleNodes)
    {
        TravelTree(PossibleNode, SheepAndWolfCount, PossibleNodes, CheckNodes);
    }
    
    for(const int& CheckNode : CheckNodes)
    {
        if(IsPossibleTravel(CheckNode, SheepAndWolfCount))
        {
            TravelTree(CheckNode, SheepAndWolfCount, PossibleNodes, CheckNodes);
        }
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    InfoPtr = &info;
    
    for(const vector<int>& Edge : edges)
    {
        Tree[Edge[0]].push_back(Edge[1]);
    }
    
    TravelTree(0, {0, 0}, vector<int>(), vector<int>());
    
    return MaxSheepCount;
}
