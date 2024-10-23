#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int findFibonacciNumber = 0;
	cin >> findFibonacciNumber;

	vector<long long> fibonacciVector(findFibonacciNumber + 1, 0);
	fibonacciVector[1] = 1;

	for (int fibonacciNumber = 2; fibonacciNumber <= findFibonacciNumber; ++fibonacciNumber)
	{
		fibonacciVector[fibonacciNumber] = fibonacciVector[fibonacciNumber - 2] + fibonacciVector[fibonacciNumber - 1];
	}

	cout << fibonacciVector[findFibonacciNumber];
}
