#include <bits/stdc++.h>

using namespace std;

int solution(string s) {
    const int sLength = s.length();
    const int MaxZipSize = sLength / 2;
    int answer = sLength;
    
    for(int ZipSize = 1; ZipSize <= MaxZipSize; ++ZipSize)
    {
        string TempString;
        int EqualCount = 1;
        
        for(int Index = 0; Index < sLength - ZipSize; Index += ZipSize)
        {
            const string LeftString = s.substr(Index, ZipSize);
            const string RightString = s.substr(Index + ZipSize, ZipSize);
            
            if(LeftString == RightString)
            {
                ++EqualCount;
            }
            else
            {
                if(EqualCount > 1)
                {
                    TempString += to_string(EqualCount);
                    EqualCount = 1;
                }
                TempString += LeftString;
            }
        }
        
        if(EqualCount > 1)
        {
            TempString += to_string(EqualCount);
            TempString += s.substr(sLength - ZipSize - 1, ZipSize);
        }
        else
        {
            const int RemainStringLength = sLength % ZipSize == 0 ? ZipSize : sLength % ZipSize;
            TempString += s.substr(sLength - RemainStringLength - 1, RemainStringLength);
        }
        
        answer = min(answer, static_cast<int>(TempString.length()));
    }
    
    return answer;
}
