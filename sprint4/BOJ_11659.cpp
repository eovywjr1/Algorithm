#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<int> prefixSumVector(N + 1, 0);

	for (int index = 1; index <= N; ++index) {
		int num;

		cin >> num;

		prefixSumVector[index] = prefixSumVector[index - 1] + num;
	}

	for (int index = 0; index < M; ++index) {
		int i, j;

		cin >> i >> j;
		cout << prefixSumVector[j] - prefixSumVector[i - 1] << "\n";
	}
}