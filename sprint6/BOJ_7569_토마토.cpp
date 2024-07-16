#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int M = 0, N = 0, H = 0;
vector<vector<vector<int>>> TomaToBox(100, vector<vector<int>>(100, vector<int>(100, 0)));
vector<vector<vector<bool>>> VisitedTomaToBox(100, vector<vector<bool>>(100, vector<bool>(100, false)));

struct Coordinates
{
public:
	Coordinates(int InI, int InJ, int InK)
	{
		i = InI;
		j = InJ;
		k = InK;
	}

	int i = 0, j = 0, k = 0;
};

void BFS(const Coordinates StartIndex)
{
	const vector<int> DirH = { 0,0,0,0,-1,1 };
	const vector<int> DirN = { -1,1,0,0,0,0 };
	const vector<int> DirM = { 0,0,-1,1,0,0 };

	queue<Coordinates> RipeTomaToQueue;
	RipeTomaToQueue.push(StartIndex);
	VisitedTomaToBox[StartIndex.i][StartIndex.j][StartIndex.k] = true;

	while (RipeTomaToQueue.empty() == false)
	{
		const Coordinates currentTomato = RipeTomaToQueue.front();
		RipeTomaToQueue.pop();

		const int currentTomatoH = currentTomato.i;
		const int currentTomatoN = currentTomato.j;
		const int currentTomatoM = currentTomato.k;

		const int DirSize = DirH.size();
		for (int Index = 0; Index < DirSize; ++Index)
		{
			const int NextTomatoH = currentTomatoH + DirH[Index];
			const int NextTomatoN = currentTomatoN + DirN[Index];
			const int NextTomatoM = currentTomatoM + DirM[Index];

			if (NextTomatoH < 0 || NextTomatoH >= H || NextTomatoN < 0 || NextTomatoN >= N || NextTomatoM < 0 || NextTomatoM >= M
				|| TomaToBox[NextTomatoH][NextTomatoN][NextTomatoM] == -1 )
			{
				continue;
			}

			if (TomaToBox[NextTomatoH][NextTomatoN][NextTomatoM] != 0 && TomaToBox[NextTomatoH][NextTomatoN][NextTomatoM] <= TomaToBox[currentTomatoH][currentTomatoN][currentTomatoM] + 1)
			{
				continue;
			}

			TomaToBox[NextTomatoH][NextTomatoN][NextTomatoM] = TomaToBox[currentTomatoH][currentTomatoN][currentTomatoM] + 1;
			RipeTomaToQueue.push(Coordinates(NextTomatoH, NextTomatoN, NextTomatoM));
			VisitedTomaToBox[NextTomatoH][NextTomatoN][NextTomatoM] = true;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	bool IsAllRipedTomato = true;

	cin >> M >> N >> H;

	for (int i = 0; i < H; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			for (int k = 0; k < M; ++k)
			{
				cin >> TomaToBox[i][j][k];

				if (TomaToBox[i][j][k] == 0)
				{
					IsAllRipedTomato = false;
				}
			}
		}
	}

	if (IsAllRipedTomato)
	{
		cout << 0;

		return 0;
	}

	for (int i = 0; i < H; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			for (int k = 0; k < M; ++k)
			{
				if (TomaToBox[i][j][k] == 1 && VisitedTomaToBox[i][j][k] == false)
				{
					BFS(Coordinates(i, j, k));
				}
			}
		}
	}

	int Day = 0;

	for (int i = 0; i < H; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			for (int k = 0; k < M; ++k)
			{
				if (TomaToBox[i][j][k] == 0)
				{
					cout << -1;

					return 0;
				}
				else if (TomaToBox[i][j][k] == -1)
				{
					continue;
				}

				Day = max(Day, TomaToBox[i][j][k]);
			}
		}
	}

	cout << Day - 1;
	
	return 0;
}
