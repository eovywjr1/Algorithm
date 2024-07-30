#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N = 0, M = 0;
vector<string> campusVector(600);

int BFS(const pair<int, int> startIndex)
{
	queue<pair<int, int>> queue;
	vector<vector<bool>> visitedVector(600, vector<bool>(600, false));
	
	queue.push(startIndex);
	visitedVector[startIndex.first][startIndex.second] = true;

	const vector<int> dirI({ -1,1,0,0 });
	const vector<int> dirJ({ 0,0,-1,1 });
	constexpr int dirSize = 4;
	int meetFriendCount = 0;

	while (queue.empty() == false)
	{
		const pair<int, int> currentIndex = queue.front();
		queue.pop();

		for (int index = 0; index < dirSize; ++index)
		{
			const int nextI = currentIndex.first + dirI[index];
			const int nextJ = currentIndex.second + dirJ[index];

			if (nextI < 0 || N <= nextI || nextJ < 0 || M <= nextJ || visitedVector[nextI][nextJ] || campusVector[nextI][nextJ] == 'X')
				continue;

			if (campusVector[nextI][nextJ] == 'P')
				++meetFriendCount;

			queue.push({ nextI,nextJ });
			visitedVector[nextI][nextJ] = true;
		}
	}

	return meetFriendCount;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int index = 0; index < N; ++index)
	{
		cin >> campusVector[index];
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (campusVector[i][j] == 'I')
			{
				const int meetFriendCount = BFS({ i,j });
				if (meetFriendCount == 0)
					cout << "TT";
				else
					cout << meetFriendCount;

				return 0;
			}
		}
	}
}
