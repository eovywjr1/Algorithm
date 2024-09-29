#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

int dijkstra(const int cityCount, const int startCity, const int endCity, const vector<vector<pair<int, int>>>& busVector)
{
	const int invalidMoney = INT_MAX - 1;
	vector<int> minMoneyVector(cityCount + 1, invalidMoney);
	minMoneyVector[startCity] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> moneyPQ;
	moneyPQ.push({ 0, startCity });

	while (moneyPQ.empty() == false)
	{
		const pair<int, int> currentBus = moneyPQ.top();
		moneyPQ.pop();

		if (minMoneyVector[currentBus.second] < currentBus.first)
			continue;

		for (const pair<int, int>& nextBus : busVector[currentBus.second])
		{
			const int nextMoney = currentBus.first + nextBus.first;
			if (minMoneyVector[nextBus.second] <= nextMoney)
				continue;

			minMoneyVector[nextBus.second] = nextMoney;
			moneyPQ.push({ nextMoney, nextBus.second });
		}
	}

	return minMoneyVector[endCity];
}

int main()
{
	int N = 0, M = 0;
	cin >> N >> M;

	vector<vector<pair<int, int>>> busVector(N + 1);

	for (int busCount = 0; busCount < M; ++busCount)
	{
		int startCity = 0, endCity = 0, money = 0;
		cin >> startCity >> endCity >> money;

		busVector[startCity].push_back({ money, endCity });
	}

	int startCity = 0, endCity = 0;
	cin >> startCity >> endCity;

	cout << dijkstra(N, startCity, endCity, busVector);
}
