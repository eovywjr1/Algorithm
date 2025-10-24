#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0, S = 0;
	cin >> N >> S;

	vector<int> Sequence(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> Sequence[i];
	}

	int MinLength = N + 1;
	int LeftIndex = 0, RightIndex = 0;
	int Sum = Sequence[0];

	while (LeftIndex <= RightIndex && RightIndex < N)
	{
		if (S <= Sum)
		{
			MinLength = min(MinLength, RightIndex - LeftIndex + 1);
			Sum -= Sequence[LeftIndex];
			++LeftIndex;
		}
		else
		{
			++RightIndex;
			Sum += Sequence[RightIndex];
		}
	}
	
	if (MinLength == N + 1)
	{
		cout << 0;
	}
	else
	{
		cout << MinLength;
	}
}
