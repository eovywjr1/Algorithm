#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <limits.h>

using namespace std;

vector<vector<bool>> PalindromeDP;

int TextLength = 0;

int main()
{
	string Text;
	cin >> Text;

	TextLength = Text.length();
	PalindromeDP = vector<vector<bool>>(TextLength, vector<bool>(TextLength, false));

	for (int i = 0; i < TextLength; ++i)
	{
		PalindromeDP[i][i] = true;

		if (i > 0 && Text[i] == Text[i - 1])
		{
			PalindromeDP[i - 1][i] = true;
		}

		for (int j = 0; j < i; ++j)
		{
			if (Text[i] == Text[j] && PalindromeDP[j + 1][i - 1])
			{
				PalindromeDP[j][i] = true;
			}
		}
	}

	vector<int> MinDivisionCountDP(TextLength, TextLength);
	MinDivisionCountDP[0] = 1;

	for (int i = 1; i < TextLength; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			if (PalindromeDP[j][i])
			{
				const int PalindromeDivisionCount = j > 0 ? MinDivisionCountDP[j - 1] + 1 : 1;
				MinDivisionCountDP[i] = min(MinDivisionCountDP[i], PalindromeDivisionCount);
			}
		}
	}

	cout << MinDivisionCountDP[TextLength - 1];
}
