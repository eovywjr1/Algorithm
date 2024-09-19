#include <iostream>

using namespace std;

int A = 0, B = 0, C = 0;

// 분할 정복을 이용한 거듭 제곱
long long power(const int B)
{
	if (B == 0)
		return 1;

	if (B == 1)
		return A % C;

	const long long halfExponentNumber = power(B / 2);

	if (B % 2 == 0)
		return halfExponentNumber * halfExponentNumber % C;
	else
		return halfExponentNumber * halfExponentNumber % C * A % C;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> A >> B >> C;

	cout << power(B) % C;
}
