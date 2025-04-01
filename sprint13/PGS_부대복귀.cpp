#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<vector<int>> adjacentRoads(n+1);
    for(const vector<int>& road : roads)
    {
        adjacentRoads[road[0]].push_back(road[1]);
        adjacentRoads[road[1]].push_back(road[0]);
    }
    
    vector<int> shortestCosts(n+1, INT_MAX);
    queue<pair<int, int>> roadBFSQueue;
    roadBFSQueue.push(make_pair(destination, 0));
    shortestCosts[destination] = 0;
    
    while(roadBFSQueue.empty() == false)
    {
        const pair<int,int> currentRoad = roadBFSQueue.front();
        roadBFSQueue.pop();
        
        for(const int location : adjacentRoads[currentRoad.first])
        {
            const int nextCost = currentRoad.second + 1;
            if(shortestCosts[location] <= nextCost)
            {
                continue;
            }
            
            roadBFSQueue.push(make_pair(location, nextCost));
            shortestCosts[location] = nextCost;
        }
    }
    
    vector<int> answer;
    for(const int source : sources)
    {
        const int sourceCost = shortestCosts[source] == INT_MAX ? -1 : shortestCosts[source];
        answer.push_back(sourceCost);
    }
    
    return answer;
}
