#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
    deque<int> deque;
    
    for(const string operation : operations){
        char operationChar;
        int number = 0;
        stringstream ss(operation);
        ss >> operationChar;
        ss >> number;
        
        if(operationChar == 'I'){
            deque.push_back(number);
            sort(deque.begin(), deque.end());
        }
        else if (deque.empty() == false ){
            if(operation[2] == '-'){
                deque.pop_front();
            }
            else{
                deque.pop_back();
            }
        }
    }
    
    vector<int> answer(2,0);
    if(deque.empty() == false){
        answer[0] = deque.back();
        answer[1] = deque.front();
    }
    
    return answer;
}
