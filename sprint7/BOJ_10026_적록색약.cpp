#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int N;

void BFS(const vector<string>& rgbVector, vector<vector<bool>>& visitedVector, bool isNormal, const pair<int,int> startIndex)
{
	const vector<int> dirIVector({ 0,0,-1,1 });
	const vector<int> dirJVector({ -1,1,0,0 });
	const size_t dirSize = dirIVector.size();
	queue<pair<int, int>> queue;
	
	queue.push({ startIndex.first, startIndex.second });
	visitedVector[startIndex.first][startIndex.second] = true;

	while (queue.empty() == false)
	{
		const pair<int, int> currentIndex = queue.front();
		queue.pop();

		for (int i = 0; i < dirSize; ++i)
		{
			const int nextI = currentIndex.first + dirIVector[i];
			const int nextJ = currentIndex.second + dirJVector[i];

			if (nextI < 0 || N <= nextI || nextJ < 0 || N <= nextJ || visitedVector[nextI][nextJ])
				continue;

			const char currentRGB = rgbVector[currentIndex.first][currentIndex.second];
			const char nextRGB = rgbVector[nextI][nextJ];
			if (currentRGB != nextRGB)
			{
				if (isNormal)
					continue;
				else if (currentRGB == 'B' || nextRGB == 'B')
					continue;
			}

			queue.push({ nextI,nextJ });
			visitedVector[nextI][nextJ] = true;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	vector<string> rgbVector;
	for (int index = 0; index < N; ++index)
	{
		string rgb;
		cin >> rgb;
		rgbVector.push_back(rgb);
	}

	vector<vector<bool>> normalVistied(N, vector<bool>(N, false));
	vector<vector<bool>> unusualVistied(N, vector<bool>(N, false));
	int normalAnswer = 0;
	int unusualAnswer = 0;

	for (int i= 0; i< N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (normalVistied[i][j] == false)
			{
				BFS(rgbVector, normalVistied, true, { i,j });
				++normalAnswer;
			}

			if (unusualVistied[i][j] == false)
			{
				BFS(rgbVector, unusualVistied, false, { i,j });
				++unusualAnswer;
			}
		}
	}

	cout << normalAnswer << ' ' << unusualAnswer;
}
