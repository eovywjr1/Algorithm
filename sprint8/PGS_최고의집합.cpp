#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    if(s < n){
        vector<int> answer({-1});
        return answer;
    }
    
    vector<int> answer(n, s/n);
    int remainNumber = s%n;
    
    for(int index = answer.size() - 1; remainNumber>0; --index, --remainNumber){
        ++answer[index];
    }
    
    return answer;
}
