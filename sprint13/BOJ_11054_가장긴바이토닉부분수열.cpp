#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	int N = 0;
	cin >> N;

	vector<int> Sequence(N);
	
	for (int Index = 0; Index < N; ++Index)
	{
		cin >> Sequence[Index];
	}

	vector<int> PrevSmallerNumberCounts(N, 0);
	vector<int> NextSmallerNumberCounts(N, 0);

	for (int Index = 0; Index < N; ++Index)
	{
		for (int PrevIndex = 0; PrevIndex < Index; ++PrevIndex)
		{
			if (Sequence[PrevIndex] < Sequence[Index])
			{
				PrevSmallerNumberCounts[Index] = max(PrevSmallerNumberCounts[Index], PrevSmallerNumberCounts[PrevIndex] + 1);
			}
		}
	}

	for (int Index = N - 1; Index >= 0; --Index)
	{
		for (int NextIndex = N - 1; NextIndex > Index; --NextIndex)
		{
			if (Sequence[NextIndex] < Sequence[Index])
			{
				NextSmallerNumberCounts[Index] = max(NextSmallerNumberCounts[Index], NextSmallerNumberCounts[NextIndex] + 1);
			}
		}
	}

	int MaxBitonicLength = 0;

	for (int Index = 0; Index < N; ++Index)
	{
		MaxBitonicLength = max(MaxBitonicLength, PrevSmallerNumberCounts[Index] + NextSmallerNumberCounts[Index] + 1);
	}

	cout << MaxBitonicLength;
}
