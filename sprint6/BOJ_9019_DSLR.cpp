#include <iostream>
#include <string>
#include <queue>

using namespace std;

int D(const int A)
{
	return A * 2 % 10000;
}

int S(const int A)
{
	if (A == 0)
		return 9999;

	return A - 1;
}

int L(const int A)
{
	const int d1 = A / 1000;
	const int d2 = A / 100 % 10;
	const int d3 = A / 10 % 10;
	const int d4 = A % 10;

	return d2 * 1000 + d3 * 100 + d4 * 10 + d1;
}

int R(const int A)
{
	const int d1 = A / 1000;
	const int d2 = A / 100 % 10;
	const int d3 = A / 10 % 10;
	const int d4 = A % 10;

	return d4 * 1000 + d1 * 100 + d2 * 10 + d3;
}

string DSLR(const int A, const int B)
{
	string answer;
	queue<pair<int, string>> queue;
	vector<bool> visited(10000, false);

	queue.push({ A,answer });
	visited[A] = true;

	while (queue.empty() == false)
	{
		const pair<int, string> currentCase = queue.front();
		queue.pop();

		const int currentNum = currentCase.first;
		const string currentString = currentCase.second;
		if (currentNum == B)
			return currentString;

		const int DNum = D(currentNum);
		if (visited[DNum] == false)
		{
			queue.push({ DNum, currentString + 'D' });
			visited[DNum] = true;
		}

		const int SNum = S(currentNum);
		if (visited[SNum] == false)
		{
			queue.push({ SNum, currentString + 'S' });
			visited[SNum] = true;
		}

		const int LNum = L(currentNum);
		if (visited[LNum] == false)
		{
			queue.push({ LNum, currentString + 'L' });
			visited[LNum] = true;
		}

		const int RNum = R(currentNum);
		if (visited[RNum] == false)
		{
			queue.push({ RNum, currentString + 'R' });
			visited[RNum] = true;
		}
	}

	return nullptr;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int Index = 0; Index < T;++Index)
	{
		int A, B;
		cin >> A >> B;

		string answer = DSLR(A, B);
		cout << answer << '\n';
	}
}
