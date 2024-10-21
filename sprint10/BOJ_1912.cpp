#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int numCount = 0;
	cin >> numCount;

	vector<int> numVector(numCount, 0);

	for (int numIndex = 0; numIndex < numCount; ++numIndex)
	{
		cin >> numVector[numIndex];
	}

	vector<int> consecutiveSumVector(numCount);
	consecutiveSumVector[0] = numVector[0];

	int maxConsecutiveSum = consecutiveSumVector[0];

	for (int numIndex = 1; numIndex < numCount; ++numIndex)
	{
		if (consecutiveSumVector[numIndex - 1] < 0)
			consecutiveSumVector[numIndex] = numVector[numIndex];
		else
			consecutiveSumVector[numIndex] = consecutiveSumVector[numIndex - 1] + numVector[numIndex];

		maxConsecutiveSum = max(maxConsecutiveSum, consecutiveSumVector[numIndex]);
	}

	cout << maxConsecutiveSum;
}
