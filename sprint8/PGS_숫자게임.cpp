#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int answer = 0;
    int aIndex = 0;
    for(const int b : B){
        if(A[aIndex] < b){
            ++aIndex;
            ++answer;
        }
    }
    
    return answer;
}
