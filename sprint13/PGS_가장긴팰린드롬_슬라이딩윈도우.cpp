#include <bits/stdc++.h>

using namespace std;

int GetPalindromeLegnth(const string& String, int LeftIndex, int RightIndex)
{
    const int StringSize = String.length();
    
    while(LeftIndex >= 0 && RightIndex < StringSize)
    {
        if(String[LeftIndex] != String[RightIndex])
        {
            break;
        }
        
        --LeftIndex;
        ++RightIndex;
    }
    
    return RightIndex - LeftIndex - 1;
}

int solution(string s)
{
    const int sSize = s.length();
    int answer = 1;
    
    for(int Index = 0; Index < sSize; ++Index)
    {
        const int OddLengthPalindrome = GetPalindromeLegnth(s, Index, Index);
        answer = max(answer, OddLengthPalindrome);
        
        const int EvenLengthPalindrome = GetPalindromeLegnth(s, Index, Index+1);
        answer = max(answer, EvenLengthPalindrome);
    }
    
    return answer;
}
