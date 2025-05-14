#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int N = 0, K = 0, T = 0, W = 0;
unordered_map<int, vector<int>> NextBuildings;
vector<int> Indegree;
unordered_map<int, long long> RequireTimes;
unordered_map<int, int> BuildTimes;

void FindBuildTimes()
{
	queue<int> BuildingQueue;

	for (int BuildIndex = 1; BuildIndex <= N; ++BuildIndex)
	{
		if (Indegree[BuildIndex] == 0)
		{
			BuildingQueue.push(BuildIndex);
			RequireTimes[BuildIndex] = BuildTimes[BuildIndex];
		}
	}

	while (!BuildingQueue.empty())
	{
		const int CurrentBuilding = BuildingQueue.front();
		BuildingQueue.pop();

		for (const int NextBuilding : NextBuildings[CurrentBuilding])
		{
			RequireTimes[NextBuilding] = max(RequireTimes[NextBuilding], RequireTimes[CurrentBuilding] + static_cast<long long>(BuildTimes[NextBuilding]));

			--Indegree[NextBuilding];
			if (Indegree[NextBuilding] == 0)
			{
				BuildingQueue.push(NextBuilding);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> T;

	for(int TestIndex = 0; TestIndex < T; ++TestIndex)
	{
		cin >> N >> K;

		NextBuildings.clear();
		BuildTimes.clear();
		RequireTimes.clear();
		
		Indegree = vector<int>(N + 1, 0);

		for (int BuildingIndex = 1; BuildingIndex <= N; ++BuildingIndex)
		{
			int BuildTime = 0;
			cin >> BuildTime;

			BuildTimes[BuildingIndex] = BuildTime;
		}

		for (int RequireIndex = 0; RequireIndex < K; ++RequireIndex)
		{
			int RequireBuilding = 0, Building = 0;
			cin >> RequireBuilding >> Building;

			NextBuildings[RequireBuilding].push_back(Building);
			++Indegree[Building];
		}

		cin >> W;

		FindBuildTimes();

		cout << RequireTimes[W] << '\n';
	}
}
