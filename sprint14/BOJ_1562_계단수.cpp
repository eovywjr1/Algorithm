#include <iostream>

using namespace std;

const int AllVisitMask = 1023;
const int MaxNumber = 9;
const int Modular = 1'000'000'000;
int Dp[101][MaxNumber + 1][AllVisitMask + 1] = { 0 };

int main()
{
	int N = 0;
	cin >> N;

	for (int i = 1; i <= MaxNumber; ++i)
	{
		Dp[1][i][1 << i] = 1;
	}

	for (int i = 2; i <= N; ++i)
	{
		for (int j = 0; j <= MaxNumber; ++j)
		{
			for (int k = 0; k <= AllVisitMask; ++k)
			{
				if (j > 0)
				{
					Dp[i][j][k | 1 << j] = (Dp[i][j][k | 1 << j] + Dp[i - 1][j - 1][k]) % Modular;
				}

				if (j < MaxNumber)
				{
					Dp[i][j][k | 1 << j] = (Dp[i][j][k | 1 << j] + Dp[i - 1][j + 1][k]) % Modular;
				}
			}
		}
	}

	int Answer = 0;
	for (int i = 0; i <= MaxNumber; ++i)
	{
		Answer = (Answer + Dp[N][i][AllVisitMask]) % Modular;
	}

	cout << Answer;
}
