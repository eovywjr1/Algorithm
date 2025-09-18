#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> PrimeNumbers;

void Eratos(const int Number)
{
	vector<bool> IsPrime(Number + 1, true);

	const int SqrtNumber = sqrt(Number);
	for (int i = 2; i <= SqrtNumber; ++i)
	{
		if(!IsPrime[i])
		{ 
			continue;
		}

		for (int j = i * i; j <= Number; j += i)
		{
			IsPrime[j] = false;
		}
	}

	for (int i = 2; i <= Number; ++i)
	{
		if (IsPrime[i])
		{
			PrimeNumbers.push_back(i);
		}
	}
}

int main()
{
	int N = 0;
	cin >> N;

	PrimeNumbers.reserve(N);

	Eratos(N);

	const int PrimeNumberCount = PrimeNumbers.size();
	int LeftIndex = 0, RightIndex = 0;
	int Sum = 0;
	int Answer = 0;

	while (RightIndex <= PrimeNumberCount)
	{
		if (Sum < N)
		{
			Sum += PrimeNumbers[RightIndex];
			++RightIndex;
		}
		else
		{
			if (Sum == N)
			{
				++Answer;
			}

			Sum -= PrimeNumbers[LeftIndex];
			++LeftIndex;
		}
	}

	cout << Answer;
}
