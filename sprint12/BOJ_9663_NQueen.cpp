#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int N;
int answer = 0;
vector<int> installedRawIndex;

bool canInstallQueen(int colIndex)
{
	for (int index = 0; index < colIndex; ++index)
	{
		if (installedRawIndex[index] == installedRawIndex[colIndex] || abs(installedRawIndex[colIndex] - installedRawIndex[index]) == colIndex - index)
		{
			return false;
		}
	}

	return true;
}

void checkQueen(int currentColIndex)
{
	if (currentColIndex == N)
	{
		++answer;

		return;
	}

	for (int index = 0; index < N; ++index)
	{
		installedRawIndex[currentColIndex] = index;
		if (canInstallQueen(currentColIndex))
		{
			checkQueen(currentColIndex + 1);
		}
	}
}

int main()
{
	cin >> N;
	installedRawIndex.resize(N);

	checkQueen(0);

	cout << answer;
}
