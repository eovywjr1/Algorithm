#include <bits/stdc++.h>

using namespace std;

vector<char> combinationString(10);

void getSubCombinationOrder(const string& order, vector<string>& combinations, const int combinationSize, const int startIndex, const int currentSize){
    if(currentSize == combinationSize){
        string s;
        for(int index = 0; index < combinationSize; ++index){
            s += combinationString[index];
        }
        
        combinations.push_back(s);
        
        return;
    }
    
    const int orderSize = order.length();
    for(int index = startIndex; index < order.length(); ++index){
        combinationString[currentSize] = order[index];
        
        getSubCombinationOrder(order, combinations, combinationSize, index + 1, currentSize + 1);
    }
}

void getCombinationOrder(const string& order, vector<string>& combinations)
{
    const int orderSize = order.length();
    for(int combinationSize = 2; combinationSize <= orderSize; ++combinationSize){
        getSubCombinationOrder(order, combinations, combinationSize, 0, 0);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    map<int, map<string, int>> subOrderCount;
    
    for(string& order : orders){
        sort(order.begin(), order.end());
        
        vector<string> combinations;
        getCombinationOrder(order, combinations);
        
        for(const string& combination : combinations){
            ++subOrderCount[combination.length()][combination];
        }
    }
    
    vector<string> answer;
    for(int orderSize : course){
        vector<string> temp;
        int maxCount = 0;
        
        for(const auto& subOrder : subOrderCount[orderSize]){
            if(subOrder.second < maxCount){
                continue;
            }
            else if(subOrder.second == maxCount){
                temp.push_back(subOrder.first);
            }
            else{
                temp.clear();
                maxCount = subOrder.second;
                temp.push_back(subOrder.first);
            }
        }
        
        if(maxCount>=2){
            for(const string& tempString : temp){
                answer.push_back(tempString);
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}
