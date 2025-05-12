#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int N = 0, M = 0;
int MaxSafeAreaCount = 0;
vector<vector<int>> Area;

void BFS()
{
	queue<pair<int, int>> CoordiQueue;
	vector<vector<bool>> VisitedArea(N, vector<bool>(M, false));
	
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (Area[i][j] != 1)
			{
				CoordiQueue.push({i,j});
				VisitedArea[i][j] = true;
			}
		}
	}

	const vector<int> DirI({ -1,1,0,0 });
	const vector<int> DirJ({ 0,0,-1,1 });

	int SafeAreaCount = 0;
	bool bIsVirus = false;

	while (!CoordiQueue.empty())
	{
		const pair<int, int> CurrentCoordi = CoordiQueue.front();
		CoordiQueue.pop();

		++SafeAreaCount;

		for (int Dir = 0; Dir < 4; ++Dir)
		{
			const int NextI = CurrentCoordi.first + DirI[Dir];
			const int NextJ = CurrentCoordi.second + DirJ[Dir];

			if (NextI < 0 || NextI >= N || NextJ < 0 || NextJ >= M || VisitedArea[NextI][NextJ] || Area[NextI][NextJ] == 1)
			{
				continue;
			}

			if (Area[NextI][NextJ] == 2)
			{
				bIsVirus = true;
			}

			CoordiQueue.push({ NextI,NextJ });
			VisitedArea[NextI][NextJ] = true;
		}
	}

	if(bIsVirus)


	MaxSafeAreaCount = max(MaxSafeAreaCount, SafeAreaCount);
}

void SetWall(int Count)
{
	const int MaxWallCount = 3;
	if (Count == MaxWallCount)
	{
		BFS();
		return;
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (Area[i][j] == 0)
			{
				Area[i][j] = 1;
				SetWall(Count + 1);
				Area[i][j] = 0;
			}
		}
	}
}

int main()
{
	cin >> N >> M;

	Area = vector<vector<int>>(N, vector<int>(M, 0));
	
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> Area[i][j];
		}
	}

	SetWall(0);

	cout << MaxSafeAreaCount;
}
