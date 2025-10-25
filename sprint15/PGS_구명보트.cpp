#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> people, int limit) {
    sort(people.begin(), people.end());
    
    int answer = 0;
    int LeftIndex = 0, RightIndex = people.size() - 1;
    
    while(LeftIndex <= RightIndex)
    {
        if(people[LeftIndex] + people[RightIndex] <= limit)
        {
            ++LeftIndex;
        }
        
        --RightIndex;
        ++answer;
    }
    
    return answer;
}
