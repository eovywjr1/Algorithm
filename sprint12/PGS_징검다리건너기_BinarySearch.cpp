#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> stones, int k) {
    int start = *min_element(stones.begin(), stones.end());
    int end = *max_element(stones.begin(), stones.end());
    int answer = 0;
    
    while(start <= end){
        const int mid = (start + end) / 2;
        int skipStoneCount = 0;
        int maxSkipStoneCount = 0;
        vector<int> copiedStones(stones);
        
        for(int& stone : copiedStones){
            stone -= mid;
            if(stone < 0){
                ++skipStoneCount;
            }
            else{
                skipStoneCount = 0;
            }
            
            maxSkipStoneCount = max(maxSkipStoneCount, skipStoneCount);
        }
        
        if(maxSkipStoneCount < k){
            start = mid + 1;
            answer = max(answer, mid);
        }
        else{
            end = mid - 1;
        }
    }
    
    return answer;
}
