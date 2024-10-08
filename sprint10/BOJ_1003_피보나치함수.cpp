#include <iostream>
#include <array>

using namespace std;

constexpr int maxNum = 40;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	array<pair<int, int>, 41> zeroAndOneCountAtFibonacci;
	zeroAndOneCountAtFibonacci[0] = { 1, 0 };
	zeroAndOneCountAtFibonacci[1] = { 0, 1 };

	int testCount = 0;
	cin >> testCount;

	for (int num = 2; num <= maxNum; ++num)
	{
		zeroAndOneCountAtFibonacci[num].first = zeroAndOneCountAtFibonacci[num - 1].first + zeroAndOneCountAtFibonacci[num - 2].first;
		zeroAndOneCountAtFibonacci[num].second = zeroAndOneCountAtFibonacci[num - 1].second + zeroAndOneCountAtFibonacci[num - 2].second;
	}

	for (int testIndex = 0; testIndex < testCount; ++testIndex)
	{
		int testNum = 0;
		cin >> testNum;

		cout << zeroAndOneCountAtFibonacci[testNum].first << ' ' << zeroAndOneCountAtFibonacci[testNum].second << '\n';
	}
}
