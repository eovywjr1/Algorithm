#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

int N = 0;

int Solution(const vector<int>& fruits)
{
	int maxFruitCount = 0;
	int fruitTypeCount = 0;
	int rightIndex = 0;
	unordered_map<int, int> fruitsMap;

	for (int leftIndex = 0; leftIndex < N; ++leftIndex)
	{
		for (; rightIndex < N; ++rightIndex)
		{
			const int currentFruitNumber = fruits[rightIndex];
			if (fruitsMap[currentFruitNumber] == 0)
				++fruitTypeCount;

			if (fruitTypeCount > 2)
			{
				--fruitTypeCount;
				break;
			}

			++fruitsMap[currentFruitNumber];
		}

		// RightIndex For문이 끝날 때 개수에 포함이 안되는 다음 RightIndex가 되므로 +1을 하지 않음
		maxFruitCount = max(maxFruitCount, rightIndex - leftIndex);

		--fruitsMap[fruits[leftIndex]];
		if (fruitsMap[fruits[leftIndex]] == 0)
			--fruitTypeCount;
	}

	return maxFruitCount;
}

int main()
{
	cin >> N;

	vector<int> fruits(N,0);
	for (int index = 0; index < N; ++index)
	{
		cin >> fruits[index];
	}

	cout << Solution(fruits);
}
