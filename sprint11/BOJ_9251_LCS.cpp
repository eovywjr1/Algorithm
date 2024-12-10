#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string s1, s2;
	cin >> s1 >> s2;

	vector<vector<int>> LCSLengthDp(1001, vector<int>(1001, 0));
	const int s2Length = s2.length();
	const int s1Length = s1.length();

	for (int s2Index = 1; s2Index <= s2Length; ++s2Index)
	{
		for (int s1Index = 1; s1Index <= s1Length; ++s1Index)
		{
			if (s2[s2Index - 1] == s1[s1Index - 1])
			{
				LCSLengthDp[s2Index][s1Index] = LCSLengthDp[s2Index - 1][s1Index - 1] + 1;
			}
			else
			{
				LCSLengthDp[s2Index][s1Index] = max(LCSLengthDp[s2Index][s1Index - 1], LCSLengthDp[s2Index - 1][s1Index]);
			}
		}
	}

	cout << LCSLengthDp[s2Length][s1Length];
}
