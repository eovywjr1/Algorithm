#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<vector<int>> Results) {
    vector<vector<bool>> WinRecord(n + 1, vector<bool>(n + 1, false));
    
    for(const vector<int> Result : Results)
    {
        WinRecord[Result[0]][Result[1]] = true;
    }
    
    for(int k = 1; k <= n; ++k)
    {
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j <= n; ++j)
            {
                if(WinRecord[i][k] && WinRecord[k][j])
                {
                    WinRecord[i][j] = true;
                }
            }
        }
    }
    
    int Answer = 0;
    
    for(int i = 1; i <= n; ++i)
    {
        int WinOrLossCount = 0;
        for(int j = 1; j <= n; ++j)
        {
            if(WinRecord[i][j] || WinRecord[j][i])
            {
                ++WinOrLossCount;
            }
        }
        
        if(WinOrLossCount == n - 1)
        {
            ++Answer;
        }
    }
    
    return Answer;
}
