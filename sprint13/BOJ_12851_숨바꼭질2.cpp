#include <iostream>
#include <vector>
#include <limits.h>
#include <cmath>
#include <queue>

using namespace std;

int K = 0;
int MaxPathTime = 0;
int MaxPosition = 100000;
vector<pair<int, int>> PathTimes(100001, { INT_MAX,0 });

bool NextPosition(const int CurrentPosition, const int NextPosition)
{
	if (NextPosition > MaxPosition || NextPosition < 0)
	{
		return false;
	}

	const int NextTime = PathTimes[CurrentPosition].first + 1;

	if (NextTime < PathTimes[NextPosition].first)
	{
		PathTimes[NextPosition].first = NextTime;
		PathTimes[NextPosition].second = PathTimes[CurrentPosition].second;
	}
	else if (PathTimes[NextPosition].first == NextTime)
	{
		PathTimes[NextPosition].second += PathTimes[CurrentPosition].second;

		return false;
	}
	else
	{
		return false;
	}

	return true;
}

int main()
{
	int N = 0;
	cin >> N >> K;

	MaxPathTime = abs(K - N);

	if (K <= N)
	{
		cout << MaxPathTime << '\n' << 1;
		return 0;
	}

	PathTimes[N] = { 0,1 };
	
	queue<int> PositionQueue;
	PositionQueue.push(N);

	while (!PositionQueue.empty())
	{
		const int CurrentPosition = PositionQueue.front();
		PositionQueue.pop();

		if (NextPosition(CurrentPosition, CurrentPosition - 1))
		{
			PositionQueue.push(CurrentPosition - 1);
		}
		if (NextPosition(CurrentPosition, CurrentPosition + 1))
		{
			PositionQueue.push(CurrentPosition + 1);
		}
		if (NextPosition(CurrentPosition, CurrentPosition * 2))
		{
			PositionQueue.push(CurrentPosition * 2);
		}
	}

	cout << PathTimes[K].first << '\n' << PathTimes[K].second;
}
