#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> Board;

int N = 0;

void RecursiveWriteTriangle(const int X, const int Y, int TriangleSize)
{
	if (TriangleSize <= 3) {
		Board[Y][X] = '*'; // 0 2
		Board[Y + 1][X - 1] = '*'; // 1 1
		Board[Y + 1][X + 1] = '*'; // 1 3
		Board[Y + 2][X - 2] = '*';
		Board[Y + 2][X - 1] = '*';
		Board[Y + 2][X] = '*';
		Board[Y + 2][X + 1] = '*';
		Board[Y + 2][X + 2] = '*';
		
		
		return;
	}
	
	const int NextSize = TriangleSize / 2;
	RecursiveWriteTriangle(X, Y, NextSize);
	RecursiveWriteTriangle(X - NextSize, Y + NextSize, NextSize);
	RecursiveWriteTriangle(X + NextSize, Y + NextSize, NextSize);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	Board.resize(N);
	for (int Index = 0; Index < N; ++Index)
	{
		Board[Index].resize(2 * N + 1, ' ');
	}

	RecursiveWriteTriangle(N - 1, 0, N);
	
	for (int Y = 0; Y < N; ++Y)
	{
		for (int X = 0; X < 2 * N + 1; ++X)
		{
			cout << Board[Y][X];
		}

		cout << '\n';
	}

	return 0;
}
