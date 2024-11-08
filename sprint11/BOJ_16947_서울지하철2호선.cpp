#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <limits.h>
#include <unordered_map>

using namespace std;

set<int> CycleStations;

bool FindCycleByDFS(const vector<vector<int>>& Edges, const int StartStation, const int CurrentStation, unordered_map<int,int>& NextStations)
{
	for (const int NextStation : Edges[CurrentStation])
	{
		if (NextStations[NextStation] == CurrentStation)
		{
			continue;
		}

		if (NextStations[NextStation] == 0)
		{
			NextStations[CurrentStation] = NextStation;
			
			if (FindCycleByDFS(Edges, StartStation, NextStation, NextStations))
			{
				return true;
			}

			NextStations[CurrentStation] = 0;
		}
		else if(NextStation == StartStation)
		{
			for (int CycleStation = NextStation; CycleStation != 0; CycleStation = NextStations[CycleStation])
			{
				CycleStations.insert(CycleStation);
			}

			return true;
		}
	}

	return false;
}

void GetDistanceToCycle(const vector<vector<int>>& Edges)
{
	vector<bool> Visiteds(Edges.size(), false);
	queue<pair<int, int>> BFSQueue;

	for (const int CycleStation : CycleStations)
	{
		BFSQueue.push({ CycleStation, 0 });
		Visiteds[CycleStation] = true;
	}

	vector<int> DistanceToCycles(Edges.size());

	while (BFSQueue.empty() == false)
	{
		const pair<int, int> CompareStation = BFSQueue.front();
		BFSQueue.pop();

		DistanceToCycles[CompareStation.first] = CompareStation.second;

		for (const int NextStation : Edges[CompareStation.first])
		{
			if (Visiteds[NextStation])
			{
				continue;
			}

			Visiteds[NextStation] = true;
			BFSQueue.push({ NextStation, CompareStation.second + 1 });
		}
	}

	for (int Station = 1; Station < DistanceToCycles.size(); ++Station)
	{
		cout << DistanceToCycles[Station] << ' ';
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int StationCount = 0;
	cin >> StationCount;

	vector<vector<int>> Edges(StationCount + 1);
	for (int EdgeIndex = 0; EdgeIndex < StationCount; ++EdgeIndex)
	{
		int Station1 = 0, Station2 = 0;
		cin >> Station1 >> Station2;

		Edges[Station1].push_back(Station2);
		Edges[Station2].push_back(Station1);
	}

	unordered_map<int, int> NextStations;

	for (int Station = 1; Station <= StationCount; ++Station)
	{
		if (FindCycleByDFS(Edges, Station, Station, NextStations))
		{
			break;
		}
	}

	GetDistanceToCycle(Edges);
}
