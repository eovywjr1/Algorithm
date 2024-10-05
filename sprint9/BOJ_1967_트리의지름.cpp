#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int DFSAndGetMaxDistance(const vector<vector<pair<int, int>>>& edge, const int startIndex)
{
	vector<bool> visited(edge.size(), false);
	queue<pair<int,int>> queue;
	visited[startIndex] = true;
	queue.push({ 0,startIndex });

	int maxDistance = 0;
	while (queue.empty() == false)
	{
		const pair<int,int> currentNode = queue.front();
		queue.pop();

		maxDistance = max(maxDistance, currentNode.first);

		for (const pair<int, int>& nextEdge : edge[currentNode.second])
		{
			if (visited[nextEdge.second])
				continue;

			visited[nextEdge.second] = true;
			queue.push({ currentNode.first + nextEdge.first, nextEdge.second });
		}
	}

	return maxDistance;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	cin >> n;

	vector<vector<pair<int, int>>> edge(n + 1);
	for (int nodeCount = 0; nodeCount < n - 1; ++nodeCount)
	{
		int parentNode = 0, childNode = 0, weight = 0;
		cin >> parentNode >> childNode >> weight;

		edge[parentNode].push_back({ weight, childNode });
		edge[childNode].push_back({ weight, parentNode });
	}

	int treeDiameter = 0;
	for (int nodeIndex = 1; nodeIndex <= n; ++nodeIndex)
	{
		if (edge[nodeIndex].empty())
			continue;

		treeDiameter = max(treeDiameter, DFS(edge, nodeIndex));
	}

	cout << treeDiameter;
}
