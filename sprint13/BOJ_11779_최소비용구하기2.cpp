#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <limits.h>

using namespace std;

struct PathData
{
	int Cost = INT_MAX, PreviousCity = 0;
};

struct BusData
{
public:
	BusData(int InDestination, int InCost)
		: Destination(InDestination)
		, Cost(InCost)
	{}

	int Destination = 0, Cost = 0;
};

unordered_map<int, vector<BusData>> BusMap;
unordered_map<int, PathData> StartToDestPathDataMap;

void Dikstra(const int Start, const int Destination)
{
	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> CityQueue;

	CityQueue.push({ 0,Start });
	StartToDestPathDataMap[Start].Cost = 0;

	while (!CityQueue.empty())
	{
		const pair<int,int> CurrentPath = CityQueue.top();
		CityQueue.pop();

		if (CurrentPath.second == Destination)
		{
			return;
		}

		for (const BusData& BusData : BusMap[CurrentPath.second])
		{
			const int NextCityCost = CurrentPath.first + BusData.Cost;

			if (StartToDestPathDataMap[BusData.Destination].Cost == INT_MAX || NextCityCost < StartToDestPathDataMap[BusData.Destination].Cost)
			{
				StartToDestPathDataMap[BusData.Destination].Cost = NextCityCost;
				StartToDestPathDataMap[BusData.Destination].PreviousCity = CurrentPath.second;

				CityQueue.push({ NextCityCost, BusData.Destination });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int CityCount = 0;
	cin >> CityCount;

	int BusCount = 0;
	cin >> BusCount;

	for (int BusIndex = 0; BusIndex < BusCount; ++BusIndex)
	{
		int Start = 0, Destination = 0, Cost = 0;
		cin >> Start >> Destination >> Cost;

		BusMap[Start].emplace_back(Destination, Cost);
	}
	
	int Start = 0;
	cin >> Start;

	int Destination = 0;
	cin >> Destination;

	Dikstra(Start, Destination);

	int PassedCity = Destination;
	vector<int> PassedCities;

	while (PassedCity != Start)
	{
		PassedCities.push_back(PassedCity);
		PassedCity = StartToDestPathDataMap[PassedCity].PreviousCity;
	}

	PassedCities.push_back(Start);

	cout << StartToDestPathDataMap[Destination].Cost << '\n';
	cout << PassedCities.size() << '\n';
	
	for(int PassedCityIndex = PassedCities.size() - 1; PassedCityIndex >= 0; --PassedCityIndex)
	{
		cout << PassedCities[PassedCityIndex] << ' ';
	}
}
