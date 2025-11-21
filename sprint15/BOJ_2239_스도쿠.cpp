#include <iostream>
#include <vector>

using namespace std;

const int BoardSize = 9;
vector<vector<int>> Board;
vector<pair<int, int>> EmptyIndexes;

bool CanChangeNumber(const int HeightIndex, const int WeightIndex)
{
	const int Number = Board[HeightIndex][WeightIndex];
	for (int i = 0; i < BoardSize; ++i)
	{
		if (i != WeightIndex && Board[HeightIndex][i] == Number)
		{
			return false;
		}

		if (i != HeightIndex && Board[i][WeightIndex] == Number)
		{
			return false;
		}

		const int y = 3 * (HeightIndex / 3) + i / 3;
		const int x = 3 * (WeightIndex / 3) + i % 3;
		if (!(y == HeightIndex && x == WeightIndex) && Board[y][x] == Number)
		{
			return false;
		}
	}

	return true;
}

void MakeSudoku(const int Count)
{
	if (Count == EmptyIndexes.size())
	{
		for (int i = 0; i < BoardSize; ++i)
		{
			for (int j = 0; j < BoardSize; ++j)
			{
				cout << Board[i][j];
			}

			cout << '\n';
		}

		exit(0);
	}

	const int i = EmptyIndexes[Count].first;
	const int j = EmptyIndexes[Count].second;

	for (int k = 1; k <= BoardSize; ++k)
	{
		Board[i][j] = k;
		if (CanChangeNumber(i, j))
		{
			MakeSudoku(Count + 1);
		}
		Board[i][j] = 0;
	}
}

int main()
{
	Board = vector<vector<int>>(BoardSize, vector<int>(BoardSize));

	for (int i = 0; i < BoardSize; ++i)
	{
		string NumberStr;
		cin >> NumberStr;

		for (int j = 0; j < BoardSize; ++j)
		{
			Board[i][j] = NumberStr[j] - '0';

			if (Board[i][j] == 0)
			{
				EmptyIndexes.push_back({ i,j });
			}
		}
	}

	MakeSudoku(0);
}
