#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N = 0, M = 0;
vector<int> SubArray;

void PrintNonDescendingSubArray(const int Number, const int Count)
{
	if (Count >= M)
	{
		sort(SubArray.begin(), SubArray.end());

		for (const int Num : SubArray)
		{
			cout << Num << ' ';
		}

		cout << '\n';
		return;
	}

	for (int TempNumber = Number; TempNumber <= N; ++TempNumber)
	{
		SubArray[Count] = TempNumber;
		PrintNonDescendingSubArray(TempNumber, Count + 1);
	}
}

int main()
{
	cin >> N >> M;

	SubArray = vector<int>(M, 0);

	PrintNonDescendingSubArray(1, 0);
}
