#include <string>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

int getIntMinute(const string& record){
    return ((record[0]-'0') * 10 + record[1]-'0' ) * 60 + (record[3]-'0') * 10 + record[4]-'0';
}

string getCarNumber(const string& record){
    string carNumber;
    
    for(int recordIndex = 6; recordIndex <= 9; ++recordIndex){
        carNumber += record[recordIndex];
    }
    
    return carNumber;
}

bool checkInPark(const string& record){
    if(record[11] == 'I')
        return true;
    
    return false;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    unordered_map<string, int> enterTimeMap;
    map<string, int> parkTimeMap;
    
    for(const string& record : records){
        const int minuteTime = getIntMinute(record);
        const string carNumber = getCarNumber(record);
        const bool isInPark = checkInPark(record);
        
        if(isInPark){
            enterTimeMap[carNumber]= minuteTime;
        }
        else{
            parkTimeMap[carNumber] += minuteTime - enterTimeMap[carNumber];
            enterTimeMap.erase(carNumber);
        }
    }
    
    for(const pair<const string, int>& enterTime : enterTimeMap){
        parkTimeMap[enterTime.first] += 23 * 60 + 59 - enterTime.second;
    }
    
    vector<int> answer;
    
    for(const pair<const string, int>& parkTime : parkTimeMap){
        int remainUnitTime = 0;
        
        if(parkTime.second - fees[0] > 0){
            remainUnitTime = (parkTime.second - fees[0]) / fees[2];
            
            if((parkTime.second - fees[0]) % fees[2] != 0)
                ++remainUnitTime;
        }
        
        answer.emplace_back(fees[1] + remainUnitTime * fees[3]);
    }
    
    return answer;
}
