#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> MinDistances;

void CalculateDistance(const int NodeCount)
{
    for(int k =1;k<=NodeCount;++k)
    {
        for(int i=1;i<=NodeCount;++i)
        {
            for(int j=1;j<=NodeCount;++j)
            {
                if(MinDistances[i][k] != INT_MAX && MinDistances[k][j] != INT_MAX)
                {
                    MinDistances[i][j] = min(MinDistances[i][j], MinDistances[i][k] + MinDistances[k][j]);
                }
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    MinDistances.resize(n + 1);
    for(int i=0;i<=n;++i)
    {
        MinDistances[i].resize(n + 1, INT_MAX);
        
        MinDistances[i][i] = 0;
    }
    
    for(const vector<int>& Fare : fares)
    {
        MinDistances[Fare[0]][Fare[1]] = Fare[2];
        MinDistances[Fare[1]][Fare[0]] = Fare[2];
    }
    
    CalculateDistance(n);
    
    int Answer = INT_MAX;
    
    for(int i=1;i<=n;++i)
    {
        Answer = min(Answer, MinDistances[s][i] + MinDistances[i][a] + MinDistances[i][b]);
    }
    
    return Answer;
}
