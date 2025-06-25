#include <iostream>
#include <vector>
#include <map>
#include <limits.h>
#include <cmath>

using namespace std;

int N = 0, M = 0;
int ChickenCount = 0;
map<int, pair<int, int>> ChickenHandles;
vector<pair<int, int>> HomeIndexes;
int MinCityChickenDistance = INT_MAX;

vector<int> SelectedChickenHandle;

void FindMinCityChickenDistance()
{
	int CityChickenDistance = 0;

	for (const pair<int, int>& HomeIndex : HomeIndexes)
	{
		int ChickenDistance = INT_MAX;
		for(const int Handle : SelectedChickenHandle)
		{
			const int Distance = abs(ChickenHandles[Handle].first - HomeIndex.first) + abs(ChickenHandles[Handle].second - HomeIndex.second);
			ChickenDistance = min(ChickenDistance, Distance);
		}

		if (ChickenDistance != INT_MAX)
		{
			CityChickenDistance += ChickenDistance;
		}
	}

	MinCityChickenDistance = min(MinCityChickenDistance, CityChickenDistance);
}

void FindCombinationChicken(const int CurrentChickenHandle, const int Count)
{
	SelectedChickenHandle[Count] = CurrentChickenHandle;

	if (Count == M - 1)
	{
		FindMinCityChickenDistance();
		return;
	}

	for (int Handle = CurrentChickenHandle + 1; Handle < ChickenCount; ++Handle)
	{
		FindCombinationChicken(Handle, Count + 1);
	}
}

int main()
{
	cin >> N >> M;

	int ChickenIndex = 0;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			int CityNumber = 0;
			cin >> CityNumber;

			if (CityNumber == 2)
			{
				ChickenHandles[ChickenIndex] = { i,j };
				++ChickenIndex;
			}
			else if (CityNumber == 1)
			{
				HomeIndexes.push_back({ i,j });
			}
		}
	}

	ChickenCount = ChickenIndex;

	SelectedChickenHandle.resize(M);

	for (int Handle = 0; Handle < ChickenCount; ++Handle)
	{
		FindCombinationChicken(Handle, 0);
	}

	cout << MinCityChickenDistance;
}
