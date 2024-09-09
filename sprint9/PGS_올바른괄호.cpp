#include <string>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<char> bracketStack;
    for(const char text : s){
        if(text == '('){
            bracketStack.push(text);
        }
        else{
            if(bracketStack.empty())
                return false;
            
            bracketStack.pop();
        }
            
    }
    
    return (bracketStack.empty()) ? true : false;
}
