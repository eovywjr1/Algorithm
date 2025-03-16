#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0, M = 0;
	cin >> N >> M;

	vector<vector<int>> rowConsecutivelySum(N + 1, vector<int>(N + 1, 0));

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			int tableNum = 0;
			cin >> tableNum;
			rowConsecutivelySum[i][j] = rowConsecutivelySum[i][j - 1] + rowConsecutivelySum[i - 1][j] - rowConsecutivelySum[i - 1][j - 1] + tableNum;
		}
	}

	for (int index = 0; index < M; ++index)
	{
		int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
		cin >> x1 >> y1 >> x2 >> y2;

		const int result = rowConsecutivelySum[x2][y2] - rowConsecutivelySum[x2][y1 - 1] - rowConsecutivelySum[x1 - 1][y2] + rowConsecutivelySum[x1 - 1][y1 - 1];
	
		cout << result << '\n';
	}
}
