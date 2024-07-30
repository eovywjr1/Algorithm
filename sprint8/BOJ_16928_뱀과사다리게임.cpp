#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

unordered_map<int, int> ladderMap;
unordered_map<int, int> snakeMap;

int BFS()
{
	queue<pair<int,int>> queue;
	vector<bool> visitedVector(101, false);

	queue.push({ 1,0 });
	visitedVector[1] = true;

	while (queue.empty() == false)
	{
		const pair<int, int> currentRound = queue.front();
		queue.pop();

		const int currentNumber = currentRound.first;
		const int currentCount = currentRound.second;

		if (currentNumber == 100)
			return currentCount;

		for (int addNumber = 1; addNumber <= 6; ++addNumber)
		{
			int nextNumber = currentNumber + addNumber;

			if (snakeMap[nextNumber] != 0)
				nextNumber = snakeMap[nextNumber];

			if (ladderMap[nextNumber] != 0)
				nextNumber = ladderMap[nextNumber];

			if (nextNumber > 100 || visitedVector[nextNumber])
				continue;

			queue.push({ nextNumber,currentCount + 1 });
			visitedVector[nextNumber] = true;
		}
	}

	return 0;
}

int main()
{
	int N, M;
	cin >> N >> M;

	for (int index = 0; index < N; ++index)
	{
		int startNumber, endNumber;
		cin >> startNumber >> endNumber;

		ladderMap[startNumber] = endNumber;
	}

	for (int index = 0; index < M; ++index)
	{
		int startNumber, endNumber;
		cin >> startNumber >> endNumber;

		snakeMap[startNumber] = endNumber;
	}

	cout << BFS();
}
