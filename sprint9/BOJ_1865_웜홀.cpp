#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

constexpr long long invalidDistance = 12500000000;

struct EdgeWormholeData
{
	int startVertex = 0, endVertex = 0, time = 0;
};

bool BellmanFord(const int vertexCount, const int startVertex, const vector<EdgeWormholeData>& edgeVector)
{
	vector<long long> distanceVector(vertexCount + 1, invalidDistance);
	distanceVector[startVertex] = 0;

	for (int count = 1; count < vertexCount; ++count)
	{
		for (const EdgeWormholeData& data : edgeVector)
		{
			const long long nextDistance = data.time + distanceVector[data.startVertex];
			distanceVector[data.endVertex] = min(distanceVector[data.endVertex], nextDistance);
		}
	}

	// 벨만포트 알고리즘 음의 사이클 판단
	// 출발 위치가 임의이므로 임의 정점에 음의 사이클이 있다면 시간이 줄어들어 출발 위치로 돌아오는 것이 가능
	for (const EdgeWormholeData& data : edgeVector)
	{
		const long long nextDistance = data.time + distanceVector[data.startVertex];
		if (nextDistance < distanceVector[data.endVertex])
			return true;
	}

	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int TC = 0;
	cin >> TC;

	for (int tcIndex = 0; tcIndex < TC; ++tcIndex)
	{                                                                                                                                                                                                                                         
		int vertexCount = 0, edgeCount = 0, wormholeCount = 0;
		cin >> vertexCount >> edgeCount >> wormholeCount;

		vector<EdgeWormholeData> edgeVector(vertexCount + 1);

		for (int edgeIndex = 0; edgeIndex < edgeCount; ++edgeIndex)
		{
			int startVertex = 0, endVertex = 0, time = 0;
			cin >> startVertex >> endVertex >> time;

			edgeVector.push_back({ startVertex, endVertex, time });
			edgeVector.push_back({ endVertex, startVertex, time });
		}

		for (int womrholeIndex = 0; womrholeIndex < wormholeCount; ++womrholeIndex)
		{
			int startVertex = 0, endVertex = 0, time = 0;
			cin >> startVertex >> endVertex >> time;

			edgeVector.push_back({ startVertex, endVertex, time * -1 });
		}

		if (BellmanFord(vertexCount, 1, edgeVector))
			cout << "YES";
		else
			cout << "NO";
		cout << '\n';
	}
}
