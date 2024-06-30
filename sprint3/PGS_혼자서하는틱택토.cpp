#include <string>
#include <vector>

using namespace std;

const int boardSize = 3;
int xCount =0;
int oCount =0;

bool isComplete(const char checkText, const vector<string>& board){
    for(int index=0;index<boardSize;++index){
        if(board[index][0] == checkText && board[index][1] == checkText && board[index][2] == checkText)
            return true;
        
        if(board[0][index] == checkText && board[1][index] == checkText && board[2][index] == checkText)
            return true;
    }
    
    if(board[0][0] == checkText && board[1][1] == checkText && board[2][2] == checkText)
        return true;
    
    if(board[0][2] == checkText && board[1][1] == checkText && board[2][0] == checkText)
        return true;
    
    return false;
}

void getTurnCount(const vector<string>& board){
    for(int i=0;i<boardSize;++i){
        for(int j=0;j<boardSize;++j){
            if(board[i][j] == 'O')
                ++oCount;
            else if(board[i][j] == 'X')
                ++xCount;
        }
    }
}

int solution(vector<string> board) {
    const bool isOComplete = isComplete('O', board);
    const bool isXComplete = isComplete('X', board);
    getTurnCount(board);
    
    if(isOComplete && isXComplete)
        return 0;
    
    if(oCount < xCount || xCount + 1 < oCount)
        return 0;
    
    if(isOComplete && oCount <= xCount)
        return 0;
    
    if(isXComplete && xCount < oCount)
        return 0;
    
    return 1;
}
