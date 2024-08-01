#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    priority_queue<int> workPQ;
    
    for(const int work : works){
        workPQ.push(work);
    }
    
    for(int remainWork = n; remainWork>0; --remainWork ){
        if(workPQ.empty())
            break;
        
        int maxRemainWork = workPQ.top();
        --maxRemainWork;
        
        workPQ.pop();
        
        if(maxRemainWork > 0)
            workPQ.push(maxRemainWork);
    }
    
    long long answer = 0;
    while(workPQ.empty()==false){
        const int maxRemainWork = workPQ.top();
        workPQ.pop();
        
        answer += maxRemainWork * maxRemainWork;
    }
    
    return answer;
}
