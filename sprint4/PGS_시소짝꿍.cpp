#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    unordered_map<int,int> weightMap;
    
    for(const int weight : weights){
        ++weightMap[weight];
    }
    
    for(const int weight : weights){
        if(weight % 2 == 0)
            answer += (long long)(weightMap[weight/2]);
        
        if(weight % 3 == 0)
            answer += (long long)(weightMap[weight*2/3]);
        
        if(weight % 4 == 0)
            answer += (long long)(weightMap[weight*3/4]);
    }
    
    for(auto it = weightMap.begin(); it!=weightMap.end(); ++it){
        const long long weightCount = it->second;
        answer += (long long)(weightCount * (weightCount - 1) / 2);
    }
    
    return answer;
}
