#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	int sequenceSize = 0;
	cin >> sequenceSize;

	vector<int> sequence(sequenceSize, 0);

	for (int& sequenceNumber : sequence)
	{
		cin >> sequenceNumber;
	}

	int maxIncreasePartSequenceSize = 1;
	vector<int> maxIncreasePartSequenceSizeVector(sequenceSize, 1);

	for (int sequenceIndex = 0; sequenceIndex < sequenceSize; ++sequenceIndex)
	{
		for (int partSequenceIndex = 0; partSequenceIndex < sequenceIndex; ++partSequenceIndex)
		{
			if (sequence[partSequenceIndex] < sequence[sequenceIndex])
			{
				maxIncreasePartSequenceSizeVector[sequenceIndex] = max(maxIncreasePartSequenceSizeVector[sequenceIndex], maxIncreasePartSequenceSizeVector[partSequenceIndex] + 1);
				maxIncreasePartSequenceSize = max(maxIncreasePartSequenceSize, maxIncreasePartSequenceSizeVector[sequenceIndex]);
			}
		}
	}

	cout << maxIncreasePartSequenceSize;
}
