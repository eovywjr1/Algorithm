#include <iostream>
#include <vector>

using namespace std;

vector<int> parentVector(51);

int findParent(const int number)
{
	if (parentVector[number] == number)
		return number;

	return parentVector[number] = findParent(parentVector[number]);
}

void unionParent(const int num1, const int num2)
{
	const int parentNumber1 = findParent(num1);
	const int parentNumber2 = findParent(num2);

	if (parentNumber1 == parentNumber2)
		return;

	if(parentNumber1 < parentNumber2)
		parentVector[parentNumber2] = parentNumber1;
	else
		parentVector[parentNumber1] = parentNumber2;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int index = 1; index <= 50; ++index)
	{
		parentVector[index] = index;
	}

	int N = 0, M = 0;
	cin >> N >> M;

	int trueManCount = 0;
	cin >> trueManCount;

	vector<vector<int>> partyVector(51, vector<int>(51, 0));

	for (int index = 0; index < trueManCount; ++index)
	{
		int trueManNumber;
		cin >> trueManNumber;

		parentVector[trueManNumber] = 0;
	}

	for (int index = 0; index < M; ++index)
	{
		int partyManCount = 0;
		cin >> partyManCount;

		cin >> partyVector[index][0];

		for (int partyManIndex = 1; partyManIndex < partyManCount; ++partyManIndex)
		{
			cin >> partyVector[index][partyManIndex];

			unionParent(partyVector[index][0], partyVector[index][partyManIndex]);
		}
	}

	int answer = M;

	for (int index = 0; index < M; ++index)
	{
		bool isExistTrueMan = false;
		for (const int partyNumber : partyVector[index])
		{
			if (partyNumber == 0)
				break;

			if (findParent(partyNumber) == 0)
			{
				--answer;
				break;
			}
		}
	}

	cout << answer;
}
