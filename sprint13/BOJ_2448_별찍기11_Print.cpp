#include <iostream>
#include <cmath>

using namespace std;

int N = 0;

void PrintPadding(const int Y)
{
	for (int Cnt = 0; Cnt < N - Y - 1; ++Cnt)
	{
		cout << ' ';
	}
}

void PrintTriangle(const int K, const int Y)
{
	if (K <= 0)
	{
		if (Y % 3 == 0)
		{
			cout << '*';
		}
		else if (Y % 3 == 1)
		{
			cout << "* *";
		}
		else if (Y % 3 == 2)
		{
			cout << "*****";
		}

		return;
	}

	const int SubTriangleSize = static_cast<int>(3 * pow(2, K - 1));

	if (Y < SubTriangleSize)
	{
		PrintTriangle(K - 1, Y);
	}
	else
	{
		PrintTriangle(K - 1, Y - SubTriangleSize);

		for (int MiddlePaddingCount = 0; MiddlePaddingCount < SubTriangleSize * 2 - 1 - ((Y - SubTriangleSize) * 2); ++MiddlePaddingCount)
		{
			cout << ' ';
		}

		PrintTriangle(K - 1, Y - SubTriangleSize);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	const int K = static_cast<int>(log2(N / 3));

	for (int Y = 0; Y < N; ++Y)
	{
		PrintPadding(Y);
		PrintTriangle(K, Y);
		PrintPadding(Y);

		cout << '\n';
	}

	return 0;
}
