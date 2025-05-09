#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<int> money) {
    sort(money.begin(), money.end());
    
    vector<int> ExchangeMethodCounts(n + 1, 0);
    ExchangeMethodCounts[0] = 1;
    
    const int Mod = 1000000007;
    
    for(int Money : money)
    {
        for(int Cost = Money; Cost <= n; ++Cost)
        {
            ExchangeMethodCounts[Cost] = (ExchangeMethodCounts[Cost] + ExchangeMethodCounts[Cost - Money]) % Mod;
        }
    }
    
    return ExchangeMethodCounts[n];
}
