#include <iostream>
#include <numeric>

using namespace std;

const long long ModNumber = 1'000'000'007;

long long ModularExponention(const long long Base, const long long Exponential)
{
	if (Exponential == 1)
	{
		return Base;
	}

	if (Exponential % 2 == 0)
	{
		const long long SqrtResult = ModularExponention(Base, Exponential / 2);
		return SqrtResult * SqrtResult % ModNumber;
	}
	else
	{
		return Base * ModularExponention(Base, Exponential - 1) % ModNumber;
	}
}

int main()
{
	int M = 0;
	cin >> M;

	const long long Exponential = ModNumber - 2;
	
	long long SumExpectedValue = 0;
	for (int i = 0; i < M; ++i)
	{
		long long a = 0, b = 0;
		cin >> b >> a;

		const long long TheGreatestCommonDivisor = gcd(a, b);
		a /= TheGreatestCommonDivisor;
		b /= TheGreatestCommonDivisor;

		SumExpectedValue = (SumExpectedValue + a * ModularExponention(b, Exponential) % ModNumber) % ModNumber;
	}

	cout << SumExpectedValue;
}
