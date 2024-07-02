#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    const int numbersSize = numbers.size();
    vector<int> answer(numbersSize);
    stack<int> backBigNumberStack;
    
    for(int index = numbersSize-1; index>=0; --index){
        const int currentNumber = numbers[index];
        
        while(backBigNumberStack.empty() == false){
            const int topNumber = backBigNumberStack.top();
            
            if(topNumber <= currentNumber )
                backBigNumberStack.pop();
            else
                break;
        }
        
        if(backBigNumberStack.empty() == false)
            answer[index]=backBigNumberStack.top();
        else
            answer[index]=-1;
        
        backBigNumberStack.push(currentNumber);
    }
    
    return answer;
}
