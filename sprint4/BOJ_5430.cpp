#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int index = 0; index < T; ++index) {
		string functionStr;
		cin >> functionStr;

		int n;
		cin >> n;

		string numStr;
		cin >> numStr;

		const int numStrLength = numStr.length();
		vector<int> numVector;
		int num = 0;
		for (int i = 1; i < numStrLength; ++i) {
			if (numStr[i] < '0' || numStr[i] > '9') {
				if (num != 0)
					numVector.push_back(num);

				num = 0;
				continue;
			}

			num = num * 10 + (numStr[i] - '0');
		}

		const int functionStrLength = functionStr.length();
		int reverseCount = 0;
		int startIndex = 0;
		int endIndex = numVector.size() - 1;
		bool isGotoNextCase = false;

		for (int i = 0; i < functionStrLength; ++i) {
			if (functionStr[i] == 'R') {
				++reverseCount;
			}
			else if (functionStr[i] == 'D') {
				if (endIndex < startIndex) {
					cout << "error" << '\n';
					isGotoNextCase = true;
					break;
				}

				if (reverseCount % 2 == 0)
					++startIndex;
				else
					--endIndex;
			}
		}

		if (isGotoNextCase)
			continue;

		cout << '[';
		if (numVector.empty() == false) {
			if (reverseCount % 2 == 0) {
				for(int i=startIndex;i<endIndex;++i)
					cout << numVector[i] << ',';

				cout << numVector[endIndex];
			}
			else {
				for (int i = endIndex; i > 0; --i)
					cout << numVector[i] << ',';

				cout << numVector[0];
			}
		}
		cout << ']';
		cout << '\n';
	}
}