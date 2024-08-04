#include <iostream>
#include <vector>
#include <limits.h>
#include <cmath>
#include <queue>

using namespace std;

int N = 0, X = 0;
constexpr int invalidDistance = INT_MAX - 1;

void dijkstra(const int startVertexNumber, const vector<vector<pair<int, int>>>& edgesVector, vector<int>& distanceVector)
{
	distanceVector[startVertexNumber] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ startVertexNumber,0 });

	while (pq.empty() == false)
	{
		const pair<int, int> currentVertex = pq.top();
		const int currentVertexNumber = currentVertex.first;
		const int currentVertexDistance = currentVertex.second;

		pq.pop();

		for (const pair<int, int> edge : edgesVector[currentVertexNumber])
		{
			const int nextVertexNumber = edge.first;
			const int nextVertexDistance = currentVertexDistance + edge.second;

			if (nextVertexDistance < distanceVector[nextVertexNumber])
			{
				distanceVector[nextVertexNumber] = nextVertexDistance;
				pq.push({ nextVertexNumber, nextVertexDistance });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int M;
	cin >> N >> M >> X;
	--X;

	vector<vector<pair<int, int>>> edgesVector(N);   
	for (int index = 0; index < M; ++index)
	{
		int startVertexNumber = 0, endVertexNumber = 0, distance = 0;
		cin >> startVertexNumber >> endVertexNumber >> distance;

		edgesVector[startVertexNumber - 1].push_back({ endVertexNumber - 1,distance });
	}

	vector<int> distanceToXVector(N, invalidDistance);
	dijkstra(X, edgesVector, distanceToXVector);

	int answer = 0;
	for (int vertexNumber = 0; vertexNumber < N; ++vertexNumber)
	{
		if (vertexNumber == X)
			continue;

		vector<int> distanceToVertexVector(N, invalidDistance);
		dijkstra(vertexNumber, edgesVector, distanceToVertexVector);
		
		answer = max(answer, distanceToXVector[vertexNumber] + distanceToVertexVector[X]);
	}

	cout << answer;
}
