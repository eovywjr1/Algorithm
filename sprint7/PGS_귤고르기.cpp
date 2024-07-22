#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int solution(int k, vector<int> tangerine) {
    unordered_map<int,int> tangerineCountMap;
    
    for(const int tangerineSize : tangerine){
        ++tangerineCountMap[tangerineSize];
    }
    
    priority_queue<pair<int,int>> tangerineSizePQ;
    for(auto it = tangerineCountMap.begin(); it != tangerineCountMap.end(); ++it){
        tangerineSizePQ.push({it->second,it->first});
    }
    
    int tangerineCount = 0;
    int answer = 0;
    
    while(tangerineCount < k){
        tangerineCount += tangerineSizePQ.top().first;
        tangerineSizePQ.pop();
        ++answer;
    }
    
    return answer;
}
