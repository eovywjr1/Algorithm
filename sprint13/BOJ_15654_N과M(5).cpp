#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 9

int N = 0, M = 0;
vector<int> combinations;
vector<int> nums;
bool visited[MAX] = { false };

void printCombinations(const int i, const int r)
{
	if (r >= M)
	{
		for (int& combination : combinations)
		{
			cout << combination << ' ';
		}

		cout << '\n';
		
		return;
	}

	for (int numIndex = 0; numIndex < N; ++numIndex)
	{
		if (visited[numIndex])
		{
			continue;
		}

		combinations[r] = nums[numIndex];
		visited[numIndex] = true;
		printCombinations((numIndex + 1) % N, r + 1);
		visited[numIndex] = false;
	}
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		int num = 0;
		cin >> num;

		nums.push_back(num);
	}

	combinations.resize(M);

	sort(nums.begin(), nums.end());

	printCombinations(0, 0);
}
