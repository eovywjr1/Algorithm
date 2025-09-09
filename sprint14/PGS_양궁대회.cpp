#include <bits/stdc++.h>

using namespace std;

int ShootCount = 0;
vector<int>* InfosPtr = nullptr;
const int MaxScore = 10;

int MaxDiffRyanScore = 0;
vector<int> MaxRyanScoreShootedCounts = vector<int>(MaxScore + 1, 0);

void FindMaxDiffScore(const int CurrentShootCount, const int CurrentScore, const int RyanScore, const int ApeachScore, vector<int>& ShootedCount)
{
    if(CurrentScore == 0)
    {
        ShootedCount[MaxScore] += ShootCount - CurrentShootCount;
        
        const int DiffScore = RyanScore - ApeachScore;
        
        if(MaxDiffRyanScore < DiffScore)
        {
            MaxDiffRyanScore = DiffScore;
            MaxRyanScoreShootedCounts = ShootedCount;
        }
        else if(MaxDiffRyanScore == DiffScore)
        {
            for(int i = MaxScore; i >=0; --i)
            {
                if(MaxRyanScoreShootedCounts[i] != ShootedCount[i])
                {
                    if(MaxRyanScoreShootedCounts[i] < ShootedCount[i])
                    {
                        MaxRyanScoreShootedCounts = ShootedCount;
                    }
                    break;
                }
            }
        }
        
        ShootedCount[MaxScore] = 0;
        
        return;
    }
    
    const int ScoreIndex = MaxScore - CurrentScore;
    const int RequiredShootCount = (*InfosPtr)[ScoreIndex] + 1;
    const int NextShootCount = CurrentShootCount + RequiredShootCount;
    
    if(NextShootCount <= ShootCount)
    {
        ShootedCount[ScoreIndex] = RequiredShootCount;
        FindMaxDiffScore(NextShootCount, CurrentScore - 1, RyanScore + CurrentScore, ApeachScore, ShootedCount);
        ShootedCount[ScoreIndex] = 0;
    }
    
    const int AddApeachScore = (*InfosPtr)[ScoreIndex] > 0 ? CurrentScore : 0;
    FindMaxDiffScore(CurrentShootCount, CurrentScore - 1, RyanScore, ApeachScore + AddApeachScore, ShootedCount);
    ShootedCount[ScoreIndex] = 0;
}

vector<int> solution(int n, vector<int> Infos) {
    ShootCount = n;
    InfosPtr = &Infos;
    
    vector<int> InitialShootedCount(MaxScore + 1, 0);
    FindMaxDiffScore(0, MaxScore, 0, 0, InitialShootedCount);
    
    if(MaxDiffRyanScore <= 0)
    {
        return vector<int>{-1};
    }
    
    return MaxRyanScoreShootedCounts;
}
