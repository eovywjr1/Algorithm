#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	
	vector<vector<int>> rgbCost(N, vector<int>(3));
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cin >> rgbCost[i][j];
		}
	}

	vector<vector<int>> leastRGBCost(N, vector<int>(3));
	leastRGBCost[0][0] = rgbCost[0][0];
	leastRGBCost[0][1] = rgbCost[0][1];
	leastRGBCost[0][2] = rgbCost[0][2];

	for (int index = 1; index < N; ++index)
	{
		leastRGBCost[index][0] = rgbCost[index][0] + min(leastRGBCost[index-1][1], leastRGBCost[index - 1][2]);
		leastRGBCost[index][1] = rgbCost[index][1] + min(leastRGBCost[index-1][0], leastRGBCost[index - 1][2]);
		leastRGBCost[index][2] = rgbCost[index][2] + min(leastRGBCost[index-1][0], leastRGBCost[index - 1][1]);
	}

	int answer = 1000 * N;
	for (int index = 0; index < 3; ++index)
	{
		answer = min(answer, leastRGBCost[N - 1][index]);
	}

	cout << answer;
}
