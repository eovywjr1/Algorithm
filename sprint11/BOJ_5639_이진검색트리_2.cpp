#include <iostream>
#include <vector>

using namespace std;

int nodeCount = 0;
vector<int> preTraversialNode(10000, 0);

void postTraverisal(const int startIndex, const int endIndex)
{
	if (startIndex >= endIndex)
	{
		return;
	}

	int nextRightNodeIndex = startIndex + 1;
	while (nextRightNodeIndex < endIndex && preTraversialNode[nextRightNodeIndex] < preTraversialNode[startIndex])
	{
		++nextRightNodeIndex;
	}

	postTraverisal(startIndex + 1, nextRightNodeIndex);
	postTraverisal(nextRightNodeIndex, endIndex);

	cout << preTraversialNode[startIndex] << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int num = 0;
	while (cin >> num)
	{
		preTraversialNode[nodeCount] = num;
		++nodeCount;
	}

	postTraverisal(0, nodeCount);
}
