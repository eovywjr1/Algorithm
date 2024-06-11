#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> board, int h, int w) {
    const int boardSize = board.size();
    int answer = 0;
    const int dh[4] = {0,0,-1,1};
    const int dw[4] = {-1,1,0,0};
    string selectColor = board[h][w];
    
    for(int i=0;i<4;i++){
        const int selectedHIndex = h+dh[i];
        const int selectedWIndex = w+dw[i];
        
        if(selectedHIndex<0 || boardSize<=selectedHIndex)
            continue;
        if(selectedWIndex<0 || boardSize<=selectedWIndex)
            continue;
        
        if(board[selectedHIndex][selectedWIndex] ==selectColor )
            ++answer;
    }
    
    return answer;
}
