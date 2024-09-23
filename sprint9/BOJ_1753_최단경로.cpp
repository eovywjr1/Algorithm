#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>

using namespace std;

void dijkstra(const int startNumber, const vector<vector<pair<int, int>>>& edgeVector, vector<int>& distanceVector)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	distanceVector[startNumber] = 0;
	pq.push({ 0, startNumber });

	while (pq.empty() == false)
	{
		const pair<int, int> currentVertex = pq.top();
		pq.pop();

		if (distanceVector[currentVertex.second] < currentVertex.first)
			continue;

		for (const pair<int, int> nextEdge : edgeVector[currentVertex.second])
		{
			const int nextDistance = currentVertex.first + nextEdge.first;
			if (distanceVector[nextEdge.second] <= nextDistance)
				continue;

			distanceVector[nextEdge.second] = nextDistance;
			pq.push({ nextDistance,nextEdge.second });
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int V = 0, E = 0;
	cin >> V >> E;

	int startNumber = 0;
	cin >> startNumber;

	vector<vector<pair<int, int>>> edgeVector(V + 1);
	for (int i = 0; i < E; ++i)
	{
		int u = 0, v = 0, w = 0;
		cin >> u >> v >> w;

		edgeVector[u].push_back({ w,v });
	}

	vector<int> distanceVector(V + 1, INT_MAX - 1);

	dijkstra(startNumber, edgeVector, distanceVector);

	for (int vertexNumber = 1; vertexNumber <= V; ++vertexNumber)
	{
		if (distanceVector[vertexNumber] == INT_MAX - 1)
			cout << "INF";
		else
			cout << distanceVector[vertexNumber];

		cout << '\n';
	}
}
