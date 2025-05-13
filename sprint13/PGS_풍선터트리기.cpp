#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> a) {
    const int aSize = a.size();
    vector<int> LeftMin(aSize, INT_MAX);
    vector<int> RightMin(aSize, INT_MAX);
    
    LeftMin[0] = a[0];
    RightMin[aSize-1] = a[aSize-1];
    
    for(int Index = 1; Index < aSize; ++Index)
    {
        LeftMin[Index] = min(LeftMin[Index-1], a[Index]);
        RightMin[aSize-Index-1] = min(RightMin[aSize-Index], a[aSize-Index-1]);
    }
    
    int Answer = 0;
    
    for(int Index = 0; Index < aSize; ++Index)
    {
        int BiggerCount = 0;
        
        if(Index > 0 && LeftMin[Index-1] < a[Index])
        {
            ++BiggerCount;
        }
        
        if(Index + 1 < aSize && RightMin[Index+1] < a[Index])
        {
            ++BiggerCount;
        }
        
        if(BiggerCount < 2)
        {
            ++Answer;
        }
    }
    
    return Answer;
}
