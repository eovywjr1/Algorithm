#include <string>
#include <vector>
#include <array>
#include <set>
#include <algorithm>

using namespace std;

const char emptyString = 'i';

void check2x2Block(const vector<string>& board, set<pair<int,int>>& deleteBlockSet){
    const int boardSize = board.size();
    const int boardWidth = board[0].length();
    const array<pair<int,int>,4> checkIndexArray{pair<int,int>(0,0),pair<int,int>(0,1),pair<int,int>(1,0),pair<int,int>(1,1)};
    
    for(int boardFirstIndex = 0; boardFirstIndex < boardSize; ++boardFirstIndex ){
        for(int boardSecondIndex = 0; boardSecondIndex < boardWidth; ++boardSecondIndex){
            if(board[boardFirstIndex][boardSecondIndex] == emptyString)
                continue;
            
            bool is2x2DeleteBlock = true;
            for(int checkIndex = 0; checkIndex < checkIndexArray.size(); ++checkIndex){
                const int nextFirstIndex = checkIndexArray[checkIndex].first + boardFirstIndex;
                const int nextSecondIndex = checkIndexArray[checkIndex].second + boardSecondIndex;
                
                if(boardSize <= nextFirstIndex || boardWidth <= nextSecondIndex || board[boardFirstIndex][boardSecondIndex] != board[nextFirstIndex][nextSecondIndex]){
                    is2x2DeleteBlock = false;
                    break;
                }
            }
            
            if(is2x2DeleteBlock){
                for(int checkIndex = 0; checkIndex < checkIndexArray.size(); ++checkIndex)
                    deleteBlockSet.insert(pair<int,int>(boardFirstIndex + checkIndexArray[checkIndex].first, boardSecondIndex + checkIndexArray[checkIndex].second));
            }
        }
    }
}

int deleteBlockAndDropBlockAndGetDeleteCount(vector<string>& board, const set<pair<int,int>>& deleteBlockSet){
    if(deleteBlockSet.empty())
        return 0;
    
    for(const pair<int,int>& deleteBlock : deleteBlockSet)
        board[deleteBlock.first][deleteBlock.second] = emptyString;
    
    const int boardSize = board.size();
    const int boardWidth = board[0].length();
    
    for(int boardSecondIndex = 0; boardSecondIndex < boardWidth; ++boardSecondIndex){
        for(int boardFirstIndex = boardSize - 2; boardFirstIndex >= 0; --boardFirstIndex ){
            if(board[boardFirstIndex][boardSecondIndex] == emptyString)
                continue;
            
            int tempBoardFirstIndex = boardFirstIndex + 1;
            
            while(tempBoardFirstIndex < boardSize && board[tempBoardFirstIndex][boardSecondIndex] == emptyString){
                swap(board[tempBoardFirstIndex-1][boardSecondIndex], board[tempBoardFirstIndex][boardSecondIndex]);
                
                ++tempBoardFirstIndex;
            }
        }
    }
    
    return deleteBlockSet.size();
}

int solution(int m, int n, vector<string> board) {
    int deleteCount = 0;
    
    while(true){
        set<pair<int,int>> deleteBlockSet;
        
        check2x2Block(board, deleteBlockSet);
        
        int tempDeleteCount = deleteBlockAndDropBlockAndGetDeleteCount(board, deleteBlockSet);
        
        if(tempDeleteCount == 0)
            return deleteCount;
        
        deleteCount += tempDeleteCount;
    }
    
    return 0;
}
