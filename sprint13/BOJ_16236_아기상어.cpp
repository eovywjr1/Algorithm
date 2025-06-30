#include <iostream>
#include <vector>
#include <optional>
#include <cmath>
#include <queue>
#include <limits.h>

using namespace std;

struct ChildSharkData
{
	pair<int, int> CurrentPosition;
	int Size = 2;
	int EatCount = 0;
};

int N = 0;
vector<vector<int>> Space;
ChildSharkData CurrentChildSharkData;
optional<pair<int, int>> MinDistanceEatableShark;
int MoveDistance = INT_MAX;
int SumMoveDistance = 0;

void FindMinDistanceEatSharkBFS()
{
	queue<pair<pair<int, int>, int>> BFSQueue;
	BFSQueue.push({ CurrentChildSharkData.CurrentPosition, 0 });

	vector<vector<bool>> Visited(N, vector<bool>(N, false));
	Visited[CurrentChildSharkData.CurrentPosition.first][CurrentChildSharkData.CurrentPosition.second] = true;

	const vector<int> DirI = { -1,1,0,0 };
	const vector<int> DirJ = { 0,0,-1,1 };

	MoveDistance = INT_MAX;

	while (!BFSQueue.empty())
	{
		const pair<int, int> CurrentPosition = BFSQueue.front().first;
		const int Distance = BFSQueue.front().second;

		BFSQueue.pop();

		if (MoveDistance < Distance)
		{
			continue;
		}

		for (int i = 0; i < 4; ++i)
		{
			const int NextI = CurrentPosition.first + DirI[i];
			const int NextJ = CurrentPosition.second + DirJ[i];

			if (NextI < 0 || NextI >= N || NextJ < 0 || NextJ >= N || Visited[NextI][NextJ] || CurrentChildSharkData.Size < Space[NextI][NextJ])
			{
				continue;
			}

			const int NextDistance = Distance + 1;
			if (Space[NextI][NextJ] != 0 && Space[NextI][NextJ] < CurrentChildSharkData.Size && (NextDistance < MoveDistance || (NextDistance == MoveDistance && (NextI < MinDistanceEatableShark.value().first || (NextI == MinDistanceEatableShark.value().first && NextJ < MinDistanceEatableShark.value().second)))))
			{
				MoveDistance = NextDistance;
				MinDistanceEatableShark = { NextI,NextJ };
			}
			
			Visited[NextI][NextJ] = true;
			BFSQueue.push({ {NextI,NextJ}, NextDistance });
		}
	}
}

void EatShark()
{
	++CurrentChildSharkData.EatCount;
	if (CurrentChildSharkData.EatCount == CurrentChildSharkData.Size)
	{
		++CurrentChildSharkData.Size;
		CurrentChildSharkData.EatCount = 0;
	}

	SumMoveDistance += MoveDistance;

	CurrentChildSharkData.CurrentPosition = MinDistanceEatableShark.value();

	Space[MinDistanceEatableShark.value().first][MinDistanceEatableShark.value().second] = 0;
	MinDistanceEatableShark.reset();
}

int main()
{
	cin >> N;

	Space.resize(N);
	for (int i = 0; i < N; ++i)
	{
		Space[i].resize(N);

		for (int j = 0; j < N; ++j)
		{
			cin >> Space[i][j];

			if (Space[i][j] == 9)
			{
				CurrentChildSharkData.CurrentPosition = { i,j };
				Space[i][j] = 0;
			}
		}
	}

	while (true)
	{
		FindMinDistanceEatSharkBFS();

		if (!MinDistanceEatableShark.has_value())
		{
			break;
		}

		EatShark();
	}

	cout << SumMoveDistance;
}
