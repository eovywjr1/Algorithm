#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> elements) {
    const int ElementSize = elements.size();
    unordered_set<int> SequenceNumber;
    
    for(int StartIndex = 0; StartIndex < ElementSize; ++StartIndex)
    {
        int Sum = 0;
        
        for(int Index = StartIndex; Index < StartIndex + ElementSize; ++Index)
        {
            const int RealIndex = Index % ElementSize;
            Sum += elements[RealIndex];
            SequenceNumber.insert(Sum);
        }
    }
    
    return SequenceNumber.size();
}
