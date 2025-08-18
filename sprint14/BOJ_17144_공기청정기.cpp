#include <iostream>
#include <vector>
#include <optional>

using namespace std;

int R = 0, C = 0;
vector<vector<int>> Home;

void SpreadDust()
{
	vector<vector<int>> TempHome = Home;
	const int DirI[4] = { -1,1,0,0 };
	const int DirJ[4] = { 0,0,-1,1 };

	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			if (Home[i][j] <= 0)
			{
				continue;
			}

			const int SpreadAmount = Home[i][j] / 5;
			int SumSpreadAmount = 0;

			for (int k = 0; k < 4; ++k)
			{
				const int NextI = i + DirI[k];
				const int NextJ = j + DirJ[k];

				if (NextI < 0 || NextI >= R || NextJ < 0 || NextJ >= C || Home[NextI][NextJ] == -1)
				{
					continue;
				}

				TempHome[NextI][NextJ] += SpreadAmount;
				SumSpreadAmount += SpreadAmount;
			}

			TempHome[i][j] -= SumSpreadAmount;
		}
	}

	Home = TempHome;
}

optional<pair<int, int>> AirCleanerPosition;

void CirculateAir(const pair<int,int>& AirCleanerPositionValue, const vector<int>& DirI, const vector<int>& DirJ, const int MinI, const int MaxI)
{
	pair<int, int> CurrentPosition = make_pair(AirCleanerPositionValue.first + DirI[0], AirCleanerPositionValue.second + DirJ[0]);
	pair<int, int> NextPosition = make_pair(CurrentPosition.first + DirI[0], CurrentPosition.second + DirJ[0]);
	int DirIndex = 0;

	while (Home[NextPosition.first][NextPosition.second] != -1)
	{
		Home[CurrentPosition.first][CurrentPosition.second] = Home[NextPosition.first][NextPosition.second];

		if (NextPosition.first + DirI[DirIndex] < MinI || NextPosition.first + DirI[DirIndex] > MaxI 
			|| NextPosition.second + DirJ[DirIndex] < 0 || NextPosition.second + DirJ[DirIndex] >= C)
		{
			++DirIndex;
		}

		CurrentPosition = NextPosition;
		NextPosition = make_pair(CurrentPosition.first + DirI[DirIndex], CurrentPosition.second + DirJ[DirIndex]);
	}

	Home[CurrentPosition.first][CurrentPosition.second] = 0;
}

// 이동을 역순으로
void CirculateCounterclockwiseAir()
{
	const vector<int> DirI = { -1, 0, 1, 0 };
	const vector<int> DirJ = { 0, 1, 0, -1 };

	CirculateAir(AirCleanerPosition.value(), DirI, DirJ, 0, AirCleanerPosition.value().first);
}

void CirculateclockwiseAir()
{
	const vector<int> DirI = { 1, 0, -1, 0 };
	const vector<int> DirJ = { 0, 1, 0, -1 };
	const pair<int, int> AirCleanerPositionValue = make_pair(AirCleanerPosition.value().first + 1, AirCleanerPosition.value().second);

	CirculateAir(AirCleanerPositionValue, DirI, DirJ, AirCleanerPosition.value().first + 1, R - 1);
}

int main()
{
	int T = 0;
	cin >> R >> C >> T;

	Home = vector<vector<int>>(R, vector<int>(C));

	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			cin >> Home[i][j];

			if (Home[i][j] == -1 && !AirCleanerPosition.has_value())
			{
				AirCleanerPosition = make_pair(i, j);
			}
		}
	}

	for (int Time = 0; Time < T; ++Time)
	{
		SpreadDust();
		
		CirculateCounterclockwiseAir();
		CirculateclockwiseAir();
	}

	int SumDust = 0;

	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			if (Home[i][j] != -1)
			{
				SumDust += Home[i][j];
			}
		}
	}

	cout << SumDust;
}
