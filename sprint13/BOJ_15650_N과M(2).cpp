#include <iostream>
#include <vector>

using namespace std;

int N = 0, M = 0;
vector<int> combinations;

void printCombination(const int n, const int r)
{
	if (r >= M)
	{
		for (const int combination : combinations)
		{
			cout << combination << ' ';
		}

		cout << '\n';

		return;
	}

	for (int number = n; number <= N; ++number)
	{
		combinations[r] = number;

		printCombination(number + 1, r + 1);
	}
}

int main() 
{
	cin >> N >> M;
	combinations.resize(M);

	printCombination(1, 0);
}
