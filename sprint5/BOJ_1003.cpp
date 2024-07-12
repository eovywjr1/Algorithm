#include "iostream"
#include "vector"

using namespace std;

vector<pair<int, int>> FibonacciCountVector(40, { 0,0 });

void fibonacci(int n) {
	if (FibonacciCountVector[n].first != 0 || FibonacciCountVector[n].second != 0)
		return;

	if (FibonacciCountVector[n - 1].first == 0 && FibonacciCountVector[n - 1].second == 0)
		fibonacci(n - 1);

	FibonacciCountVector[n].first += FibonacciCountVector[n - 1].first;
	FibonacciCountVector[n].second += FibonacciCountVector[n - 1].second;
	
	FibonacciCountVector[n].first += FibonacciCountVector[n - 2].first;
	FibonacciCountVector[n].second += FibonacciCountVector[n - 2].second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	FibonacciCountVector[0].first = 1;
	FibonacciCountVector[1].second = 1;

	for (int Index = 0; Index < T; ++Index) {
		int N;
		cin >> N;

		fibonacci(N);

		cout << FibonacciCountVector[N].first << ' ' << FibonacciCountVector[N].second;
		cout << '\n';
	}
}
