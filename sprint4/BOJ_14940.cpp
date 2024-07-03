#include <iostream>
#include <vector>
#include <queue>

using namespace std;

constexpr int maxDir = 4;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> mapVector(n, vector<int>(m, 0));
	pair<int, int> goalPoint;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> mapVector[i][j];

			if (mapVector[i][j] == 2)
				goalPoint = { i,j };
		}
	}

	vector<vector<int>> answer(n, vector<int>(m, 0));
	vector<vector<bool>> visitedVector(n, vector<bool>(m, false));
	const vector<int> dirI({ -1,1,0,0 });
	const vector<int> dirJ({ 0,0,-1,1 });
	queue<pair<pair<int, int>, int>> bfsQueue;

	bfsQueue.push({ goalPoint, 0 });
	visitedVector[goalPoint.first][goalPoint.second] = true;

	while (bfsQueue.empty() == false) {
		const pair<pair<int, int>, int> currentPoint = bfsQueue.front();
		const pair<int, int> currentPointIndex = currentPoint.first;

		bfsQueue.pop();

		answer[currentPointIndex.first][currentPointIndex.second] = currentPoint.second;

		for (int index = 0; index < maxDir; ++index) {
			const int nextPointI = currentPointIndex.first + dirI[index];
			const int nextPointJ = currentPointIndex.second + dirJ[index];

			if (nextPointI < 0 || n <= nextPointI || nextPointJ < 0 || m <= nextPointJ)
				continue;

			if (visitedVector[nextPointI][nextPointJ])
				continue;

			if (mapVector[nextPointI][nextPointJ] == 0)
				continue;

			bfsQueue.push({ {nextPointI,nextPointJ},currentPoint.second + 1 });
			visitedVector[nextPointI][nextPointJ] = true;
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (visitedVector[i][j] == false && mapVector[i][j] != 0)
				answer[i][j] = -1;

			cout << answer[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}