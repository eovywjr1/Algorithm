#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	const int MaxNumber = 1000000;

	int N = 0;
	cin >> N;

	vector<int> Numbers(N);
	unordered_set<int> NumbersSet;
	
	for (int i = 0; i < N; ++i)
	{
		cin >> Numbers[i];

		const int Number = Numbers[i];
		NumbersSet.insert(Number);
	}

	unordered_map<int, int> Scores;

	for(const int Number : Numbers)
	{
		for (int Multiple = Number * 2; Multiple <= MaxNumber; Multiple += Number)
		{
			if (NumbersSet.find(Multiple) != NumbersSet.end())
			{
				++Scores[Number];
				--Scores[Multiple];
			}
		}
	}

	for (const int Number : Numbers)
	{
		cout << Scores[Number] << ' ';
	}
}
