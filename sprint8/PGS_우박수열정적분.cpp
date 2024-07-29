#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> areaVector(10000,0);
    int n = 0;
    
    while(k>1){
        int tempK = k;
        
        if(k%2 == 0)
            k/=2;
        else
            k = k*3+1;
        
        ++n;
        
        const int minY = min(tempK,k);
        const int maxY = max(tempK,k);
        areaVector[n] = areaVector[n-1] + minY + (maxY - minY) / 2.0f;
    }
    
    vector<double> answer;
    
    for(const vector<int>& range : ranges){
        const int x1 = range[0];
        const int x2 = n + range[1];
        
        if(x2<x1)
            answer.push_back(-1);
        else
            answer.push_back(areaVector[x2] - areaVector[x1]);
    }
    
    return answer;
}
