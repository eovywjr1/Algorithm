#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0, K = 0;
	cin >> N >> K;

	const int maxWeight = 100000;
	int answer = 0;
	vector<int> dp(maxWeight + 1, 0);

	for (int i = 0; i < N; ++i)
	{
		int W = 0, V = 0;
		cin >> W >> V;

		for (int weight = K; weight >= W; --weight)
		{
			dp[weight] = max(dp[weight], dp[weight - W] + V);
			answer = max(answer, dp[weight]);
		}
	}

	cout << answer;
}
