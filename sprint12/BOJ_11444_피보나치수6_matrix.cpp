#include <iostream>
#include <vector>

using namespace std;

constexpr long long MOD = 1000000007;

using matrix = vector<vector<long long>>;

matrix operator*(const matrix& lhs, const matrix& rhs)
{
	matrix temp(2, vector<long long>(2));

	temp[0][0] = (lhs[0][0] * rhs[0][0] + lhs[0][1] * rhs[1][0]) % MOD;
	temp[0][1] = (lhs[0][0] * rhs[0][1] + lhs[0][1] * rhs[1][1]) % MOD;

	temp[1][0] = (lhs[1][0] * rhs[0][0] + lhs[1][1] * rhs[1][0]) % MOD;
	temp[1][1] = (lhs[1][0] * rhs[0][1] + lhs[1][1] * rhs[1][1]) % MOD;

	return temp;
}

int main()
{
	long long n;
	cin >> n;

	

	matrix result = { {1, 0}, {0, 1} };
	matrix baseMatrix = { {1,1}, {1,0} };

	while (n > 0)
	{
		if (n % 2 == 1)
		{
			result = result * baseMatrix;
		}

		baseMatrix = baseMatrix * baseMatrix;
		n /= 2;
	}

	cout << result[0][1];
}
