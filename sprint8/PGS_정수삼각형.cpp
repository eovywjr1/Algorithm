#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(vector<vector<int>> triangle) {
    vector<vector<int>> sumMaxVector(500,vector<int>(500, 0));
    sumMaxVector[0][0] = triangle[0][0];
    
    const int triangleSize = triangle.size();
    for(int i = 0; i<triangleSize-1; ++i){
        const int lineSize = triangle[i].size();
        for(int j = 0;j<lineSize;++j){
            sumMaxVector[i+1][j] = max(sumMaxVector[i+1][j], sumMaxVector[i][j] + triangle[i+1][j]);
            sumMaxVector[i+1][j+1] = max(sumMaxVector[i+1][j+1], sumMaxVector[i][j] + triangle[i+1][j+1]);
        }
    }
    
    int answer=0;
    const int triangleLastLineSize = triangle[triangleSize-1].size();
    for(int index=0;index<triangleLastLineSize;++index){
        answer=max(answer,sumMaxVector[triangleSize-1][index]);
    }
    
    return answer;
}
