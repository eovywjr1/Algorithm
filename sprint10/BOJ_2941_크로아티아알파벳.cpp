#include <iostream>
#include <string>
#include <array>

using namespace std;

bool CheckCroatiaAlphabetAndGetCroatiaAlphabetLength(const string& str, const size_t startIndex, size_t& croatiaAlphabetLength)
{
	constexpr int croatiaAlphabetSize = 8;
	const array<string, croatiaAlphabetSize> croatiaAlphabetArray = { "c=", "c-","dz=","d-","lj","nj","s=","z=" };
	
	for (size_t croatiaAlphabetIndex = 0; croatiaAlphabetIndex < croatiaAlphabetSize; ++croatiaAlphabetIndex)
	{
		const size_t checkcroatiaAlphabetLength = croatiaAlphabetArray[croatiaAlphabetIndex].length();

		if (str.length() - startIndex < checkcroatiaAlphabetLength)
			continue;

		bool isCroatiaAlphabet = true;
		
		for (size_t strIndex = 0; strIndex < checkcroatiaAlphabetLength; ++strIndex)
		{
			if (str[startIndex + strIndex] != croatiaAlphabetArray[croatiaAlphabetIndex][strIndex])
			{
				isCroatiaAlphabet = false;
				break;
			}
		}

		if (isCroatiaAlphabet)
		{
			croatiaAlphabetLength = checkcroatiaAlphabetLength;

			return true;
		}
	}

	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	cin >> str;

	const size_t strLength = str.length();
	int croatiaAlphabetCount = 0;

	for (size_t strIndex = 0; strIndex < strLength; ++strIndex)
	{
		size_t croatiaAlphabetLength = -1;

		if (CheckCroatiaAlphabetAndGetCroatiaAlphabetLength(str, strIndex, croatiaAlphabetLength))
		{
			strIndex += croatiaAlphabetLength - 1; // for문에 의해 증가되므로 마지막 글자까지만 이동
			++croatiaAlphabetCount;
		}
		else if (str[strIndex] >= 'a' && str[strIndex] <= 'z')
		{
			++croatiaAlphabetCount;
		}

	}

	cout << croatiaAlphabetCount;
}
