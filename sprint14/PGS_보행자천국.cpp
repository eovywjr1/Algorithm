#include <bits/stdc++.h>

using namespace std;

int MOD = 20170805;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    int Dp[500][500][2] = {0};
    
    if(city_map[0][1] != 1)
    {
        Dp[0][1][1] = 1;
    }
    
    if(city_map[1][0] != 1)
    {
        Dp[1][0][0] = 1;
    }
    
    for(int i=0;i<m;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(city_map[i][j] == 1 || Dp[i][j][0] != 0 || Dp[i][j][1] != 0)
            {
                continue;
            }
            
            if(i>0)
            {
                Dp[i][j][0] = Dp[i-1][j][0];
                
                if(city_map[i-1][j] != 2)
                {
                    Dp[i][j][0] = (Dp[i][j][0] + Dp[i-1][j][1]) % MOD;
                }
            }
            
            if(j > 0)
            {
                Dp[i][j][1] = Dp[i][j-1][1];
                
                if(city_map[i][j-1] != 2)
                {
                    Dp[i][j][1] = (Dp[i][j][1] + Dp[i][j-1][0]) % MOD;
                }
            }
        }
    }
    
    return (Dp[m-1][n-1][0] + Dp[m-1][n-1][1]) % MOD;
}
