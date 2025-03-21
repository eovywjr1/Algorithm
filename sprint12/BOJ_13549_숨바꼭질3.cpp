#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0, K = 0;
	cin >> N >> K;

	const int maxPoint = 100000;
	const int distance = abs(N - K);
	vector<int> minTimesFindBrother(maxPoint + 1, INT_MAX);
	minTimesFindBrother[N] = 0;
	
	queue<int> queue;
	queue.push(N);

	while (queue.empty() == false)
	{
		const int currentPoint = queue.front();
		queue.pop();

		if (currentPoint == K || distance < abs(currentPoint - K) - minTimesFindBrother[currentPoint])
		{
			continue;
		}

		if (currentPoint < maxPoint && minTimesFindBrother[currentPoint] + 1 < minTimesFindBrother[currentPoint + 1])
		{
			minTimesFindBrother[currentPoint + 1] = minTimesFindBrother[currentPoint] + 1;
			queue.push(currentPoint + 1);
		}

		if (currentPoint > 0 && minTimesFindBrother[currentPoint] + 1 < minTimesFindBrother[currentPoint - 1])
		{
			minTimesFindBrother[currentPoint - 1] = minTimesFindBrother[currentPoint] + 1;
			queue.push(currentPoint - 1);
		}

		if (currentPoint * 2 <= maxPoint && minTimesFindBrother[currentPoint] < minTimesFindBrother[currentPoint * 2])
		{
			minTimesFindBrother[currentPoint * 2] = minTimesFindBrother[currentPoint];
			queue.push(currentPoint * 2);
		}
	}

	cout << minTimesFindBrother[K];
}
