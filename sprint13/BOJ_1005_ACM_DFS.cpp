#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int N = 0, K = 0, T = 0, W = 0;
unordered_map<int, vector<int>> RequireBuildings;
unordered_map<int, long long> RequireTimes;

unordered_map<int, int> BuildTimes;

long long GetRequireBuildingTimesDFS(const int BuildingIndex)
{
	long long RequireSubTimes = 0;

	for (const int RequireBuilding : RequireBuildings[BuildingIndex])
	{
		auto RequireTime = RequireTimes.find(RequireBuilding);
		if (RequireTime != RequireTimes.end())
		{
			RequireSubTimes = max(RequireSubTimes, RequireTime->second);
		}
		else
		{
			RequireSubTimes = max(RequireSubTimes, GetRequireBuildingTimesDFS(RequireBuilding));
		}
	}

	RequireSubTimes += BuildTimes[BuildingIndex];
	RequireTimes[BuildingIndex] = RequireSubTimes;

	return RequireSubTimes;
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

		RequireBuildings.clear();
		BuildTimes.clear();
		RequireTimes.clear();

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

			RequireBuildings[Building].push_back(RequireBuilding);
		}

		cin >> W;

		cout << GetRequireBuildingTimesDFS(W) << '\n';
	}
}
