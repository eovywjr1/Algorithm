#include <string>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

const int invalidTired = INT_MAX;

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

int checkTired(const int mineralIndex, const int pickIndex, vector<int> remainPicks, const vector<string>& minerals){
    const int mineralSize = minerals.size();
    if(mineralSize <= mineralIndex )
        return 0;
    
    int tired = 0;
    for(int index = mineralIndex; index<mineralSize && index<mineralIndex+5; ++index){
        tired += caculateTired(pickIndex, minerals[index]);
    }
    
    if(remainPicks[0] == 0 && remainPicks[1] == 0 && remainPicks[2] == 0)
        return tired;
    
    int minNextTired=invalidTired;
    for(int index=0;index<3;++index){
        if(remainPicks[index] == 0)
            continue;
        
        vector<int> remainTempPicks(remainPicks);
        --remainTempPicks[index];
        
        minNextTired = min(minNextTired, checkTired(mineralIndex+5, index, remainTempPicks, minerals));
    }
    
    return tired + minNextTired;
}

int solution(vector<int> picks, vector<string> minerals) {
    int answer = invalidTired;
    
    for(int index=0;index<3;++index){
        if(picks[index] == 0)
            continue;
        
        vector<int> remainTempPicks(picks);
        --remainTempPicks[index];
        
        answer = min(answer, checkTired(0, index, remainTempPicks, minerals));
    }
    
    return answer;
}
