#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> Skills) {
    const int BoardHeight = board.size();
    const int BoardWeight = board[0].size();
    
    // +1을 하는 이유는 Skill 유효 범위 다음 인덱스에서 Skill의 Degree를 무효화하기 위함
    vector<vector<int>> AccumulateDegreeMarks(BoardHeight + 1, vector<int>(BoardWeight + 1, 0));
    
    for(const vector<int>& Skill : Skills)
    {
        const int Degree = Skill[0] == 1 ? Skill[5] * -1 : Skill[5];
        
        AccumulateDegreeMarks[Skill[1]][Skill[2]] += Degree;
        AccumulateDegreeMarks[Skill[1]][Skill[4] + 1] -= Degree;
        AccumulateDegreeMarks[Skill[3] + 1][Skill[2]] -= Degree;
        AccumulateDegreeMarks[Skill[3] + 1][Skill[4] + 1] += Degree;
    }
    
    for(int i = 0; i < BoardHeight; ++i)
    {
        for(int j = 0; j < BoardWeight; ++j)
        {
            AccumulateDegreeMarks[i][j + 1] += AccumulateDegreeMarks[i][j];
        }
    }
    
    for(int i = 0; i < BoardHeight; ++i)
    {
        for(int j = 0; j < BoardWeight; ++j)
        {
            AccumulateDegreeMarks[i + 1][j] += AccumulateDegreeMarks[i][j];
        }
    }
    
    int Answer = 0;
    
    for(int i = 0; i < BoardHeight; ++i)
    {
        for(int j = 0; j < BoardWeight; ++j)
        {
            if(board[i][j] + AccumulateDegreeMarks[i][j] > 0)
            {
                ++Answer;
            }
        }
    }
    
    return Answer;
}
