#include <bits/stdc++.h>

using namespace std;

long long solution(int n, vector<int> times) {
    sort(times.begin(), times.end());
    
    long long minTime = 1;
    long long maxTime = n * static_cast<long long>(times[times.size()-1]);
    long long answer = 0;
    
    while(minTime <= maxTime)
    {
        const long long midTime = (minTime + maxTime) / 2;
        long long enablePersonNum = 0;
        
        for(int time : times)
        {
            enablePersonNum += midTime / time;
        }
        
        if(enablePersonNum < n)
        {
            minTime = midTime + 1;
        }
        else
        {
            maxTime = midTime - 1;
            answer = midTime;
        }
    }
        
    return answer;
}
