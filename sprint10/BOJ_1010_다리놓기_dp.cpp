#include <iostream>
#include <array>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testCase = 0;
	cin >> testCase;

	constexpr int maxSiteCount = 30;
	array<array<int, maxSiteCount>, maxSiteCount> edgeCaseArray;

	for (int siteCount = 1; siteCount < maxSiteCount; ++siteCount)
	{
		edgeCaseArray[1][siteCount] = siteCount;
		edgeCaseArray[siteCount][1] = siteCount;
	}

	for (int leftSiteCount = 2; leftSiteCount < maxSiteCount; ++leftSiteCount)
	{
		for (int rightSiteCount = 2; rightSiteCount < maxSiteCount; ++rightSiteCount)
		{
			int edgeCaseSum = 0;
			
			for (int subRightSiteCount = leftSiteCount - 1; subRightSiteCount < rightSiteCount; ++subRightSiteCount)
			{
				edgeCaseSum += edgeCaseArray[leftSiteCount - 1][subRightSiteCount];
			}
			
			edgeCaseArray[leftSiteCount][rightSiteCount] = edgeCaseSum;
		}
	}

	for (int testCount = 0; testCount < testCase; ++testCount)
	{
		int leftSite = 0, rightSite = 0;
		cin >> leftSite >> rightSite;

		cout << edgeCaseArray[leftSite][rightSite] << '\n';
	}
}
