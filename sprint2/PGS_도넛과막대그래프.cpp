#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

unordered_map<int,vector<int>> inEdgePointMap;
unordered_map<int,vector<int>> outEdgePointMap;
unordered_map<int,bool> visitedPointMap;

const int maxPointNumber = 1000001;

int check(int startPoint){
    queue<int> checkQueue;
    checkQueue.push(startPoint);
    
    while(!checkQueue.empty()){
        const int currentPoint = checkQueue.front();
        checkQueue.pop();
        
        if(visitedPointMap[currentPoint])
            return 1;
        
        if(outEdgePointMap[currentPoint].size()==2)
            return 3;
            
        visitedPointMap[currentPoint]=true;
        
        for(int nextPoint : outEdgePointMap[currentPoint]){
            checkQueue.push(nextPoint);
        }
    }
    
    return 2;
}

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer(4, 0);
    vector<vector<int>> completedPointList;
    
    for(vector<int> edge : edges){
        outEdgePointMap[edge[0]].push_back(edge[1]);
        inEdgePointMap[edge[1]].push_back(edge[0]);
    }
    
    for(int pointNumber = 1; pointNumber<=maxPointNumber; ++pointNumber){
        const int inEdgePointSize = inEdgePointMap[pointNumber].size();
        
        if(inEdgePointSize!=0)
            continue;
        
        if(outEdgePointMap[pointNumber].size() <= 1)
            continue;
        
        answer[0]=pointNumber; 
            
        for(int nextEdge : outEdgePointMap[pointNumber]){
            const int resultIndex = check(nextEdge);
            ++answer[resultIndex];
        }
            
        break;
    }
    
    return answer;
}
