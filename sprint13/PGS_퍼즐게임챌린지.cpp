#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int LeftLevel = 1, RightLevel = 100000;
    const int PuzzleCount = diffs.size();
    int Answer = 0;
    
    while(LeftLevel < RightLevel)
    {
        const int MidLevel = (LeftLevel + RightLevel) / 2;
        long long SumTimes = 0;
        
        for(int PuzzleIndex = 0; PuzzleIndex < PuzzleCount; ++PuzzleIndex)
        {
            SumTimes += times[PuzzleIndex];
            
            if(MidLevel < diffs[PuzzleIndex])
            {
                SumTimes += (times[PuzzleIndex] + times[PuzzleIndex - 1]) * (diffs[PuzzleIndex] - MidLevel);
            }
        }
        
        if(limit < SumTimes)
        {
            LeftLevel = MidLevel + 1;
        }
        else if(SumTimes < limit)
        {
            RightLevel = MidLevel;
        }
        else
        {
            return MidLevel;
        }
    }
    
    return RightLevel;
}
