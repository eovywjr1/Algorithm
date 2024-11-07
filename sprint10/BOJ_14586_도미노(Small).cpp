#include <vector>
#include <iostream>
#include <limits.h>
#include <algorithm>

using namespace std;

using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int DominoCount = 0;
	cin >> DominoCount;

	vector<pair<int, int>> DominoInfo(DominoCount);
	for (int DominoIndex = 0; DominoIndex < DominoCount; ++DominoIndex)
	{
		cin >> DominoInfo[DominoIndex].first >> DominoInfo[DominoIndex].second;
	}

	sort(DominoInfo.begin(), DominoInfo.end());

	vector<int> DominoLeftConcurrencyFallIndex(DominoCount);
	vector<int> DominoRightConcurrencyFallIndex(DominoCount);

	for (int DominoIndex = 0; DominoIndex < DominoCount; ++DominoIndex)
	{
		ll LeftValidFallDistance = DominoInfo[DominoIndex].first - DominoInfo[DominoIndex].second;
		for (int LeftDominoIndex = DominoIndex; LeftDominoIndex >= 0 && LeftValidFallDistance <= DominoInfo[LeftDominoIndex].first; --LeftDominoIndex)
		{
			LeftValidFallDistance = min(LeftValidFallDistance, 1LL * DominoInfo[LeftDominoIndex].first - DominoInfo[LeftDominoIndex].second);
			DominoLeftConcurrencyFallIndex[DominoIndex] = LeftDominoIndex;
		}

		ll RightValidFallDistance = 1LL * DominoInfo[DominoIndex].first + DominoInfo[DominoIndex].second;
		for (int RightDominoIndex = DominoIndex; RightDominoIndex < DominoCount && RightValidFallDistance >= DominoInfo[RightDominoIndex].first; ++RightDominoIndex)
		{
			RightValidFallDistance = max(RightValidFallDistance, 1LL * DominoInfo[RightDominoIndex].first + DominoInfo[RightDominoIndex].second);
			DominoRightConcurrencyFallIndex[DominoIndex] = RightDominoIndex;
		}
	}

	vector<int> MinPushDomino(DominoCount, INT_MAX);
	MinPushDomino[0] = 1;

	for (int DominoIndex = 0; DominoIndex < DominoCount; ++DominoIndex)
	{
		MinPushDomino[DominoIndex] = (DominoLeftConcurrencyFallIndex[DominoIndex] == 0) ? 1 : min(MinPushDomino[DominoIndex], MinPushDomino[DominoLeftConcurrencyFallIndex[DominoIndex] - 1] + 1);

		for (int LeftDominoIndex = 0; LeftDominoIndex < DominoIndex; ++LeftDominoIndex)
		{
			if (DominoIndex <= DominoRightConcurrencyFallIndex[LeftDominoIndex])
			{
				MinPushDomino[DominoIndex] = (LeftDominoIndex == 0) ? 1 : min(MinPushDomino[DominoIndex], MinPushDomino[LeftDominoIndex - 1] + 1);
			}
		}
	}

	cout << MinPushDomino[DominoCount - 1];
}
