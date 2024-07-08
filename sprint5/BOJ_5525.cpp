#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	string str;
	cin >> str;

	int answer = 0;

	for (int index = 0; index < M; ++index) {
		if (str[index] != 'I')
			continue;

		int ioiCount = 0;

		while (str[index + 1] == 'O' && str[index + 2] == 'I') {
			++ioiCount;

			if (ioiCount == N) {
				++answer;
				--ioiCount;
			}

			index += 2;
		}
	}

	cout << answer;
}
