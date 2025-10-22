#include <string>
#include <vector>

using namespace std;

const int Mod = 1234567;

long long solution(int n) {
    vector<int> ArrivedCaseCount(n+1, 0);
    ArrivedCaseCount[0] = 0;
    ArrivedCaseCount[1] = 1;
    ArrivedCaseCount[2] = 2;
    
    for(int i=3;i<=n;++i)
    {
        ArrivedCaseCount[i] = (ArrivedCaseCount[i - 1] + ArrivedCaseCount[i - 2]) % Mod;
    }
    
    return ArrivedCaseCount[n];
}
