#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int N = 0, M = 0;
int MaxSafeAreaCount = 0;
int DefaultSafeAreaCount = 0;
const int MaxWallCount = 3;
vector<pair<int, int>> VirusCoordis;
vector<vector<int>> Area;

void BFS()
{
	vector<vector<bool>> VisitedArea(N, vector<bool>(M, false));
	queue<pair<int, int>> CoordiQueue;

	for (const pair<int, int>& VirusCoordi : VirusCoordis)
	{
		CoordiQueue.push(VirusCoordi);
		VisitedArea[VirusCoordi.first][VirusCoordi.second] = true;
	}

	const vector<int> DirI({ -1,1,0,0 });
	const vector<int> DirJ({ 0,0,-1,1 });

	int VirusSpreadCount = 0;

	while (!CoordiQueue.empty())
	{
		const pair<int, int> CurrentCoordi = CoordiQueue.front();
		CoordiQueue.pop();

		for (int Dir = 0; Dir < 4; ++Dir)
		{
			const int NextI = CurrentCoordi.first + DirI[Dir];
			const int NextJ = CurrentCoordi.second + DirJ[Dir];

			if (NextI < 0 || NextI >= N || NextJ < 0 || NextJ >= M || VisitedArea[NextI][NextJ] || Area[NextI][NextJ] != 0)
			{
				continue;
			}

			++VirusSpreadCount;
			CoordiQueue.push({ NextI,NextJ });
			VisitedArea[NextI][NextJ] = true;
		}
	}

	MaxSafeAreaCount = max(MaxSafeAreaCount, DefaultSafeAreaCount - VirusSpreadCount - MaxWallCount);
}

void SetWall(int Count)
{
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

			if (Area[i][j] == 0)
			{
				++DefaultSafeAreaCount;
			}
			else if (Area[i][j] == 2)
			{
				VirusCoordis.push_back({ i,j });
			}
		}
	}

	SetWall(0);

	cout << MaxSafeAreaCount;
}
