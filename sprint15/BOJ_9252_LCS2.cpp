#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	const int MaxLength = 1000;

	string str1, str2;
	cin >> str1 >> str2;

	const int Length1 = str1.length();
	const int Length2 = str2.length();

	vector<vector<int>> DP(MaxLength + 1, vector<int>(MaxLength + 1, 0));

	for (int i = 1; i <= Length1; ++i)
	{
		for (int j = 1; j <= Length2; ++j)
		{
			DP[i][j] = (str1[i - 1] == str2[j - 1]) ? DP[i - 1][j - 1] + 1 : max(DP[i - 1][j], DP[i][j - 1]);
		}
	}

	cout << DP[Length1][Length2] << '\n';

	if (DP[Length1][Length2] > 0)
	{
		int i = Length1, j = Length2;
		string Answer;

		while (i > 0 && j > 0)
		{
			if (DP[i][j] == DP[i-1][j])
			{
				--i;
			}
			else if (DP[i][j] == DP[i][j - 1])
			{
				--j;
			}
			else
			{
				Answer.push_back(str1[i - 1]);
				--i;
				--j;
			}
		}

		for (int i = Answer.length() - 1; i >= 0; --i)
		{
			cout << Answer[i];
		}
	}	
}
