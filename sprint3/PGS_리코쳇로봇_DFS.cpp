#include <string>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

vector<vector<int>> countVector(100, vector<int>(100, INT_MAX));
int boardSize = 0;
int width = 0;
pair<int,int> goalIndex = {-1,-1};

void DFS(const vector<string>& board, const pair<int,int> indexPair, const int count){
    const vector<int> dirI({0,0,-1,1});
    const vector<int> dirJ({-1,1,0,0});
    
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
        
        if(board[i][j] == 'G')
            goalIndex = {i,j};
        
        if(count + 1 < countVector[i][j]){
            countVector[i][j] = count + 1;
            DFS(board, {i,j}, count + 1);
        }
    }
}

int solution(vector<string> board) {
    boardSize=board.size();
    width = board[0].length();
    
    for(int i=0;i<boardSize;++i){
        for(int j=0;j<width;++j){
            if(board[i][j] == 'R'){
                board[i][j] = 0;
                DFS(board, {i,j}, 0);
                
                if(goalIndex.first == -1)
                    return -1;
                
                return countVector[goalIndex.first][goalIndex.second];
            }
        }
    }
    
    return 0;
}
