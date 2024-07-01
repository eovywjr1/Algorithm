#include <string>
#include <vector>
#include <queue>

using namespace std;

int mapsHeight = 0;
int mapsWidth = 0;
int answer = 0;

const pair<int,int> BFS(const pair<int,int> startPoint, const vector<string>& maps, const char findText){
    const int dirI[4] = {-1,1,0,0};
    const int dirJ[4] = {0,0,-1,1};
    vector<vector<bool>> visited(100, vector<bool>(100, false));
    queue<pair<pair<int,int>, int>> queue;
    
    queue.push({startPoint, 0});
    visited[startPoint.first][startPoint.second] = true;
    
    while(queue.empty() == false){
        const pair<pair<int,int>, int> currentPoint = queue.front();
        const pair<int,int> currentIndex = currentPoint.first;
        
        if(maps[currentIndex.first][currentIndex.second] == findText){
            answer += currentPoint.second;
            return currentIndex;
        }
        
        queue.pop();
        
        for(int index=0;index<4;++index){
            const int nextI = currentIndex.first + dirI[index];
            const int nextJ = currentIndex.second + dirJ[index];
            
            if(nextI < 0 || mapsHeight <= nextI || nextJ < 0 || mapsWidth <= nextJ )
                continue;
            
            if(maps[nextI][nextJ] == 'X')
                continue;
            
            if(visited[nextI][nextJ]) // 이 if문이 없어서 방문한 포인트를 다시 방문해서 시간초과가 발생했습니다.
                continue;
            
            visited[nextI][nextJ] = true;
            queue.push({{nextI,nextJ}, currentPoint.second + 1});
        }
    }
    
    return {-1,-1};
}

int solution(vector<string> maps) {
    mapsHeight = maps.size();
    mapsWidth = maps[0].size();
    
    for(int i=0;i<mapsHeight;++i){
        for(int j=0;j<mapsWidth;++j){
            if(maps[i][j] == 'S'){
                const pair<int,int> lever = BFS({i,j}, maps, 'L');
                if(lever.first == -1)
                    return -1;
                
                const pair<int,int> exit = BFS(lever, maps, 'E');
                if(exit.first == -1)
                    return -1;
                
                return answer;
            }
        }
    }
    
    return -1;
}
