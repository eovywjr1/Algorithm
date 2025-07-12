#include <bits/stdc++.h>

using namespace std;

map<int, vector<pair<int,int>>> Edges;
vector<int> MinDistances;

void Dijkstra(const int Start, const int VertexCount)
{
    vector<int> TempDistnaces(VertexCount + 1, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> PQ;
    
    PQ.push({0, Start});
    TempDistnaces[Start] = 0;
    
    while(!PQ.empty())
    {
        const int CurrentVertex = PQ.top().second;
        const int CurrentCost = PQ.top().first;
        PQ.pop();
        
        for(const pair<int,int>& Edge : Edges[CurrentVertex])
        {
            const int NextCost = CurrentCost + Edge.second;
            if(NextCost < TempDistnaces[Edge.first])
            {
                TempDistnaces[Edge.first] = NextCost;
                PQ.push({NextCost, Edge.first});
            }
        }
    }
    
    MinDistances = TempDistnaces;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    for(const vector<int>& Fare : fares)
    {
        Edges[Fare[0]].push_back({Fare[1], Fare[2]});
        Edges[Fare[1]].push_back({Fare[0], Fare[2]});
    }
    
    int Answer = INT_MAX;
    
    for(int Vertex = 1; Vertex <= n; ++Vertex)
    {
        Dijkstra(Vertex, n);
        
        Answer = min(Answer, MinDistances[s] + MinDistances[a] + MinDistances[b]);
    }
    
    return Answer;
}
