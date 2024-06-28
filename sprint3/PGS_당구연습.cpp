#include <string>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

int getDistance(const int x1, const int y1, int x2, int y2){
    return (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
}

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    
    for(const vector<int>& ball : balls){
        int minDistance = INT_MAX;
        const int ballX = ball[0];
        const int ballY = ball[1];
        vector<bool> enableSideVector(4, true); 
            
        if(startX == ballX){
            if(startY < ballY)
                enableSideVector[0] = false;
            else 
                enableSideVector[1] = false;
        }
        
        if(startY == ballY){
            if(startX < ballX)
                enableSideVector[3] = false;
            else
                enableSideVector[2] = false;
        }
        
        if(enableSideVector[0]){
            const int topSideMoveY = ball[1] + (n - ball[1]) * 2;
            minDistance = min(minDistance, getDistance(startX, startY, ball[0], topSideMoveY));
        }
                              
        if(enableSideVector[1]){
            const int bottomSideMoveY = ball[1] * -1;
            minDistance = min(minDistance, getDistance(startX, startY, ball[0], bottomSideMoveY));
        }
        
        if(enableSideVector[2]){
            const int leftSideMoveY = ball[0] * -1;
            minDistance = min(minDistance, getDistance(startX, startY, leftSideMoveY, ball[1]));
        }
            
        if(enableSideVector[3]){
            const int rightSideMoveY = ball[0] + (m - ball[0]) * 2;
            minDistance = min(minDistance, getDistance(startX, startY, rightSideMoveY, ball[1]));
        }
        
        answer.push_back(minDistance);
    }
    
    return answer;
}
