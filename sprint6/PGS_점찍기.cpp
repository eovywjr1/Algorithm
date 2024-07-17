#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    
    answer = d/k * 2 + 1;
    
    for(long long y=k; y< d;y+=k){
        answer += static_cast<long long>(sqrt( 1ll * d*d - y*y)) / k;
    }
    
    return answer;
}
