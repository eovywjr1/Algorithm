#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace	std;

#define MAX 9

int N = 0, M = 0;
vector<int> tempCombinations;
vector<int> nums;
array<bool, MAX> visited{ false };

void printCombination(int index, int r)
{
	if (r >= M)
	{
		for (const int combination : tempCombinations)
		{
			cout << combination << ' ';
		}

		cout << '\n';

		return;
	}

	int previousNumber = 0;

	for (int numsIndex = 0; numsIndex < N; ++numsIndex)
	{
		if (visited[numsIndex] || previousNumber == nums[numsIndex])
		{
			continue;
		}

		previousNumber = nums[numsIndex];
		tempCombinations[r] = nums[numsIndex];
		visited[numsIndex] = true;
		printCombination((numsIndex + 1) % N, r + 1);
		visited[numsIndex] = false;
	}
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		int num = 0;
		cin >> num;

		nums.push_back(num);
	}

	tempCombinations.resize(M);
	sort(nums.begin(), nums.end());

	printCombination(0, 0);
}
