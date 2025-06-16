#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N = 0, M = 0;
int NumsSize = 0;
vector<int> Nums;
vector<int> Sequence;

void PrintSequenceRecursive(const int Index, const int Count)
{
	if (Count == M)
	{
		for (const int Num : Sequence)
		{
			cout << Num << ' ';
		}

		cout << '\n';

		return;
	}

	for (int i = Index; i < NumsSize; ++i)
	{
		Sequence[Count] = Nums[i];
		PrintSequenceRecursive(i, Count + 1);
	}
}

int main()
{
	cin >> N >> M;
	
	for (int i = 0; i < N; ++i)
	{
		int Num = 0;
		cin >> Num;

		if (find(Nums.begin(), Nums.end(), Num) == Nums.end())
		{
			Nums.push_back(Num);
		}
	}

	sort(Nums.begin(), Nums.end());
	NumsSize = Nums.size();

	Sequence.resize(M);

	PrintSequenceRecursive(0, 0);
}
