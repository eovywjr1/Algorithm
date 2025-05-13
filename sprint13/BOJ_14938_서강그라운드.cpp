#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <unordered_map>

using namespace std;

int n = 0, m = 0, r = 0, MaxItemCount = 0;
vector<int> ItemCounts;
unordered_map<int, vector<pair<int, int>>> Edges;

void FindMaxItemCount(const int StartVertex)
{
	vector<int> Distances(n + 1, INT_MAX);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> DistancePQ;

	Distances[StartVertex] = 0;
	DistancePQ.push({ 0,StartVertex });

	while (!DistancePQ.empty())
	{
		const pair<int, int> CurrentVertexInfo = DistancePQ.top();
		DistancePQ.pop();

		for (const pair<int, int>& NextEdge : Edges[CurrentVertexInfo.second])
		{
			const int NextDistance = CurrentVertexInfo.first + NextEdge.second;
			const int NextVertex = NextEdge.first;

			if (NextDistance < Distances[NextVertex])
			{
				Distances[NextVertex] = NextDistance;
				DistancePQ.push({ NextDistance, NextVertex });
			}
		}
	}

	int ItemCountSum = 0;

	for (int Vertex = 1; Vertex <= n; ++Vertex)
	{
		if (Distances[Vertex] <= m)
		{
			ItemCountSum += ItemCounts[Vertex];
		}
	}

	MaxItemCount = max(MaxItemCount, ItemCountSum);
}

int main()
{
	cin >> n >> m >> r;

	ItemCounts = vector<int>(n + 1, 0);
	for (int Vertex = 1; Vertex <= n; ++Vertex)
	{
		cin >> ItemCounts[Vertex];
	}

	for (int Index = 0; Index < r; ++Index)
	{
		int Vertex1 = 0, Vertex2 = 0, Distance = 0;
		cin >> Vertex1 >> Vertex2 >> Distance;

		Edges[Vertex1].push_back({ Vertex2, Distance });
		Edges[Vertex2].push_back({ Vertex1, Distance });
	}

	for (int Vertex = 1; Vertex <= n; ++Vertex)
	{
		FindMaxItemCount(Vertex);
	}

	cout << MaxItemCount;
}
