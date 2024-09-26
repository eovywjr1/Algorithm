#include <vector>

using namespace std;

int solution(int n) {
    vector<int> fibonacciVector(n+1);
    fibonacciVector[0]=0;
    fibonacciVector[1]=1;
    
    for(int i=2;i<=n;++i){
        fibonacciVector[i] = (fibonacciVector[i-1] + fibonacciVector[i-2]) % 1234567;
    }
    
    return fibonacciVector[n];
}
