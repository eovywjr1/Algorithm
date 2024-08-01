#include <string>
#include <vector>

using namespace std;

constexpr int modNumber = 1000000007;

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int>> leastDistanceCountVector(n,vector<int>(m, 0));
    leastDistanceCountVector[0][0]=1;
    
    for(const vector<int> puddle : puddles){
        leastDistanceCountVector[puddle[1]-1][puddle[0]-1] = -1;
    }
    
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(leastDistanceCountVector[i][j] == -1)
                continue;
            
            if(i>0 && leastDistanceCountVector[i-1][j] != -1)
                leastDistanceCountVector[i][j] += leastDistanceCountVector[i-1][j];
            
            if(j>0 && leastDistanceCountVector[i][j-1] != -1)
                leastDistanceCountVector[i][j] = (leastDistanceCountVector[i][j] + leastDistanceCountVector[i][j-1] ) % modNumber;
        }
    }
                
    return leastDistanceCountVector[n-1][m-1];
}
