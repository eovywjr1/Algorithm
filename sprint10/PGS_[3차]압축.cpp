#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<int> solution(string msg) {
    unordered_map<string, int> dictionary;
    const int alphabatCount = 'Z' - 'A';
    int index = 0;
    
    
    for(; index <= alphabatCount; ++index )
        dictionary[to_string('A' + index)] = index + 1; // A가 1부터 시작이므로 + 1
    
    index = 27; // Z가 26이므로 다음 index인 27로 변경
        
    vector<int> answer;
    
    for(int msgIndex = 0; msgIndex<msg.length();++msgIndex){
        string tempString = to_string(msg[msgIndex]);
        int existStringEndIndex = 1;
        int lastExistIndex = 0;
        
        while(dictionary.find(tempString) != dictionary.end()){
            lastExistIndex = dictionary[tempString];
            tempString += msg[msgIndex+existStringEndIndex];
            ++existStringEndIndex;
        }
        
        // while문을 벗어났을 때 등록된 글자가 아니므로 이전 글자까지 옮기기 위해 -1, for문에서도 더하고 있으므로 -1
        msgIndex += existStringEndIndex - 2; 
        
        answer.push_back(lastExistIndex);
        dictionary[tempString] = index;
        ++index;
    }
    
    return answer;
}
