#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    const int sequenceSize=sequence.size();
    
    vector<int> answer = {0, sequenceSize-1};
    
    int startIndex=0;
    int endIndex=0;
    int sum = sequence[0];
    
    while(startIndex<=endIndex && endIndex<sequenceSize){
        if(sum<k){
            sum+=sequence[++endIndex];
        }
        else if(k<sum){
            sum-=sequence[startIndex++];
        }
        else{
            if(endIndex-startIndex < answer[1]-answer[0])
                answer={startIndex,endIndex};
            
            sum-=sequence[startIndex++];
        }
    }
    
    return answer;
}
