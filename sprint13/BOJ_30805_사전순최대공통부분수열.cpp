#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N = 0, M = 0;

bool CompareArray(const pair<int, int>& Lhs, const pair<int, int>& Rhs)
{
	if (Lhs.first == Rhs.first)
	{
		return Rhs.second < Lhs.second;
	}

	return Lhs.first < Rhs.first;
}

int main()
{
	cin >> N;

	vector<pair<int, int>> ANumberAndIndexes(N);
	for (int Index = 0; Index < N; ++Index)
	{
		int Number = 0;
		cin >> Number;
		ANumberAndIndexes[Index] = { Number, Index };
	}

	cin >> M;

	vector<pair<int, int>> BNumberAndIndexes(M);
	for (int Index = 0; Index < M; ++Index)
	{
		int Number = 0;
		cin >> Number;
		BNumberAndIndexes[Index] = { Number, Index };
	}

	sort(ANumberAndIndexes.begin(), ANumberAndIndexes.end(), CompareArray);
	sort(BNumberAndIndexes.begin(), BNumberAndIndexes.end(), CompareArray);

	vector<pair<int,pair<int,int>>> LastDictionaryCommonSubArray;

	while (!ANumberAndIndexes.empty() && !BNumberAndIndexes.empty())
	{
		while (!ANumberAndIndexes.empty() && !BNumberAndIndexes.empty() && (ANumberAndIndexes.end() - 1)->first < (BNumberAndIndexes.end() - 1)->first)
		{
			BNumberAndIndexes.pop_back();
		}

		while (!ANumberAndIndexes.empty() && !BNumberAndIndexes.empty() && (BNumberAndIndexes.end() - 1)->first < (ANumberAndIndexes.end() - 1)->first)
		{
			ANumberAndIndexes.pop_back();
		}

		while (!LastDictionaryCommonSubArray.empty() && !ANumberAndIndexes.empty() && (ANumberAndIndexes.end() - 1)->second < (LastDictionaryCommonSubArray.end() - 1)->second.first)
		{
			ANumberAndIndexes.pop_back();
		}

		while (!LastDictionaryCommonSubArray.empty() && !BNumberAndIndexes.empty() && (BNumberAndIndexes.end() - 1)->second < (LastDictionaryCommonSubArray.end() - 1)->second.second)
		{
			BNumberAndIndexes.pop_back();
		}

		if (!ANumberAndIndexes.empty() && !BNumberAndIndexes.empty() && (ANumberAndIndexes.end() - 1)->first == (BNumberAndIndexes.end() - 1)->first)
		{
			LastDictionaryCommonSubArray.push_back({ (ANumberAndIndexes.end() - 1)->first, {(ANumberAndIndexes.end() - 1)->second, (BNumberAndIndexes.end() - 1)->second} });
			ANumberAndIndexes.pop_back();
			BNumberAndIndexes.pop_back();
		}
	}

	cout << LastDictionaryCommonSubArray.size() << '\n';
	
	for (const pair<int, pair<int, int>>& Element : LastDictionaryCommonSubArray)
	{
		cout << Element.first << ' ';
	}
}
