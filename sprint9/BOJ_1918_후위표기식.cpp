#include <iostream>
#include <string>
#include <stack>

using namespace std;

int priorityOperator(char operatorText)
{
	switch (operatorText)
	{
	case '(':
	case ')':
		return 3;
	case '*':
	case '/':
		return 2;
	case '+':
	case '-':
		return 1;
	default:
		return 0;
	}
}

bool isOperator(char text)
{
	if (priorityOperator(text) != 0)
		return true;

	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string expression;
	cin >> expression;

	string answer = "";
	stack<char> operatorStack;

	for (const char text : expression)
	{
		if (isOperator(text) == false)
		{
			answer += text;

			continue;
		}

		if (text == ')')
		{
			while (operatorStack.empty() == false && operatorStack.top() != '(')
			{
				answer += operatorStack.top();
				operatorStack.pop();
			}
			operatorStack.pop();

			continue;
		}

		while (operatorStack.empty() == false && operatorStack.top() != '(' && priorityOperator(text) <= priorityOperator(operatorStack.top()))
		{
			answer += operatorStack.top();
			operatorStack.pop();
		}

		operatorStack.push(text);
	}

	while (operatorStack.empty() == false)
	{
		answer += operatorStack.top();
		operatorStack.pop();
	}

	cout << answer;
}
