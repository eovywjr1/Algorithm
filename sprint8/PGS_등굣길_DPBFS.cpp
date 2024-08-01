#include <string>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

constexpr int modNumber = 1000000007;

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<pair<int,int>>> leastDistanceCountVector(n,vector<pair<int,int>>(m, {INT_MAX-1,0}));
    leastDistanceCountVector[n-1][m-1]={0,1};
    
    vector<vector<bool>> puddlesMarkVector(n,vector<bool>(m, false));
    for(const vector<int> puddle : puddles){
        puddlesMarkVector[puddle[1]-1][puddle[0]-1] = true;
    }
    
    const vector<int> dirI({-1,0});
    const vector<int> dirJ({0,-1});
    vector<vector<bool>> vistedVector(n,vector<bool>(m, false));
    
    queue<pair<int,int>> queue;
    queue.push({n-1,m-1});
    vistedVector[n-1][m-1] = true;
    
    while(queue.empty()==false){
        const pair<int,int> currentIndex = queue.front();
        queue.pop();
        
        for(int index=0;index<2;++index){
            const int nextI = currentIndex.first + dirI[index];
            const int nextJ = currentIndex.second + dirJ[index];
            
            if(nextI < 0 || nextJ < 0)
                continue;
            
            const int nextIndexDistance = leastDistanceCountVector[nextI][nextJ].first;
            const int currentIndexDistance = leastDistanceCountVector[currentIndex.first][currentIndex.second].first;
            if(puddlesMarkVector[nextI][nextJ] || nextIndexDistance < currentIndexDistance + 1)
                continue;
            
            const int currentIndexPathCount = leastDistanceCountVector[currentIndex.first][currentIndex.second].second;
            if(nextIndexDistance == currentIndexDistance + 1)
                leastDistanceCountVector[nextI][nextJ].second = ( leastDistanceCountVector[nextI][nextJ].second + currentIndexPathCount ) % modNumber;
            else
                leastDistanceCountVector[nextI][nextJ] = {currentIndexDistance + 1, currentIndexPathCount};
            
            if(vistedVector[nextI][nextJ] == false){
                queue.push({nextI,nextJ});
                vistedVector[nextI][nextJ] = true;
            }
        }
    }
                     
    return leastDistanceCountVector[0][0].second;
}
