#include <vector>
#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include "limits.h"

using namespace std;

int N = 0;
constexpr int invalidDistance = INT_MAX - 1;
map<int, vector<pair<int,int>>> edges;
vector<int> distanceVector(803, invalidDistance);

void dijkstra(const int startVertexNumber)
{
	distanceVector.clear();
	distanceVector.resize(N + 1);
	for (int index = 1; index <= N; ++index)
	{
		distanceVector[index] = invalidDistance;
	}

	distanceVector[startVertexNumber] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,startVertexNumber });

	while (pq.empty() == false)
	{
		const int currentDistance = pq.top().first;
		const int currentVertexNumber = pq.top().second;
		pq.pop();

		for (const pair<int, int> nextEdge : edges[currentVertexNumber])
		{
			const int nextVertexNumber = nextEdge.second;
			const int nextDistance = currentDistance + nextEdge.first;

			if (distanceVector[nextVertexNumber] <= nextDistance)
				continue;

			distanceVector[nextVertexNumber] = nextDistance;
			pq.push({ nextDistance, nextVertexNumber });
		}
	}
}

int main()
{
	int E = 0;
	cin >> N >> E;

	for (int index = 0; index < E; ++index)
	{
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;

		edges[a].push_back({ c,b });
		edges[b].push_back({ c,a });
	}

	int v1 = 0, v2 = 0;
	cin >> v1 >> v2;

	dijkstra(1);
	const int startToV1 = distanceVector[v1];
	const int startToV2 = distanceVector[v2];

	dijkstra(v1);
	const int v1ToV2 = distanceVector[v2];
	const int v1ToDest = distanceVector[N];

	dijkstra(v2);
	const int v2ToDest = distanceVector[N];

	int minDistance = invalidDistance;
	if (startToV1 != invalidDistance && v1ToV2 != invalidDistance && v2ToDest != invalidDistance)
		minDistance = min(minDistance, startToV1 + v1ToV2 + v2ToDest);

	if (startToV2 != invalidDistance && v1ToV2 != invalidDistance && v1ToDest != invalidDistance)
		minDistance = min(minDistance, startToV2 + v1ToV2 + v1ToDest);

	if (minDistance == invalidDistance)
		cout << -1;
	else
		cout << minDistance;
}
