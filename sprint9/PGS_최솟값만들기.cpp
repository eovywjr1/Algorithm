#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B)
{
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<int>());
    
    const int numSize = A.size();
    
    int answer = 0;
    for(int index=0;index<numSize;++index){
        answer += A[index] * B[index];
    }

    return answer;
}
