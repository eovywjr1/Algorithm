#include <string>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

constexpr int invalidTired = INT_MAX;
constexpr int checkMineralCountPerOneTime = 5;
constexpr int pickSize = 3; 

int caculateTired(const int pickIndex, const string mineral){
    switch(pickIndex){
        case 0:{
            return 1;
        }
        case 1:{
            if(mineral == "diamond")
                return 5;
            
            return 1;
        }
        case 2:{
            if(mineral == "diamond")
                return 25;
            
            if(mineral == "iron")
                return 5;
            
            return 1;
        }   
    }
    
    return 0;
}

int checkTired(const int mineralIndex, const int pickIndex, vector<int> picks, const vector<string>& minerals){
    const int mineralSize = minerals.size();
    if(mineralSize <= mineralIndex )
        return 0;
    
    int tired = 0;
    for(int index = mineralIndex; index<mineralSize && index<mineralIndex+checkMineralCountPerOneTime; ++index){
        tired += caculateTired(pickIndex, minerals[index]);
    }
    
    int minNextTired=invalidTired;
    for(int index=0;index<pickSize;++index){
        if(picks[index] == 0)
            continue;
        
        --picks[index];
        minNextTired = min(minNextTired, checkTired(mineralIndex+checkMineralCountPerOneTime, index, picks, minerals));
        ++picks[index];
    }
    
    if(minNextTired != invalidTired)
        tired += minNextTired;
    
    return tired;
}

int solution(vector<int> picks, vector<string> minerals) {
    int answer = invalidTired;
    
    for(int index=0;index<pickSize;++index){
        if(picks[index] == 0)
            continue;
        
        --picks[index];
        answer = min(answer, checkTired(0, index, picks, minerals));
        ++picks[index];
    }
    
    return answer;
}
