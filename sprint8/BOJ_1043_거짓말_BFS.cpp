#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0, M = 0;
	cin >> N >> M;

	int trueManCount = 0;
	cin >> trueManCount;

	unordered_map<int, bool> trueManMap;
	vector<vector<int>> partyVector(60, vector<int>(60, 0));

	for (int index = 0; index < trueManCount; ++index)
	{
		int number;
		cin >> number;

		trueManMap[number] = true;
	}

	queue<int> partyTrueManQueue;
	vector<bool> visitedPartyMan(51, false);

	for (int index = 0; index < M; ++index)
	{
		int partyManCount = 0;
		cin >> partyManCount;

		bool isExistTrueMan = false;
		for (int partyManIndex = 0; partyManIndex < partyManCount; ++partyManIndex)
		{
			cin >> partyVector[index][partyManIndex];

			if (trueManMap[partyVector[index][partyManIndex]])
				isExistTrueMan = true;
		}

		if (isExistTrueMan)
		{
			for (int partyManIndex = 0; partyManIndex < partyManCount; ++partyManIndex)
			{
				trueManMap[partyVector[index][partyManIndex]] = true;
				partyTrueManQueue.push(partyVector[index][partyManIndex]);
				visitedPartyMan[partyVector[index][partyManIndex]] = true;
			}
		}
	}

	while (partyTrueManQueue.empty() == false)
	{
		const int currentNumber = partyTrueManQueue.front();
		partyTrueManQueue.pop();

		for (int index = 0; index < M; ++index)
		{
			bool isExistTrueMan = false;

			if (find(partyVector[index].begin(), partyVector[index].end(), currentNumber) == partyVector[index].end())
				continue;

			for (const int partyNumber : partyVector[index])
			{
				if (partyNumber == 0)
					break;

				if (visitedPartyMan[partyNumber])
					continue;

				trueManMap[partyNumber] = true;
				partyTrueManQueue.push(partyNumber);
				visitedPartyMan[partyNumber] = true;
			}
		}
	}

	int answer = 0;

	for (int index = 0; index < M; ++index)
	{
		bool isExistTrueMan = false;
		for (const int partyNumber : partyVector[index])
		{
			if (trueManMap[partyNumber])
			{
				isExistTrueMan = true;
				break;
			}
		}

		if (isExistTrueMan == false)
		{
			++answer;
		}
	}

	cout << answer;
}
