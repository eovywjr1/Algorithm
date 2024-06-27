#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<vector<bool>> visited(100, vector<bool>(100, false));
int boardSize = 0;
int width = 0;

int BFS(const vector<string>& board, const pair<int,int> start){
    const vector<int> dirI({0,0,-1,1});
    const vector<int> dirJ({-1,1,0,0});
    queue<pair<pair<int,int>,int>> queue;
    queue.push({start,0});
    
    while(queue.empty() == false){
        const pair<pair<int,int>,int> currentPoint = queue.front();
        const pair<int,int> indexPair = currentPoint.first;
        queue.pop();
        
        if(board[indexPair.first][indexPair.second] == 'G')
            return currentPoint.second;
        
        for(int index=0;index<4;++index){
            int i = indexPair.first;
            int j = indexPair.second;
        
            while(true){
                const int nextI = i + dirI[index];
                const int nextJ = j + dirJ[index];
            
                if(nextI<0 || boardSize<=nextI || nextJ<0 || width<=nextJ || board[nextI][nextJ] == 'D')
                    break;
            
                i = nextI;
                j = nextJ;
            }
        
            if(i == indexPair.first && j == indexPair.second)
                continue;
        
            if(visited[i][j])
                continue;
            
            visited[i][j] = true;
            queue.push({{i,j}, currentPoint.second+1});
        }
    }
    
    return -1;
}

int solution(vector<string> board) {
    boardSize=board.size();
    width = board[0].length();
    
    for(int i=0;i<boardSize;++i){
        for(int j=0;j<width;++j){
            if(board[i][j] == 'R'){
                board[i][j] = true;
                return BFS(board, {i,j});
            }
        }
    }
    
    return 0;
}
