#include <bits/stdc++.h>

using namespace std;

long long solution(vector<int> sequence) {
    const int sequenceSize = sequence.size();
    vector<long long> dp1(sequenceSize); // 1로 시작하는 펄스의 부분 수열의 합
    vector<long long> dp2(sequenceSize); // -1로 시작하는 펄스의 부분 수열의 합
    int pulse1 = 1;
    int pulse2 = -1;
    
    dp1[0] = sequence[0] * pulse1;
    dp2[0] = sequence[0] * pulse2;
    pulse1 *= -1;
    pulse2 *= -1;
    
    long long answer = max(dp1[0], dp2[0]);
    
    for(int index = 1; index < sequenceSize; ++index)
    {
        const long long pulseNum1 = sequence[index] * pulse1;
        dp1[index] = max(dp1[index-1] + pulseNum1, pulseNum1);
        answer = max(answer, dp1[index]);
        pulse1 *= -1;
        
        const long long pulseNum2 = sequence[index] * pulse2;
        dp2[index] = max(dp2[index-1] + pulseNum2, pulseNum2);
        answer = max(answer, dp2[index]);
        pulse2 *= -1;
    }
    
    return answer;
}
