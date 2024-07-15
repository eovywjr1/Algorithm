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
        
        if(k > 0)
        {
            --k;
            mujuckQueue.push(enemyCount);
        }
        else
        {
            const int minEnemy = mujuckQueue.top();
            if(minEnemy < enemyCount)
            {
                n -= minEnemy;
                mujuckQueue.pop();
                mujuckQueue.push(enemyCount);
            }
            else
            {
                n -= enemyCount;
            }
        }
        
        ++answer;
    }
    
    if(n < 0)
        --answer;
    
    return answer;
}
