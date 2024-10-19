#include <iostream>
#include <cmath>

using namespace std;

long long combination(const int elementCount, const int selectCount)
{
	long long result = 1;

	for (int element = elementCount, select = 1; select <= selectCount; --element, ++select)
	{
		result *= element;
		result /= select;
	}

	return result;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testCase = 0;
	cin >> testCase;

	for (int testCount = 0; testCount < testCase; ++testCount)
	{
		int leftSite = 0, rightSite = 0;
		cin >> leftSite >> rightSite;

		cout << combination(max(leftSite, rightSite), min(leftSite, rightSite)) << '\n';
	}
}
