#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<bool>> visitedLand(500, vector<bool>(500, false));
unordered_map<int,int> landScore;
int landNSize;
int landMSize;
int answer=0;

bool isEnableLand(const int n, const int m, const vector<vector<int>>& land){
    if(land[n][m] == 0)
        return false;
                
    if(visitedLand[n][m])
        return false;
    
    return true;
}

void check(const int startNIndex, const int startMIndex, const vector<vector<int>>& land){
    queue<pair<int,int>> queue;
    queue.push({startNIndex,startMIndex});
    visitedLand[startNIndex][startMIndex] = true;
    
    const int dirN[4] = {0,0,-1,1};
    const int dirM[4] = {1,-1,0,0};
    
    int score = 0;
    int minMIndex = startMIndex;
    int maxMIndex = startMIndex;
    
    while(queue.empty() == false){
        const pair<int,int> currentIndex = queue.front();
        const int currentNIndex = currentIndex.first;
        const int currentMIndex = currentIndex.second;
        
        queue.pop();
        ++score;
        minMIndex = min(minMIndex, currentMIndex);
        maxMIndex = max(maxMIndex, currentMIndex);
        
        for(int index=0;index<4;++index){
            const int nextNIndex = currentNIndex+dirN[index];
            const int nextMIndex = currentMIndex+dirM[index];
                
            if(nextNIndex<0 || landNSize<=nextNIndex)
                continue;
                
            if(nextMIndex<0 || landMSize <= nextMIndex)
                continue;
            
            if(isEnableLand(nextNIndex, nextMIndex, land)==false)
                continue;
                
            queue.push({nextNIndex,nextMIndex});
            visitedLand[nextNIndex][nextMIndex] = true;
        }
    }
    
    for(int m = minMIndex; m<=maxMIndex; ++m){
        landScore[m] += score;
        answer = max(answer, landScore[m]);
    }
}

int solution(vector<vector<int>> land) {
    landNSize = land.size();
    landMSize = land[0].size();
    
    for(int m=0;m<landMSize;++m){
        for(int n=0;n<landNSize;++n){
            if(isEnableLand(n, m, land)==false)
                continue;
            
            check(n,m,land);
        }
    }
    
    return answer;
}
