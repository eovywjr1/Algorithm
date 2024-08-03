#include <iostream>
#include <vector>

using namespace std;

int maxDistance = 0;
int maxDistanceVertexNumber = 0;

void DFS(const int vertexNumber, const vector<vector<pair<int, int>>>& edgeVector, vector<bool>& visitedVector, const int distance)
{
	for (const pair<int, int> edge : edgeVector[vertexNumber])
	{
		const int nextVertexNumber = edge.first;
		if (visitedVector[nextVertexNumber])
			continue;

		const int nextDistance = distance + edge.second;

		if (maxDistance < nextDistance)
		{
			maxDistance = nextDistance;
			maxDistanceVertexNumber = nextVertexNumber;
		}

		visitedVector[nextVertexNumber] = true;
		DFS(nextVertexNumber, edgeVector, visitedVector, nextDistance);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int V;
	cin >> V;

	vector<vector<pair<int, int>>> edgeVector(V);

	for (int index = 0; index < V; ++index)
	{
		int vertexNumber = 0;
		cin >> vertexNumber;

		while (true) 
		{
			int edgeVertex = 0;
			cin >> edgeVertex;

			if (edgeVertex == -1)
				break;

			int edgeDistance = 0;
			cin >> edgeDistance;

			edgeVector[vertexNumber - 1].push_back({ edgeVertex - 1,edgeDistance });
		}
	}

	{
		vector<bool> visitedVector(V, false);
		visitedVector[1] = true;
		DFS(1, edgeVector, visitedVector, 0);
	}

	{
		vector<bool> visitedVector(V, false);
		visitedVector[maxDistanceVertexNumber] = true;
		DFS(maxDistanceVertexNumber, edgeVector, visitedVector, 0);
	}

	cout << maxDistance;
}
