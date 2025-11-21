#include <bits/stdc++.h>

using namespace std;

int GCD(int a, int b)
{
    int Min = min(a,b);
    int Max = max(a,b);
    
    while(Max % Min != 0)
    {
        const int Remain = Max % Min;
        Max = Min;
        Min = Remain;
    }
    
    return Min;
}

int solution(vector<int> arr) {
    int LCM = 1;
    
    for(const int Number : arr)
    {
        const int GCDValue = GCD(LCM, Number);
        LCM = Number * LCM / GCDValue;
    }
    
    return LCM;
}
