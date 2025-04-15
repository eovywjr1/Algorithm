#include <bits/stdc++.h>

using namespace std;

int solution(string s)
{
    const int sSize = s.length();
    vector<vector<bool>> DP(sSize, vector<bool>(sSize, false));
    int answer = 1;
    
    for(int Index = 0; Index < sSize; ++Index)
    {
        DP[Index][Index] = true;
        
        if(Index > 0 && s[Index-1] == s[Index])
        {
            answer = 2;
            DP[Index-1][Index] = true;
        }
    }
    
    for(int PalindromeLength = 3; PalindromeLength <= sSize; ++PalindromeLength)
    {
        for(int LeftIndex = 0; LeftIndex <= sSize - PalindromeLength; ++LeftIndex)
        {
            const int RightIndex = LeftIndex + PalindromeLength - 1;
            
            if(DP[LeftIndex+1][RightIndex-1] && s[LeftIndex] == s[RightIndex])
            {
                answer = max(answer, PalindromeLength);
                DP[LeftIndex][RightIndex] = true;
            }
        }
    }
    
    return answer;
}
