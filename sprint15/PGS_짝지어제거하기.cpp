#include <bits/stdc++.h>

using namespace std;

int solution(string s)
{
    stack<char> RemainTexts;
    
    for(const char Text : s)
    {
        if(!RemainTexts.empty() && RemainTexts.top() == Text)
        {
            RemainTexts.pop();
        }
        else
        {
            RemainTexts.push(Text);
        }
    }

    return RemainTexts.empty() ? 1 : 0;
}
