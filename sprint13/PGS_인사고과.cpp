#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> Scores) {
    const pair<int,int> TargetResult = {Scores[0][0], Scores[0][1]};
    const int TargetSumScore = TargetResult.first + TargetResult.second;
    
    sort(Scores.begin(), Scores.end(), [](const vector<int>& lhs, const vector<int>& rhs)
         {
            if(lhs[0] == rhs[0])
            {
                return lhs[1] < rhs[1];
            }
             
             return rhs[0] < lhs[0];
         });
    
    int Answer = 1;
    int MaxCoworkScore = 0;
    
    for(const vector<int>& Score : Scores)
    {
        if(Score[1] < MaxCoworkScore)
        {
            if(Score[0] == TargetResult.first && Score[1] == TargetResult.second)
            {
                return -1;
            }
            
            continue;
        }
    
        MaxCoworkScore = max(MaxCoworkScore, Score[1]);
        
        if(TargetSumScore < Score[0] + Score[1])
        {
            ++Answer;
        }
    }
    
    return Answer;
}
