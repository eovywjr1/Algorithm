#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int>& a, vector<int>& b){
    return a[1] < b[1];
}

int solution(vector<vector<int>> targets) {
    int answer=0;
    int prevFire=-1;
    
    sort(targets.begin(), targets.end(), compare);
    
    for(const vector<int>& target : targets){
        if(prevFire <= target[0]){
            ++answer;
            prevFire = target[1];
        }
    }
    
    return answer;
}
