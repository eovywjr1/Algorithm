#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> stones, int k) {
    deque<int> maxValueIndexSubPartition;
    
    for(int index=0;index<k;++index){
        while(maxValueIndexSubPartition.empty() == false && stones[maxValueIndexSubPartition.back()] <= stones[index]){
            maxValueIndexSubPartition.pop_back();
        }
        
        maxValueIndexSubPartition.push_back(index);
    }
    
    int answer = stones[maxValueIndexSubPartition.front()];
    
    const int stonesSize = stones.size();
    for(int index = k; index<stonesSize;++index){
        while(maxValueIndexSubPartition.empty() == false && maxValueIndexSubPartition.front() <= index-k){
            maxValueIndexSubPartition.pop_front();
        }
        
        while(maxValueIndexSubPartition.empty() == false && stones[maxValueIndexSubPartition.back()] <= stones[index]){
            maxValueIndexSubPartition.pop_back();
        }
        
        maxValueIndexSubPartition.push_back(index);
        
        answer = min(answer, stones[maxValueIndexSubPartition.front()]);
    }
    
    return answer;
}
