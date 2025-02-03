#include <bits/stdc++.h>

using namespace std;

struct OperatorPriority
{
public:
    OperatorPriority(int plusPriority, int minusPriority, int multiplyPriority)
        : _plusPriority(plusPriority), _minusPriority(minusPriority), _multiplyPriority(multiplyPriority)
    {}
    
    int _plusPriority = 0, _minusPriority = 0, _multiplyPriority = 0;
};

int getPrority(const char operatorChar, const OperatorPriority priority)
{
    switch(operatorChar)
    {
        case '*':
            {
                return priority._multiplyPriority;
            }
            case '+':
            {
                return priority._plusPriority;
            }
            case '-':
            {
                return priority._minusPriority;
            }
    }
    
    return 0;
}

long long calculateExpression(const long long num1, const long long num2, const char operatorChar)
{
    switch(operatorChar)
    {
        case '*':
            {
                return num2 * num1;
            }
            case '+':
            {
                return num2 + num1;
            }
            case '-':
            {
                return num2 - num1;
            }
    }
    
    return 0;
}

long long calculatePrice(const string expression, const OperatorPriority priority)
{
    stack<long long> numStack;
    stack<char> operatorStack;
    int num = 0;
    bool isFirstOperator = true;
    
    for(const char text : expression)
    {
        const int operatorPriority = getPrority(text, priority);
        if(operatorPriority != 0)
        {
            numStack.push(num);
            num = 0;
            
            if(isFirstOperator == false)
            {
                while(operatorStack.empty() == false && operatorPriority >= getPrority(operatorStack.top(), priority))
                {
                    const long long num1 = numStack.top();
                    numStack.pop();
                    const long long num2 = numStack.top();
                    numStack.pop();
                    
                    const long long calculateNum = calculateExpression(num1, num2, operatorStack.top());
                    operatorStack.pop();
                    
                    numStack.push(calculateNum);
                }
            }
            
            isFirstOperator = false;

            operatorStack.push(text);
        }
        else
        {
            num = num * 10 + text - '0';
        }
    }
    
    numStack.push(num);
    
    while(operatorStack.empty() == false)
    {
        const long long num1 = numStack.top();
        numStack.pop();
        const long long num2 = numStack.top();
        numStack.pop();
                    
        const long long calculateNum = calculateExpression(num1, num2, operatorStack.top());
        operatorStack.pop();
                    
        numStack.push(calculateNum);
    }
    
    return abs(numStack.top());
}

long long solution(string expression) {
    long long answer = 0;
    
    answer = max(answer, calculatePrice(expression, OperatorPriority(1,2,3)));
    answer = max(answer, calculatePrice(expression, OperatorPriority(1,3,2)));
    answer = max(answer, calculatePrice(expression, OperatorPriority(2,1,3)));
    answer = max(answer, calculatePrice(expression, OperatorPriority(2,3,1)));
    answer = max(answer, calculatePrice(expression, OperatorPriority(3,1,2)));
    answer = max(answer, calculatePrice(expression, OperatorPriority(3,2,1)));
    
    return answer;
}
