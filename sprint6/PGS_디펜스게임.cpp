#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> mujuckQueue;
    
    for( const int enemyCount : enemy)
    {
        if(n<=0)
            break;
        
        mujuckQueue.push(enemyCount);
        
        if(mujuckQueue.size() > k)
        {
            n -= mujuckQueue.top();
            mujuckQueue.pop();
        }
        
        ++answer;
    }
    
    if(n < 0)
        --answer;
    
    return answer;
}
