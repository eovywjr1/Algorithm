#include <vector>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    vector<int> entireQueue = queue1;
    entireQueue.insert(entireQueue.end(), queue2.begin(), queue2.end());
    
    long long firstQueueSum = 0;
    for(const int element : queue1)
        firstQueueSum += element;
    
    long long secondQueueSum = 0;
    for(const int element : queue2)
        secondQueueSum += element;
    
    if((firstQueueSum + secondQueueSum) % 2 != 0)
        return -1;
    
    int moveCount = 0;
    const int maxMoveCount = queue1.size() * 3;
    int queue1StartIndex = 0;
    int queue1EndIndex = queue1.size()-1;
    
    while(moveCount <= maxMoveCount){
        if(firstQueueSum == secondQueueSum)
            return moveCount;
        
        if(firstQueueSum < secondQueueSum){
            queue1EndIndex = ( queue1EndIndex + 1 ) % entireQueue.size();
            
            firstQueueSum += entireQueue[queue1EndIndex];
            secondQueueSum -= entireQueue[queue1EndIndex];
        }
        else{
            firstQueueSum -= entireQueue[queue1StartIndex];
            secondQueueSum += entireQueue[queue1StartIndex];
            
            queue1StartIndex = ( queue1StartIndex + 1 ) % entireQueue.size();
        }
        
        ++moveCount;
    }
    
    return -1;
}
