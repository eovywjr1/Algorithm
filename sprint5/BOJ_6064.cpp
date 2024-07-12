#include "iostream"

using namespace std;

int GCD(int a, int b) {
	if (b == 0)
		return a;

	return GCD(b, a % b);
}

int LCM(int a, int b) {
	return a * b / GCD(a, b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int Index = 0; Index < T; ++Index) 
	{
		int M, N, x, y;
		cin >> M >> N >> x >> y;

		const int MaxYear = LCM(M, N);
		int tempX = x, tempY = x % N, Result = -1;
		for (int Year = x; Year <= MaxYear; Year += M, tempY = (tempY + M) % N) 
		{
			if (tempY == 0)
				tempY = N;

			if (tempY == y) 
			{
				Result = Year;
				break;
			}
		}

		cout << Result << '\n';
	}
}
