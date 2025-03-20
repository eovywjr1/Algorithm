#include <bits/stdc++.h>

using namespace std;

struct RoadInfo
{
    int _expense = 0;
    int _i, _j = 0;
    bool _isVerticalRoad = false;
    
    RoadInfo(int expense, int i, int j, bool isVerticalRoad)
        : _expense(expense), _i(i), _j(j), _isVerticalRoad(isVerticalRoad)
    {}
};
    
int solution(vector<vector<int>> board) {
    const int boardSize = board.size();
    vector<vector<vector<int>>> minExpenseRoads(boardSize, vector<vector<int>>(boardSize, vector<int>(2, INT_MAX)));
    queue<RoadInfo> queue;
    const int lineExpense = 100;
    const int cornerExpense = 500;
    
    minExpenseRoads[0][0][0] = 0;
    minExpenseRoads[0][0][1] = 0;
    
    if(board[0][1] == 0){
        queue.push(RoadInfo(lineExpense, 0, 1, false));
        minExpenseRoads[0][1][1] = lineExpense;
    }
    
    if(board[1][0] == 0)
    {
        queue.push(RoadInfo(lineExpense, 1, 0, true));
        minExpenseRoads[1][0][0] = lineExpense;
    }
    
    const vector<int> dirI = {-1,1,0,0};
    const vector<int> dirJ = {0,0,-1,1};
    
    while(queue.empty() == false)
    {
        const RoadInfo currentRoad = queue.front();
        queue.pop();
        
        for(int i=0;i<4;++i)
        {
            const int nextI = currentRoad._i + dirI[i];
            const int nextJ = currentRoad._j + dirJ[i];
            
            if(nextI < 0 || nextI >= boardSize || nextJ < 0 || nextJ >= boardSize || board[nextI][nextJ])
            {
                continue;
            }
            
            const bool isVerticalRoad = i < 2 ? true : false;
            const bool isCorner = isVerticalRoad != currentRoad._isVerticalRoad ? true : false;
            const int plusExpense = isCorner ? cornerExpense + lineExpense : lineExpense;
            const int nextExpense = currentRoad._expense + plusExpense;
            const int verticalIndex = isVerticalRoad ? 0 : 1;
            
            if(minExpenseRoads[nextI][nextJ][verticalIndex] < nextExpense)
            {
                continue;
            }
            
            queue.push(RoadInfo(nextExpense, nextI, nextJ, isVerticalRoad));
            minExpenseRoads[nextI][nextJ][verticalIndex] = nextExpense;
        }
    }
    
    return min(minExpenseRoads[boardSize-1][boardSize-1][0], minExpenseRoads[boardSize-1][boardSize-1][1]);
}
