#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

void FindAliquot(const int number, vector<int>& aliquotVector){
    const int sqrtNumber = sqrt(number);
    aliquotVector.push_back(1);
    aliquotVector.push_back(number);
    
    for(int tempNumber = 2;tempNumber < sqrtNumber; ++tempNumber){
        if(number % tempNumber == 0){
            aliquotVector.push_back(tempNumber);
            aliquotVector.push_back(number/tempNumber);
        }
    }
}

int FindMaxCondtionAnswer(const vector<int>& aliquotVector, const vector<int>& checkAliquotVector, const vector<int>& checkNotAliquotVector){
    size_t aliquotSize = aliquotVector.size();
    const size_t checkAliquotVectorSize = checkAliquotVector.size();
    const auto aliquotBegin = aliquotVector.begin();
    int MaxCondtionAnswer = 0;
    
    for(const int aliquot : aliquotVector){
        bool checkCondition = true;
        
        for(int index=0; index<checkAliquotVectorSize;++index ){
            if(checkAliquotVector[index] % aliquot != 0){
                checkCondition=false;
                break;
            }
            
            if(checkNotAliquotVector[index] % aliquot == 0){
                checkCondition=false;
                break;
            }
        }
        
        if(checkCondition)
            MaxCondtionAnswer = max(MaxCondtionAnswer, aliquot);
    }
    
    return MaxCondtionAnswer;
}


int solution(vector<int> arrayA, vector<int> arrayB) {
    sort(arrayA.begin(),arrayA.end());
    sort(arrayB.begin(),arrayB.end());
    
    vector<int> aliquotA;
    vector<int> aliquotB;
    FindAliquot(arrayA[0], aliquotA);
    FindAliquot(arrayB[0], aliquotB);
    
    int answer = 0;
    
    answer = FindMaxCondtionAnswer(aliquotA, arrayA, arrayB);
    answer = max(answer, FindMaxCondtionAnswer(aliquotB, arrayB, arrayA));
    
    return answer;
}
