#include <iostream>
#include <unordered_map>

using namespace std;

constexpr int MOD = 1000000007;
unordered_map<long long, long long> fibonacciMap;

long long findFibonacchi(long long num)
{
	if (fibonacciMap.find(num) != fibonacciMap.end())
	{
		return fibonacciMap[num];
	}

	long long fibonacci = 0;
	if (num % 2 == 0)
	{
		fibonacci = (findFibonacchi(num / 2) * ((findFibonacchi(num / 2 + 1)) + findFibonacchi(num / 2 - 1)) % MOD) % MOD;
	}
	else
	{
		fibonacci = (findFibonacchi((num + 1) / 2) * findFibonacchi((num + 1) / 2) % MOD + findFibonacchi((num - 1) / 2) * findFibonacchi((num - 1) / 2) % MOD) % MOD;
	}
	
	fibonacciMap[num] = fibonacci;

	return fibonacci;
}

int main()
{
	long long n = 0;
	cin >> n;

	fibonacciMap[0] = 0;
	fibonacciMap[1] = 1;
	fibonacciMap[2] = 1;

	cout << findFibonacchi(n);
}
