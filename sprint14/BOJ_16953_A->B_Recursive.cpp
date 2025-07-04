#include <iostream>
#include <cmath>
#include <limits.h>

using namespace std;

int A = 0;
int B = 0;
int MinOperatorCount = INT_MAX;

void FindAToBOperator(const long long Number, const int Count)
{
	if (Number > B)
	{
		return;
	}

	if (Number == B)
	{
		MinOperatorCount = min(MinOperatorCount, Count);
		return;
	}

	FindAToBOperator(Number * 2, Count + 1);
	FindAToBOperator(Number * 10 + 1, Count + 1);
}

int main()
{
	cin >> A >> B;

	FindAToBOperator(A, 0);

	MinOperatorCount != INT_MAX ? cout << MinOperatorCount + 1 : cout << -1;
}
