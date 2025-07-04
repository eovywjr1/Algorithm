#include <iostream>

using namespace std;

int main()
{
	int A = 0;
	int B = 0;
	
	cin >> A >> B;

	int MinOperatorCount = 0;

	while (A < B)
	{
		if (B % 2 == 0)
		{
			B /= 2;
		}
		else if (B % 10 == 1)
		{
			B /= 10;
		}
		else
		{
			break;
		}

		++MinOperatorCount;
	}

	A == B ? cout << MinOperatorCount + 1 : cout << -1;
}
