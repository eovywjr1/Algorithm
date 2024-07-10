#include <iostream>
#include <cmath>
#include <limits.h>

using namespace std;

bool IsInteger(const double num) {
	if (num - static_cast<int>(num) == 0)
		return true;

	return false;
}

int check(const int n, const int remainNum, const int count) {
	const int subNum = pow(n, 2);

	if (count > 4 || subNum * (4 - count) < remainNum)
		return INT_MAX - 1;

	if (n == 1)
		return remainNum;

	if (remainNum <= 0)
		return 0;

	int tempCount = 1 + check(sqrt(remainNum - subNum), remainNum - subNum, count + 1);
	tempCount = min(tempCount, check(n - 1, remainNum, count));

	return tempCount;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	cout << check(sqrt(n), n, 0);
	
	return 0;
}
