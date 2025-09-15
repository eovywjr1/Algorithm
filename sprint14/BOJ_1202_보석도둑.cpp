#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<pair<int, int>> JewelInfos;
vector<int> BagWeights;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0, K = 0;
	cin >> N >> K;

	JewelInfos.resize(N);

	for (int i = 0; i < N; ++i)
	{
		auto& [Weight, Cost] = JewelInfos[i];
		cin >> Weight >> Cost;
	}

	BagWeights.resize(K);
	for (int i = 0; i < K; ++i)
	{
		cin >> BagWeights[i];
	}

	sort(BagWeights.begin(), BagWeights.end());
	sort(JewelInfos.begin(), JewelInfos.end());

	priority_queue<int> JewelPQ;
	long long MaxJewelCost = 0;

	for (int i = 0, JewelIndex = 0; i < K; ++i)
	{
		while (JewelIndex < N && JewelInfos[JewelIndex].first <= BagWeights[i])
		{
			JewelPQ.push(JewelInfos[JewelIndex].second);

			++JewelIndex;
		}

		if (!JewelPQ.empty())
		{
			MaxJewelCost += JewelPQ.top();
			JewelPQ.pop();
		}
	}

	cout << MaxJewelCost;
}
