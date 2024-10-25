#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	int grapeCupCount = 0;
	cin >> grapeCupCount;

	vector<int> grapeCups(grapeCupCount + 1, 0);
	vector<vector<int>> grapeSumVector(grapeCupCount + 1, vector<int>(3, 0));

	cin >> grapeCups[1];

	grapeSumVector[1][1] = grapeCups[1];

	for (int grapeCupIndex = 2; grapeCupIndex <= grapeCupCount; ++grapeCupIndex)
	{
		cin >> grapeCups[grapeCupIndex];

		grapeSumVector[grapeCupIndex][0] = max({ grapeSumVector[grapeCupIndex - 1][0], grapeSumVector[grapeCupIndex - 1][1], grapeSumVector[grapeCupIndex - 1][2] });
		grapeSumVector[grapeCupIndex][1] = grapeSumVector[grapeCupIndex - 1][0] + grapeCups[grapeCupIndex];
		grapeSumVector[grapeCupIndex][2] = grapeSumVector[grapeCupIndex - 1][1] + grapeCups[grapeCupIndex];
	}

	cout << max({ grapeSumVector[grapeCupCount][0], grapeSumVector[grapeCupCount][1], grapeSumVector[grapeCupCount][2] });
}
