#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int>& a, vector<int>& b){
    return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
    sort(routes.begin(), routes.end(), compare);
    
    int cameraPosition = -30001;
    int answer = 0;
    
    for(const vector<int>& route : routes){
        if(route[0] <= cameraPosition && cameraPosition <= route[1])
            continue;
        
        cameraPosition = route[1];
        ++answer;
    }
    
    return answer;
}
