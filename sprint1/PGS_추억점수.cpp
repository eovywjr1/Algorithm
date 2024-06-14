#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    unordered_map<string,int> scoreNameMap;
    
    for(int index=0;index<name.size();++index){
        scoreNameMap[name[index]] = yearning[index];
    }
    
    for(vector<string> photoIt : photo){
        int score=0;
        
        for(string photoStr : photoIt){
            score += scoreNameMap[photoStr];
        }
        
        answer.push_back(score);
    }
    
    return answer;
}
