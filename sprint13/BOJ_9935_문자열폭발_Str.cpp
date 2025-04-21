#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string Str;
	cin >> Str;

	string BombStr;
	cin >> BombStr;

	const int BombStrLength = static_cast<int>(BombStr.length());

	string TempStr;

	for (char Text : Str)
	{
		TempStr.push_back(Text);

		while (BombStrLength <= TempStr.length())
		{
			const string TempStrSubstr = TempStr.substr(TempStr.length() - BombStrLength, BombStrLength);
			
			if (TempStrSubstr == BombStr)
			{
				TempStr.erase(TempStr.end() - BombStrLength, TempStr.end());
			}
			else
			{
				break;
			}
		}
	}

	if (TempStr.empty())
	{
		cout << "FRULA";
	}
	else
	{
		cout << TempStr;
	}
}
