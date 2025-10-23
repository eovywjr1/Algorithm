#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N = 0;
	cin >> N;
	vector<int> Solutions(N);

	for (int i = 0; i < N; ++i)
	{
		cin >> Solutions[i];
	}

	int Left = 0;
	int Right = N - 1;
	int MinDistanceToZero = abs(Solutions[Left] + Solutions[Right]);
	pair<int, int> MinPair = make_pair(Solutions[Left], Solutions[Right]);
	
	while (Left < Right)
	{
		const int MidValue = Solutions[Left] + Solutions[Right];
		const int AbsMidValue = abs(MidValue);

		if (AbsMidValue < MinDistanceToZero)
		{
			MinDistanceToZero = AbsMidValue;
			MinPair = make_pair(Solutions[Left], Solutions[Right]);
		}

		if (MidValue < 0)
		{
			++Left;
		}
		else
		{
			--Right;
		}
	}

	cout << MinPair.first << ' ' << MinPair.second;
}
